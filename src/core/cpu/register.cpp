#include "register.h"

void HybridRegister::reset() {
    upper.reset();
    lower.reset();
}

void HybridRegister::set(uint16_t value) {
    upper.value = (uint8_t)(value >> 8);
    lower.value = (uint8_t)value;
}

uint16_t HybridRegister::get() { return upper.value << 8 | lower.value; }

void HybridRegister::inc() { set((uint16_t)(get() + 1)); }

void HybridRegister::dec() { set((uint16_t)(get() - 1)); }