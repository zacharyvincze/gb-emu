#include "cartridge.h"

#include <fstream>

#include "spdlog/spdlog.h"

Cartridge::Cartridge(const std::string& filepath) {
    spdlog::info("Initializing cartridge module");
    cartridge_filepath = filepath;

    std::ifstream file;
    file.open(filepath.c_str(), std::ios::binary);
    if (!file.is_open()) {
        spdlog::error("Unable to open file {}", filepath);
        return;
    }

    size_t begin = file.tellg();
    file.seekg(0, std::ios::end);
    size_t end = file.tellg();
    file.seekg(0, std::ios::beg);
    size_t file_size = end - begin;
    raw_data.resize(file_size);
    file.read(reinterpret_cast<char*>(raw_data.data()), file_size);
    file.close();
    spdlog::info("Read {} bytes into cartridge memory", file_size);

    cartridge_information.setRomSize(read(CartridgeInformation::ROM_SIZE));
    cartridge_information.setRamSize(read(CartridgeInformation::RAM_SIZE));
    cartridge_information.setCartridgeType(
        read(CartridgeInformation::CARTRIDGE_TYPE));

    std::string title;
    for (int i = CartridgeInformation::TITLE_BEGIN;
         i < CartridgeInformation::TITLE_END; i++) {
        title += read(i);
    }
    title += '\0';
    cartridge_information.setTitle(title);
    cartridge_information.setBanks(file_size / 16384);

    spdlog::info(
        "Cartridge Information:\nTitle: {}\nCartridge Type: {}\nROM: {}\nRAM: "
        "{}\nBanks: {}",
        cartridge_information.getTitle(),
        cartridge_information.cartridgeTypeString(),
        cartridge_information.romSizeString(),
        cartridge_information.ramSizeString(),
        cartridge_information.getBanks());
}

Cartridge::~Cartridge() {
    spdlog::info("Cleaning cartridge module");
    raw_data.clear();
}

void Cartridge::write(uint16_t address, uint8_t byte) {
    // TODO: Only supports MBC1 mapper
    switch (address) {
        case 0x0000 ... 0x7FFF:
            current_bank = byte;
            break;
        default:
            spdlog::warn("Attempt to write to non cartridge memory");
    }
}

uint8_t Cartridge::read(uint16_t address) {
    switch (address) {
        case 0x0000 ... 0x3FFF:
            return raw_data.at(address);
            break;
        case 0x4000 ... 0x7FFF:
            return raw_data.at(
                CartridgeInformation::BANK_SIZE * (current_bank - 1) + address);
            break;
        default:
            return 0x00;
            spdlog::warn(
                "Attempt to read from non-cartridge memory from cartridge.");
    }
}