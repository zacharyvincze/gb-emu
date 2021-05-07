#include "mmu.h"

#include <stdlib.h>

#include <fstream>
#include <iomanip>

#include "spdlog/spdlog.h"

MMU::MMU(Cartridge& cartridge, const std::string& bootstrap)
    : cartridge(cartridge) {
    spdlog::info("Initializing MMU module");

    // Clear memory
    for (int i = 0; i < 0x10000; i++) {
        data[i];
    }

    std::ifstream infile;
    infile.open(bootstrap.c_str());
    if (!infile.is_open()) {
        spdlog::error("Unable to open file: {}", bootstrap);
    }

    size_t begin = infile.tellg();
    infile.seekg(0, std::ios::end);
    size_t end = infile.tellg();
    infile.seekg(0, std::ios::beg);
    infile.read(reinterpret_cast<char*>(bootstrap_rom), BOOTSTRAP_ROM_SIZE);
    infile.close();
}

MMU::~MMU() { spdlog::info("Cleaning MMU module"); }

uint8_t MMU::read(uint16_t address) {
    spdlog::debug("Reading from address {0:x}", address);
    switch (address) {
        case 0x0000 ... 0x7FFF:
            if (bootstrap_active) {
                return bootstrap_rom[address];
            } else {
                return cartridge.read(address);
            }
        case 0x8000 ... 0x97FF:
            return data[address];
        case 0x9800 ... 0x9BFF:
            return data[address];
        case 0x9C00 ... 0x9FFF:
            return data[address];
        case 0xA000 ... 0xBFFF:
            // TODO: Cartridge RAM
            return data[address];
        case 0xC000 ... 0xDFFF:
            return data[address];
        case 0xE000 ... 0xFDFF:
            return data[address - 0x2000];
        case 0xFE00 ... 0xFE9F:
            return data[address];
        case 0xFEA0 ... 0xFEFF:
            return data[address];
            spdlog::warn("Reading from unused memory.");
        case 0xFF00 ... 0xFF7F:
            // TODO: Hardware IO registers
            break;
        case 0xFF80 ... 0xFFFE:
            return data[address];
        case 0xFFFF:
            // TODO: Interrupt enable register
            break;
    }

    return 0x00;
}

void MMU::write(uint16_t address, uint8_t byte) {
    spdlog::debug("Writing {0:x} to address {1:x}", byte, address);
    switch (address) {
        case 0x0000 ... 0x7FFF:
            cartridge.write(address, byte);
            break;
        case 0x8000 ... 0x97FF:
            data[address] = byte;
            break;
        case 0x9800 ... 0x9BFF:
            data[address] = byte;
            break;
        case 0x9C00 ... 0x9FFF:
            data[address] = byte;
            break;
        case 0xA000 ... 0xBFFF:
            data[address] = byte;
            break;
        case 0xC000 ... 0xDFFF:
            data[address] = byte;
            break;
        case 0xE000 ... 0xFDFF:
            data[address - 0x2000] = byte;
            break;
        case 0xFE00 ... 0xFE9F:
            data[address] = byte;
            break;
        case 0xFEA0 ... 0xFEFF:
            data[address] = byte;
            spdlog::warn("Writing to unused memory.");
            break;
        case 0xFF00 ... 0xFF7F:
            // TODO: Memory mapped IO
            break;
        case 0xFF80 ... 0xFFFE:
            data[address] = byte;
            break;
        case 0xFFFF:
            // TODO: Interrupt enable register
            break;
    }
}