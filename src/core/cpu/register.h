#pragma once

#include "stdint.h"

class ByteRegister {
   protected:
    uint8_t val;

   public:
    void inc() { val++; }
    void dec() { val--; }
    void reset() { val = 0; }
    uint8_t value() { return val; }
    void set(uint8_t value) { val = value; }
};

class WordRegister {
   private:
    uint16_t val;

   public:
    virtual void inc() { val++; }
    virtual void dec() { val--; }
    virtual void reset() { val = 0; }
    virtual uint16_t value() { return val; }
    virtual void set(uint16_t value) { this->val = value; }
};

class HybridRegister : public WordRegister {
   public:
    HybridRegister(ByteRegister& upper, ByteRegister& lower)
        : upper(upper), lower(lower) {}
    uint16_t value();
    void set(uint16_t value);
    void reset();
    void inc();
    void dec();

   private:
    ByteRegister& lower;
    ByteRegister& upper;
};

struct FlagRegister : public ByteRegister {
    void setZero(bool set) { val = val & set << 7; }
    bool getZero() { return val >> 7 & 1; }
    void setSubtract(bool set) { val = val & set << 6; }
    bool getSubtract() { return val >> 6 & 1; }
    void setHalfCarry(bool set) { val = val & set << 5; }
    bool getHalfCarry() { return val >> 5 & 1; }
    void setCarry(bool set) { val = val & set << 4; }
    bool getCarry() { return val >> 4 & 1; }
};