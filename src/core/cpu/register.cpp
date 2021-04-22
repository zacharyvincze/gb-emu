#include "register.h"

void HybridRegister::reset() {
    upper.reset();
    lower.reset();
}

void HybridRegister::set(uint16_t value) {
    upper.set((uint8_t)(value >> 8));
    lower.set(((uint8_t)value));
}

uint16_t HybridRegister::value() { return upper.value() << 8 | lower.value(); }

void HybridRegister::inc() { set((uint16_t)(value() + 1)); }

void HybridRegister::dec() { set((uint16_t)(value() - 1)); }