#pragma once

#include <string>

enum class Licensee {
    NONE,
    NINTENDO_RD1,
    CAPCOM,
    ELECTRONIC_ARTS,
    HUDSON_SOFT,
    B_AI,
    KSS,
    POW,
    PCM_COMPLETE,
    SAN_X,
    KEMCO_JAPAN,
    SETA,
    VIACOM,
    NINTENDO
};

enum class RomSize {
    BYTE32K,
    BYTE64K,
    BYTE128K,
    BYTE256K,
    BYTE512K,
    BYTE1M,
    BYTE2M,
    BYTE4M,
    BYTE8M,
    BYTE1_1M,
    BYTE1_2M,
    BYTE1_5M
};

enum class CartridgeType {
    ROM_ONLY,
    MBC1,
    MBC1_RAM,
    MBC1_RAM_BATTERY,
    MBC2,
    MBC2_BATTERY,
    ROM_RAM,
    ROM_RAM_BATTERY,
    MMM01,
    MMM01_RAM,
    MMM01_RAM_BATTERY,
    MBC3_TIMER_BATTERY,
    MBC3_TIMER_RAM_BATTERY,
    MBC3,
    MBC3_RAM,
    MBC3_RAM_BATTERY,
    MBC5,
    MBC5_RAM,
    MBC5_RAM_BATTERY,
    MBC5_RUMBLE,
    MBC5_RUMBLE_RAM,
    MBC5_RUMBLE_RAM_BATTERY,
    MBC6,
    MBC7_SENSOR_RUMBLE_BATTERY,
    POCKET_CAMERA,
    BANDAI_TAMA5,
    HUC3,
    HUC1_RAM_BATTERY
};

enum class RamSize { NONE, BYTE2K, BYTE8K, BYTE32K, BYTE128K, BYTE64K };

class CartridgeInformation {
   private:
    std::string title;
    RomSize rom_size;
    RamSize ram_size;
    CartridgeType cartridge_type;
    uint8_t banks;

   public:
    static const int NINTENDO_LOGO_BEGIN = 0x0104;
    static const int NINTENDO_LOGO_END = 0x0133;
    static const int TITLE_BEGIN = 0x0134;
    static const int TITLE_END = 0x0143;
    static const int MANUFACTURER_CODE_BEGIN = 0x13F;
    static const int MANUFACTURER_CODE_END = 0x0142;
    static const int CGB_FLAG = 0x0143;
    static const int SGB_FLAG = 0x0146;
    static const int CARTRIDGE_TYPE = 0x0147;
    static const int ROM_SIZE = 0x0148;
    static const int RAM_SIZE = 0x0149;
    static const int BANK_SIZE = 16384;

    const std::string romSizeString();
    const std::string ramSizeString();
    const std::string cartridgeTypeString();
    std::string getTitle() { return title; }

    inline RomSize getRomSize() { return rom_size; }
    inline RamSize getRamSize() { return ram_size; }
    inline CartridgeType getCartridgeType() { return cartridge_type; }

    void setRomSize(uint8_t byte);
    void setRamSize(uint8_t byte);
    void setCartridgeType(uint8_t byte);
    void setTitle(std::string& title) { this->title = title; }

    void setBanks(int banks) { this->banks = banks; }
    uint8_t getBanks() { return banks; }
};