#pragma once

#include "stdint.h"

struct ByteRegister {
    uint8_t value;
    void inc() { value++; }
    void dec() { value--; }
    void reset() { value = 0; }
};

struct WordRegister {
    uint16_t value;
    void inc() { value++; }
    void dec() { value--; }
    void reset() { value = 0; }
};

class HybridRegister {
   public:
    HybridRegister(ByteRegister& upper, ByteRegister& lower)
        : upper(upper), lower(lower) {}
    uint16_t get();
    void set(uint16_t value);
    void reset();
    void inc();
    void dec();

   private:
    ByteRegister& lower;
    ByteRegister& upper;
};

struct FlagRegister : public ByteRegister {
    void setZero(bool set) { value = value & set << 7; }
    bool getZero() { return value >> 7 & 1; }
    void setSubtract(bool set) { value = value & set << 6; }
    bool getSubtract() { return value >> 6 & 1; }
    void setHalfCarry(bool set) { value = value & set << 5; }
    bool getHalfCarry() { return value >> 5 & 1; }
    void setCarry(bool set) { value = value & set << 4; }
    bool getCarry() { return value >> 4 & 1; }
};