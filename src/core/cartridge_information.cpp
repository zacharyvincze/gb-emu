#include "cartridge_information.h"

const std::string CartridgeInformation::romSizeString() {
    switch (rom_size) {
        case RomSize::BYTE32K:
            return "32KByte";
        case RomSize::BYTE64K:
            return "64KByte";
        case RomSize::BYTE128K:
            return "128KByte";
        case RomSize::BYTE256K:
            return "256KByte";
        case RomSize::BYTE512K:
            return "512KByte";
        case RomSize::BYTE1M:
            return "1MByte";
        case RomSize::BYTE2M:
            return "2MByte";
        case RomSize::BYTE4M:
            return "4MByte";
        case RomSize::BYTE8M:
            return "8MByte";
        case RomSize::BYTE1_1M:
            return "1.1MByte";
        case RomSize::BYTE1_2M:
            return "1.2MByte";
        case RomSize::BYTE1_5M:
            return "1.5MByte";
        default:
            return "Unknown";
    };
}

const std::string CartridgeInformation::ramSizeString() {
    switch (ram_size) {
        case RamSize::NONE:
            return "None";
        case RamSize::BYTE2K:
            return "2KByte";
        case RamSize::BYTE8K:
            return "8KByte";
        case RamSize::BYTE32K:
            return "32KByte";
        case RamSize::BYTE64K:
            return "64KByte";
        case RamSize::BYTE128K:
            return "128KByte";
        default:
            return "Unknown";
    }
}

const std::string CartridgeInformation::cartridgeTypeString() {
    switch (cartridge_type) {
        case CartridgeType::ROM_ONLY:
            return "ROM ONLY";
        case CartridgeType::MBC1:
            return "MBC1";
        case CartridgeType::MBC1_RAM:
            return "MBC1+RAM";
        case CartridgeType::MBC1_RAM_BATTERY:
            return "MBC1+RAM+BATTERY";
        case CartridgeType::MBC2:
            return "MBC2";
        case CartridgeType::MBC2_BATTERY:
            return "MBC2+BATTERY";
        case CartridgeType::MMM01:
            return "MMM01";
        case CartridgeType::MMM01_RAM:
            return "MMM01+RAM";
        case CartridgeType::MMM01_RAM_BATTERY:
            return "MMM01+RAM+BATTERY";
        case CartridgeType::MBC3_TIMER_BATTERY:
            return "MBC3+TIMER+BATTERY";
        case CartridgeType::MBC3_TIMER_RAM_BATTERY:
            return "MBC3+TIMER+RAM+BATTERY";
        case CartridgeType::MBC3:
            return "MBC3";
        case CartridgeType::MBC3_RAM:
            return "MBC3+RAM";
        case CartridgeType::MBC3_RAM_BATTERY:
            return "MBC3+RAM+BATTERY";
        case CartridgeType::MBC5:
            return "MBC5";
        case CartridgeType::MBC5_RAM:
            return "MBC5+RAM";
        case CartridgeType::MBC5_RAM_BATTERY:
            return "MBC5+RAM+BATTERY";
        case CartridgeType::MBC6:
            return "MBC6";
        case CartridgeType::MBC7_SENSOR_RUMBLE_BATTERY:
            return "MBC7+SENSOR+RUMBLE+BATTERY";
        case CartridgeType::POCKET_CAMERA:
            return "POCKET CAMERA";
        case CartridgeType::BANDAI_TAMA5:
            return "BANDAI TAMA5";
        case CartridgeType::HUC3:
            return "HuC3";
        case CartridgeType::HUC1_RAM_BATTERY:
            return "HuC1+RAM+BATTERY";
        default:
            return "Unknown";
    }
}

