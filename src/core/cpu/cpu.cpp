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
}

CPU::~CPU() { spdlog::info("Cleaning CPU module"); }

void CPU::GetCPUInformation() {
    printf(
        "Registers:\nA: %02X\tB: %02X\tC: %02X\tD: %02X\nE: %02X\tH: %02X\tL: "
        "%02X\tF: %02X\nPC: %04X\tSP: %04X\n\nFlags:\nZ: %i\tS: %i\tC: %i\tHC: "
        "%i\n",
        a.value, b.value, c.value, d.value, e.value, h.value, l.value, f.value,
        pc.value, sp.value, f.getZero(), f.getSubtract(), f.getCarry(),
        f.getHalfCarry());
}