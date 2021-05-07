#pragma once

#include <stdint.h>

#include <string>
#include <vector>

#include "../cartridge.h"

class MMU {
    /**
     * Memory Management Unit controller.
     **/
   public:
    MMU(Cartridge& cartridge, const std::string& bootstrap);
    ~MMU();

    const static uint BOOTSTRAP_ROM_SIZE = 0x100;

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t byte);

    void dumpMem(const std::string& filepath);

   private:
    Cartridge& cartridge;
    uint8_t data[0x10000];
    uint8_t bootstrap_rom[0x100];
    bool bootstrap_active = true;
};