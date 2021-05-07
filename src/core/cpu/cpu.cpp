#include "cpu.h"

#include <iostream>
#include <sstream>

#include "spdlog/spdlog.h"

CPU::CPU(MMU& mmu, GPU& gpu)
    : af(a, f), bc(b, c), de(d, e), hl(h, l), mmu(mmu), gpu(gpu) {
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
    timer.reset();

    (this->*opcodes[0])();
    running = true;
}

CPU::~CPU() { spdlog::info("Cleaning CPU module"); }

void CPU::init() {
    gpu.init();

    running = true;
    bool next_step = false;
    while (running) {
        if (next_step) {
            next_step = false;
            uint8_t opcode = getNextByte();
            if (opcode == 0xCB) {
                uint8_t cb_opcode = getNextByte();
                spdlog::info("Executing CB opcode: {0:x}", cb_opcode);
                (this->*cb_opcodes[cb_opcode])();
                timer.increment_m(Timing::M_TIMES_CB[cb_opcode]);
            } else {
                spdlog::info("Executing opcode: {0:x}", opcode);
                (this->*opcodes[opcode])();
                timer.increment_m(Timing::M_TIMES[opcode]);
            }
            GetCPUInformation();
        }

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_RIGHT:
                        next_step = true;
                        break;
                }
            }
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
        "%i\n\nTimers:\nM: %i\tT: %i\n",
        a.value(), b.value(), c.value(), d.value(), e.value(), h.value(),
        l.value(), f.value(), pc.value(), sp.value(), f.getZero(),
        f.getSubtract(), f.getCarry(), f.getHalfCarry(), timer.get_m(),
        timer.get_t());
}