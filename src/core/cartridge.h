#pragma once

#include <string>
#include <vector>

#include "cartridge_information.h"

class Cartridge {
   public:
    Cartridge(const std::string& filepath);
    ~Cartridge();

    inline CartridgeInformation getCartridgeInformation() {
        return cartridge_information;
    }

    void write(uint16_t address, uint8_t byte);
    uint8_t read(uint16_t address);

   private:
    std::string cartridge_filepath;
    std::vector<uint8_t> raw_data;
    uint8_t current_bank = 1;
    CartridgeInformation cartridge_information;
};