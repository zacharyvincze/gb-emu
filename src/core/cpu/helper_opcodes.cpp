#include "cpu.h"

/**
 * Loads
 */
void CPU::ld(WordRegister& reg) { reg.set(getNextWord()); }

void CPU::ld(WordRegister& addr, ByteRegister& reg) {
    mmu.write(addr.value(), reg.value());
}

void CPU::ld(ByteRegister& reg) { reg.set(getNextByte()); }

void CPU::ld_sp(WordRegister& reg) {
    uint16_t address = getNextWord();
    mmu.write(address, static_cast<uint8_t>(reg.value() & 0xFF));
    mmu.write(address + 1, static_cast<uint8_t>((reg.value() & 0xFF00) >> 8));
}

void CPU::ld(WordRegister& reg, WordRegister& reg2) { reg.set(reg2.value()); }

void CPU::ld(ByteRegister& reg, uint16_t address) {
    reg.set(mmu.read(address));
}

void CPU::ld(uint16_t address, ByteRegister& reg) {
    mmu.write(address, reg.value());
}

void CPU::ld(ByteRegister& reg, ByteRegister& reg2) { ld(reg, reg2.value()); }

void CPU::ld(ByteRegister& reg, WordRegister& word_reg) {
    ld(reg, word_reg.value());
}

void CPU::ld_hl_sp() {
    uint16_t orig_val = sp.value();
    add_signed(sp);
    hl.set(sp.value());
    sp.set(orig_val);
}

void CPU::ldi(WordRegister& reg, ByteRegister& byte_reg) {
    ld(reg, byte_reg);
    reg.inc();
}

void CPU::ldi(ByteRegister& byte_reg, WordRegister& reg) {
    ld(byte_reg, reg);
    reg.inc();
}

void CPU::ldd(WordRegister& reg, ByteRegister& byte_reg) {
    ld(reg, byte_reg);
    reg.dec();
}

void CPU::ldd(ByteRegister& byte_reg, WordRegister& reg) {
    ld(byte_reg, reg);
    reg.dec();
}

void CPU::pop(WordRegister& reg) {
    uint8_t lower = mmu.read(sp.value());
    sp.inc();
    uint8_t upper = mmu.read(sp.value());
    sp.inc();
    reg.set((upper << 8) | lower);
}

void CPU::push(WordRegister& reg) {
    uint16_t reg_value = reg.value();
    sp.dec();
    mmu.write(sp.value(), (reg_value >> 8) & 0xFF);
    sp.dec();
    mmu.write(sp.value(), reg_value & 0xFF);
}

/**
 * Arithmetic
 */
void CPU::inc(WordRegister& reg) { reg.inc(); }

void CPU::inc(ByteRegister& reg) {
    reg.inc();
    f.setZero(reg.value() == 0);
    f.setSubtract(false);
    f.setHalfCarry(reg.value() & 0x0F == 0x00);
}

void CPU::inc(uint16_t address) {
    uint8_t result = mmu.read(address) + 1;
    mmu.write(address, result);
    f.setZero(result == 0);
    f.setHalfCarry(result & 0xF == 0x00);
    f.setSubtract(false);
}

void CPU::dec(ByteRegister& reg) {
    reg.dec();
    f.setZero(reg.value() == 0);
    f.setSubtract(true);
    f.setHalfCarry(reg.value() & 0x0F == 0x0F);
}

void CPU::dec(WordRegister& reg) { reg.dec(); }

void CPU::dec(uint16_t address) {
    uint8_t result = mmu.read(address) + 1;
    mmu.write(address, result);
    f.setZero(result == 0);
    f.setHalfCarry(result & 0xF == 0xF);
    f.setSubtract(true);
}

void CPU::add(WordRegister& reg, uint16_t value) {
    uint16_t reg_value = reg.value();
    uint result = reg_value + value;
    f.setHalfCarry((reg_value & 0xFFF) + (value & 0xFFF) > 0xFFF);
    f.setCarry((result & 0x10000) != 0);
    f.setSubtract(false);
    reg.set(static_cast<uint16_t>(result));
}

void CPU::add(WordRegister& reg, WordRegister& reg2) { add(reg, reg2.value()); }

void CPU::add(ByteRegister& reg, uint8_t value) {
    uint8_t reg_value = reg.value();
    uint result = reg_value + value;
    f.setSubtract(false);
    f.setHalfCarry((reg_value & 0xF) + (value & 0xF) > 0xF);
    f.setCarry(result > 0xFF);
    reg.set(static_cast<uint8_t>(result));
}

