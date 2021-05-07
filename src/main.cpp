#include <spdlog/spdlog.h>

#include <iostream>

#include "core/cartridge.h"
#include "core/cpu/cpu.h"
#include "core/cpu/mmu.h"
#include "core/gpu/gpu.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: gb_emu <bootstrap_rom> <rom_filepath>\n";
        return -1;
    }

    spdlog::set_level(spdlog::level::debug);

    Cartridge cartridge(argv[2]);
    MMU mmu(cartridge, argv[1]);
    GPU gpu;
    CPU cpu(mmu, gpu);

    cpu.init();

    return 0;
}