void CartridgeInformation::setCartridgeType(uint8_t byte) {
    switch (byte) {
        case 0x00:
            cartridge_type = CartridgeType::ROM_ONLY;
            break;
        case 0x01:
            cartridge_type = CartridgeType::MBC1;
            break;
        case 0x02:
            cartridge_type = CartridgeType::MBC1_RAM;
            break;
        case 0x03:
            cartridge_type = CartridgeType::MBC1_RAM_BATTERY;
            break;
        case 0x05:
            cartridge_type = CartridgeType::MBC2;
            break;
        case 0x06:
            cartridge_type = CartridgeType::MBC2_BATTERY;
            break;
        case 0x08:
            cartridge_type = CartridgeType::ROM_RAM;
            break;
        case 0x09:
            cartridge_type = CartridgeType::ROM_RAM_BATTERY;
            break;
        case 0x0B:
            cartridge_type = CartridgeType::MMM01;
            break;
        case 0x0C:
            cartridge_type = CartridgeType::MMM01_RAM;
            break;
        case 0x0D:
            cartridge_type = CartridgeType::MMM01_RAM_BATTERY;
            break;
        case 0x0F:
            cartridge_type = CartridgeType::MBC3_TIMER_BATTERY;
            break;
        case 0x10:
            cartridge_type = CartridgeType::MBC3_TIMER_RAM_BATTERY;
            break;
        case 0x11:
            cartridge_type = CartridgeType::MBC3;
            break;
        case 0x12:
            cartridge_type = CartridgeType::MBC3_RAM;
            break;
        case 0x13:
            cartridge_type = CartridgeType::MBC3_RAM_BATTERY;
            break;
        case 0x19:
            cartridge_type = CartridgeType::MBC5;
            break;
        case 0x1A:
            cartridge_type = CartridgeType::MBC5_RAM;
            break;
        case 0x1B:
            cartridge_type = CartridgeType::MBC5_RAM_BATTERY;
            break;
        case 0x1C:
            cartridge_type = CartridgeType::MBC5_RUMBLE;
            break;
        case 0x1D:
            cartridge_type = CartridgeType::MBC5_RUMBLE_RAM;
            break;
        case 0x1E:
            cartridge_type = CartridgeType::MBC5_RUMBLE_RAM_BATTERY;
            break;
        case 0x20:
            cartridge_type = CartridgeType::MBC6;
            break;
        case 0x22:
            cartridge_type = CartridgeType::MBC7_SENSOR_RUMBLE_BATTERY;
            break;
        case 0xFC:
            cartridge_type = CartridgeType::POCKET_CAMERA;
            break;
        case 0xFD:
            cartridge_type = CartridgeType::BANDAI_TAMA5;
            break;
        case 0xFE:
            cartridge_type = CartridgeType::HUC3;
            break;
        case 0xFF:
            cartridge_type = CartridgeType::HUC1_RAM_BATTERY;
            break;
        default:
            cartridge_type = CartridgeType::ROM_ONLY;
    }
}

void CartridgeInformation::setRomSize(uint8_t byte) {
    switch (byte) {
        case 0x00:
            rom_size = RomSize::BYTE32K;
            break;
        case 0x01:
            rom_size = RomSize::BYTE64K;
            break;
        case 0x02:
            rom_size = RomSize::BYTE128K;
            break;
        case 0x03:
            rom_size = RomSize::BYTE256K;
            break;
        case 0x04:
            rom_size = RomSize::BYTE512K;
            break;
        case 0x05:
            rom_size = RomSize::BYTE1M;
            break;
        case 0x06:
            rom_size = RomSize::BYTE2M;
            break;
        case 0x07:
            rom_size = RomSize::BYTE4M;
            break;
        case 0x08:
            rom_size = RomSize::BYTE8M;
            break;
        case 0x52:
            rom_size = RomSize::BYTE1_1M;
            break;
        case 0x53:
            rom_size = RomSize::BYTE1_2M;
            break;
        case 0x54:
            rom_size = RomSize::BYTE1_5M;
            break;
        default:
            rom_size = RomSize::BYTE32K;
    }
}

void CartridgeInformation::setRamSize(uint8_t byte) {
    switch (byte) {
        case 0x00:
            ram_size = RamSize::NONE;
            break;
        case 0x01:
            ram_size = RamSize::BYTE2K;
            break;
        case 0x02:
            ram_size = RamSize::BYTE8K;
            break;
        case 0x03:
            ram_size = RamSize::BYTE32K;
            break;
        case 0x04:
            ram_size = RamSize::BYTE128K;
            break;
        case 0x05:
            ram_size = RamSize::BYTE64K;
            break;
        default:
            ram_size = RamSize::NONE;
    }
}