void CPU::add(ByteRegister& reg, ByteRegister& reg2) { add(reg, reg2.value()); }

void CPU::add(ByteRegister& reg, WordRegister& addr) {
    add(reg, mmu.read(addr.value()));
}

void CPU::add(ByteRegister& reg) { add(reg, getNextByte()); }

void CPU::add_signed(WordRegister& reg) {
    uint16_t reg_value = reg.value();
    int8_t value = (int8_t)getNextByte();
    int result = static_cast<int>(reg_value + value);
    f.setZero(false);
    f.setSubtract(false);
    f.setHalfCarry(((reg_value ^ value ^ (result & 0xFFFF)) & 0x10) == 0x10);
    f.setCarry(((reg_value ^ value ^ (result & 0xFFFF)) & 0x100) == 0x100);
    reg.set(static_cast<uint16_t>(result));
}

void CPU::adc(ByteRegister& reg, uint8_t value) {
    uint8_t reg_value = reg.value();
    uint8_t carry_value = f.getCarry();
    uint result = reg_value + carry_value + value;
    f.setSubtract(false);
    f.setHalfCarry(((reg_value & 0xF) + (value & 0xF) + carry_value) > 0xF);
    f.setCarry(result > 0xFF);
    a.set(static_cast<uint8_t>(result));
}

void CPU::adc(ByteRegister& reg, ByteRegister& reg2) { adc(reg, reg2.value()); }

void CPU::adc(ByteRegister& reg, WordRegister& addr) { adc(reg, addr.value()); }

void CPU::adc(ByteRegister& reg) { adc(reg, getNextByte()); }

void CPU::sub(ByteRegister& reg, uint8_t value) {
    uint8_t result = reg.value() - value;
    f.setZero(result == 0);
    f.setSubtract(true);
    f.setCarry(value > reg.value());
    f.setHalfCarry((reg.value() & 0xF) - (value & 0xF) < 0);

    reg.set(static_cast<uint8_t>(result));
}

void CPU::sub(ByteRegister& reg, ByteRegister& reg2) { sub(reg, reg2.value()); }

void CPU::sub(ByteRegister& reg, WordRegister& addr) {
    sub(reg, mmu.read(addr.value()));
}

void CPU::sub(ByteRegister& reg) { sub(reg, getNextByte()); }

void CPU::sbc(ByteRegister& reg, uint8_t value) {
    uint8_t carry_value = f.getCarry();
    uint8_t result = reg.value() - value - carry_value;
    f.setZero(result == 0);
    f.setSubtract(true);
    f.setCarry((value + carry_value) > reg.value());
    f.setHalfCarry(((reg.value() & 0xF) - (value & 0xF) - carry_value) < 0);

    reg.set(static_cast<uint8_t>(result));
}

void CPU::sbc(ByteRegister& reg, ByteRegister& reg2) { sbc(reg, reg2.value()); }

void CPU::sbc(ByteRegister& reg, WordRegister& addr) {
    sbc(reg, mmu.read(addr.value()));
}

void CPU::sbc(ByteRegister& reg) { sbc(reg, getNextByte()); }

void CPU::op_and(ByteRegister& reg, uint8_t value) {
    reg.set(reg.value() & value);
    f.setZero(reg.value() == 0);
    f.setSubtract(false);
    f.setHalfCarry(true);
    f.setCarry(false);
}

void CPU::op_and(ByteRegister& reg, ByteRegister& reg2) {
    op_and(reg, reg2.value());
}

void CPU::op_and(ByteRegister& reg, WordRegister& addr) {
    op_and(reg, mmu.read(addr.value()));
}

void CPU::op_and(ByteRegister& reg) { op_and(reg, getNextByte()); }

void CPU::op_xor(ByteRegister& reg, uint8_t value) {
    reg.set(reg.value() ^ value);
    f.setZero(reg.value() == 0);
    f.setSubtract(false);
    f.setHalfCarry(false);
    f.setCarry(false);
}

void CPU::op_xor(ByteRegister& reg, ByteRegister& reg2) {
    op_xor(reg, reg2.value());
}

void CPU::op_xor(ByteRegister& reg, WordRegister& addr) {
    op_xor(reg, mmu.read(addr.value()));
}

void CPU::op_xor(ByteRegister& reg) { op_xor(reg, getNextByte()); }

