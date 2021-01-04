#pragma once

#include <iostream>

#include "cpu/cpu.h"

class Gameboy {
   public:
    Gameboy() {}
    ~Gameboy() {}

   private:
    CPU& cpu;
};