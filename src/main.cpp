#include <iostream>

#include "core/cartridge.h"
#include "core/cpu/cpu.h"
#include "core/cpu/mmu.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: gb_emu <bootstrap_rom> <rom_filepath>\n";
        return -1;
    }
    Cartridge cartridge(argv[2]);
    MMU mmu(cartridge, argv[1]);
    CPU cpu(mmu);
    return 0;
}