void CPU::op_or(ByteRegister& reg, uint8_t value) {
    reg.set(reg.value() | value);
    f.setZero(reg.value() == 0);
    f.setSubtract(false);
    f.setHalfCarry(false);
    f.setCarry(false);
}

void CPU::op_or(ByteRegister& reg, ByteRegister& reg2) {
    op_or(reg, reg2.value());
}

void CPU::op_or(ByteRegister& reg, WordRegister& addr) {
    op_or(reg, mmu.read(addr.value()));
}

void CPU::op_or(ByteRegister& reg) { op_or(reg, getNextByte()); }

void CPU::cp(ByteRegister& reg, uint8_t value) {
    uint result = reg.value() - value;
    f.setCarry(value > reg.value());
    f.setHalfCarry(((reg.value() & 0xF) - (value & 0xF)) < 0);
    f.setZero(result == 0);
    f.setSubtract(true);
}

void CPU::cp(ByteRegister& reg, ByteRegister& reg2) { cp(reg, reg2.value()); }

void CPU::cp(ByteRegister& reg, WordRegister& addr) {
    cp(reg, mmu.read(addr.value()));
}

void CPU::daa() {
    uint8_t upper = (a.value() & 0xF0) >> 4;
    uint8_t lower = (a.value() & 0xF);
    a.set(lower + (upper * 10));
    f.setZero(a.value() == 0);
    f.setHalfCarry(false);
    // TODO: Figure out what a carry entails
}

void CPU::cpl() {
    f.setSubtract(true);
    f.setHalfCarry(true);
    a.set(~a.value());
}

void CPU::ccf() {
    f.setCarry(!f.getCarry());
    f.setHalfCarry(false);
    f.setSubtract(false);
}

/**
 * Rotations
 */
uint8_t CPU::rlc(uint8_t value) {
    f.setSubtract(false);
    f.setHalfCarry(false);
    uint8_t bit = (value & 0x80) >> 7;
    f.setCarry(bit);
    value = ((value << 1) | bit);
    f.setZero(value == 0);
    return value;
}

void CPU::rlc(ByteRegister& reg) { reg.set(rlc(reg.value())); }

void CPU::rlc(WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, rlc(mmu.read(value)));
}

void CPU::rlca() {
    rlc(a);
    f.setZero(false);
}

uint8_t CPU::rrc(uint8_t value) {
    uint8_t bit = (value & 0x1);
    f.setCarry(bit);
    f.setHalfCarry(false);
    f.setSubtract(false);
    value = ((value >> 1) | (bit << 7));
    f.setZero(value == 0);
    return value;
}

void CPU::rrc(ByteRegister& reg) { reg.set(rrc(reg.value())); }

void CPU::rrc(WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, rrc(mmu.read(value)));
}

void CPU::rrca() {
    rrc(a);
    f.setZero(false);
}

uint8_t CPU::rl(uint8_t value) {
    f.setHalfCarry(false);
    f.setSubtract(false);
    uint8_t bit = f.getCarry();
    f.setCarry(value & 0x80);
    value = ((value << 1) | bit);
    f.setZero(value == 0);
    return value;
}

void CPU::rl(ByteRegister& reg) { reg.set(rl(reg.value())); }

void CPU::rl(WordRegister& reg) {
    uint16_t value;
    mmu.write(value, rl(mmu.read(value)));
}

void CPU::rla() {
    rl(a);
    f.setZero(false);
}

uint8_t CPU::rr(uint8_t value) {
    f.setHalfCarry(false);
    f.setSubtract(false);
    uint8_t bit = f.getCarry();
    f.setCarry(value & 0x1);
    value = ((value >> 1) | (bit << 7));
    f.setZero(value == 0);
    return value;
}

void CPU::rr(ByteRegister& reg) { reg.set(rr(reg.value())); }

void CPU::rr(WordRegister& reg) {
    uint16_t value;
    mmu.write(value, rr(mmu.read(value)));
}

void CPU::rra() {
    rr(a);
    f.setZero(false);
}

uint8_t CPU::sla(uint8_t value) {
    f.setCarry(value & 0x80);
    value = value << 1;
    f.setZero(value == 0);
    f.setSubtract(false);
    f.setHalfCarry(false);
    return value;
}
void CPU::sla(ByteRegister& reg) { reg.set(sla(reg.value())); }
void CPU::sla(WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, sla(mmu.read(value)));
}

