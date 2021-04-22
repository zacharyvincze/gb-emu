#include "cpu.h"

#include <iostream>
#include <sstream>

#include "spdlog/spdlog.h"

CPU::CPU(MMU& mmu) : af(a, f), bc(b, c), de(d, e), hl(h, l), mmu(mmu) {
    spdlog::info("Initializing CPU module");
    a.reset();
    b.reset();
    c.reset();
    d.reset();
    e.reset();
    h.reset();
    l.reset();

    sp.reset();
    pc.reset();

    f.reset();

    (this->*opcodes[0])();
    running = true;
}

CPU::~CPU() { spdlog::info("Cleaning CPU module"); }

void CPU::init() {
    running = true;
    while (running) {
        uint8_t opcode = getNextByte();
        if (opcode == 0xCB) {
            (this->*cb_opcodes[getNextByte()])();
        } else {
            (this->*opcodes[opcode])();
        }
    }
}

uint8_t CPU::getNextByte() {
    uint8_t opcode = mmu.read(pc.value());
    pc.inc();
    return opcode;
}

uint16_t CPU::getNextWord() {
    return static_cast<uint16_t>(getNextByte() | (getNextByte() << 8));
}

void CPU::GetCPUInformation() {
    printf(
        "Registers:\nA: %02X\tB: %02X\tC: %02X\tD: %02X\nE: %02X\tH: %02X\tL: "
        "%02X\tF: %02X\nPC: %04X\tSP: %04X\n\nFlags:\nZ: %i\tS: %i\tC: %i\tHC: "
        "%i\n",
        a.value(), b.value(), c.value(), d.value(), e.value(), h.value(),
        l.value(), f.value(), pc.value(), sp.value(), f.getZero(),
        f.getSubtract(), f.getCarry(), f.getHalfCarry());
}