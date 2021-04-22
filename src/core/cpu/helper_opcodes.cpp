#include "cpu.h"

/**
 * Loads
 */
void CPU::ld(HybridRegister& reg) { reg.set(getNextWord()); }

void CPU::ld(HybridRegister& addr, ByteRegister& reg) {
    mmu.write(addr.get(), reg.value);
}

void CPU::ld(ByteRegister& reg) { reg.value = getNextByte(); }

void CPU::ld(WordRegister& reg) {
    uint16_t address = getNextWord();
    mmu.write(address, static_cast<uint8_t>(reg.value & 0xFF));
    mmu.write(address + 1, static_cast<uint8_t>((reg.value & 0xFF00) >> 8));
}

void CPU::ld(ByteRegister& reg, uint16_t address) {
    reg.value = mmu.read(address);
}

void CPU::ld(ByteRegister& reg, HybridRegister& word_reg) {
    ld(reg, word_reg.get());
}

void CPU::ldi(HybridRegister& reg, ByteRegister& byte_reg) {
    ld(reg, byte_reg);
    reg.inc();
}

void CPU::ldi(ByteRegister& byte_reg, HybridRegister& reg) {
    ld(byte_reg, reg);
    reg.inc();
}

void CPU::ldd(HybridRegister& reg, ByteRegister& byte_reg) {
    ld(reg, byte_reg);
    reg.dec();
}

void CPU::ldd(ByteRegister& byte_reg, HybridRegister& reg) {
    ld(byte_reg, reg);
    reg.dec();
}

/**
 * Arithmetic
 */
void CPU::inc(HybridRegister& reg) { reg.inc(); }

void CPU::inc(ByteRegister& reg) {
    reg.inc();
    f.setZero(reg.value == 0);
    f.setSubtract(false);
    f.setHalfCarry(reg.value & 0x0F == 0x00);
}

void CPU::inc(WordRegister& reg) { reg.inc(); }

void CPU::inc(uint16_t address) {
    uint8_t result = mmu.read(address) + 1;
    mmu.write(address, result);
    f.setZero(result == 0);
    f.setHalfCarry(result & 0xF == 0x00);
    f.setSubtract(false);
}

void CPU::dec(ByteRegister& reg) {
    reg.dec();
    f.setZero(reg.value == 0);
    f.setSubtract(true);
    f.setHalfCarry(reg.value & 0x0F == 0x0F);
}

void CPU::dec(HybridRegister& reg) { reg.dec(); }

void CPU::dec(WordRegister& reg) { reg.dec(); }

void CPU::dec(uint16_t address) {
    uint8_t result = mmu.read(address) + 1;
    mmu.write(address, result);
    f.setZero(result == 0);
    f.setHalfCarry(result & 0xF == 0xF);
    f.setSubtract(true);
}

void CPU::add(HybridRegister& reg, uint16_t value) {
    uint16_t reg_value = reg.get();
    uint result = reg_value + value;
    f.setHalfCarry((reg_value & 0xFFF) + (value & 0xFFF) > 0xFFF);
    f.setCarry((result & 0x10000) != 0);
    f.setSubtract(false);
    reg.set(static_cast<uint16_t>(result));
}

void CPU::add(HybridRegister& reg, HybridRegister& reg2) {
    add(reg, reg2.get());
}

void CPU::add(HybridRegister& reg, WordRegister& reg2) { add(reg, reg2.value); }

void CPU::daa() {
    uint8_t upper = (a.value & 0xF0) >> 4;
    uint8_t lower = (a.value & 0xF);
    a.value = lower + (upper * 10);
    f.setZero(a.value == 0);
    f.setHalfCarry(false);
    // TODO: Figure out what a carry entails
}

void CPU::cpl() {
    f.setSubtract(true);
    f.setHalfCarry(true);
    a.value = ~a.value;
}

/**
 * Rotations
 */
void CPU::rlca() {
    f.setSubtract(false);
    f.setHalfCarry(false);
    f.setZero(false);
    uint8_t bit = (a.value & 0x80) >> 7;
    a.value = (a.value << 1) | bit;
    f.setCarry(bit);
}

void CPU::rrca() {
    uint8_t bit = (a.value & 0x1);
    f.setCarry(bit);
    f.setHalfCarry(false);
    f.setZero(false);
    f.setSubtract(false);
    a.value = (a.value >> 1) | (bit << 7);
}

void CPU::rla() {
    f.setHalfCarry(false);
    f.setSubtract(false);
    f.setZero(false);
    uint8_t bit = f.getCarry();
    f.setCarry(a.value & 0x80);
    a.value = (a.value << 1) | bit;
}

void CPU::rra() {
    f.setHalfCarry(false);
    f.setSubtract(false);
    f.setZero(false);
    uint8_t bit = f.getCarry();
    f.setCarry(a.value & 0x1);
    a.value = (a.value >> 1) | (bit << 7);
}

/**
 * Jumps
 */
void CPU::jr() { pc.value += (int8_t)getNextByte(); }

void CPU::jr_cond(bool condition) {
    if (condition) jr();
}

/**
 * Misc
 */
void CPU::stop() {
    // TODO: Change this to something else later.
    exit(1);
}

void CPU::scf() {
    f.setSubtract(false);
    f.setHalfCarry(false);
    f.setCarry(true);
}