uint8_t CPU::sra(uint8_t value) {
    f.setCarry(value & 0x1);
    uint8_t bit = value & 0x80;
    value = (value >> 1) | bit;
    f.setZero(value == 0);
    f.setHalfCarry(false);
    f.setSubtract(false);
    return value;
}
void CPU::sra(ByteRegister& reg) { reg.set(sra(reg.value())); }
void CPU::sra(WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, sra(mmu.read(value)));
}

uint8_t CPU::srl(uint8_t value) {
    f.setCarry(value & 0x1);
    value = value >> 1;
    f.setZero(value == 0);
    f.setHalfCarry(false);
    f.setSubtract(false);
    return value;
}
void CPU::srl(ByteRegister& reg) { reg.set(srl(reg.value())); }
void CPU::srl(WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, srl(mmu.read(value)));
}

/**
 * Bitwise
 */
uint8_t CPU::swap(uint8_t value) {
    f.setCarry(false);
    f.setHalfCarry(false);
    f.setSubtract(false);
    uint8_t result = ((value & 0xF0) >> 4) | ((value & 0x0F) << 4);
    f.setZero(result == 0);
    return result;
}
void CPU::swap(ByteRegister& reg) { reg.set(swap(reg.value())); }
void CPU::swap(WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, swap(mmu.read(value)));
}

uint8_t CPU::bit(uint8_t n, uint8_t value) {
    f.setHalfCarry(true);
    f.setSubtract(false);
    uint8_t result = value ^ (1UL << n);
    f.setZero(result == 0);
    return result;
}
void CPU::bit(uint8_t n, ByteRegister& reg) { reg.set(bit(n, reg.value())); }
void CPU::bit(uint8_t n, WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, bit(n, mmu.read(value)));
}

uint8_t CPU::res(uint8_t n, uint8_t value) { return value & ~(1UL << n); }
void CPU::res(uint8_t n, ByteRegister& reg) { reg.set(res(n, reg.value())); }
void CPU::res(uint8_t n, WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, res(n, mmu.read(value)));
}

uint8_t CPU::set(uint8_t n, uint8_t value) { return value | (1UL << n); }
void CPU::set(uint8_t n, ByteRegister& reg) { reg.set(set(n, reg.value())); }
void CPU::set(uint8_t n, WordRegister& reg) {
    uint16_t value = reg.value();
    mmu.write(value, set(n, mmu.read(value)));
}

/**
 * Jumps and Branches
 */
void CPU::jr() { pc.set(pc.value() + (int8_t)getNextByte()); }

void CPU::jr_cond(bool condition) {
    if (condition) {
        jr();
        timer.increment_m(1);
    }
}

void CPU::jp() { pc.set(getNextWord()); }

void CPU::jp(bool condition) {
    if (condition) {
        jp();
        timer.increment_m(1);
    }
}

void CPU::jp(WordRegister& reg) { pc.set(hl.value()); }

void CPU::ret() {
    uint8_t lower = mmu.read(sp.value());
    sp.inc();
    uint8_t upper = mmu.read(sp.value());
    sp.inc();
    pc.set((uint16_t)((upper << 8) | (lower)));
}

void CPU::ret(bool condition) {
    if (condition) {
        ret();
        timer.increment_m(3);
    }
}

void CPU::reti() {
    ret();
    ei();
}

void CPU::call() {
    sp.dec();
    mmu.write(sp.value(), (pc.value() >> 8) & 0xFF);
    sp.dec();
    mmu.write(sp.value(), pc.value() & 0xFF);
    pc.set(getNextWord());
}

void CPU::call(bool condition) {
    if (condition) {
        call();
        timer.increment_m(3);
    }
}

/**
 * Restarts
 */
void CPU::rst(uint8_t f) {
    sp.dec();
    mmu.write(sp.value(), (pc.value() >> 8) & 0xFF);
    sp.dec();
    mmu.write(sp.value(), pc.value() & 0xFF);
    pc.set((uint16_t)f);
}

/**
 * Misc
 */
void CPU::stop() {
    // TODO: Change this to something else later.
    exit(1);
}

void CPU::ei() { mmu.write(INTERRUPT_FLAG, 0x1); }

void CPU::di() { mmu.write(INTERRUPT_FLAG, 0x0); }

void CPU::scf() {
    f.setSubtract(false);
    f.setHalfCarry(false);
    f.setCarry(true);
}

void CPU::halt() {
    // TODO: Complete this function
}