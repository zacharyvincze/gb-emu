#pragma once

#include <iostream>

#include "mmu.h"
#include "register.h"

class CPU;
typedef void (CPU::*CPUFn)();

class CPU {
   public:
    CPU(MMU& mmu);
    ~CPU();

    void GetCPUInformation();

    void init();

   private:
    bool running;

    WordRegister sp;
    WordRegister pc;

    ByteRegister a;
    ByteRegister b;
    ByteRegister c;
    ByteRegister d;
    ByteRegister e;
    ByteRegister h;
    ByteRegister l;

    FlagRegister f;

    HybridRegister af;
    HybridRegister bc;
    HybridRegister de;
    HybridRegister hl;

    uint8_t getNextByte();
    uint16_t getNextWord();

    MMU& mmu;

    // Helper opcodes
    void ld(WordRegister& reg);
    void ld(WordRegister& addr, ByteRegister& reg);
    void ld(ByteRegister& reg);
    void ld_sp(WordRegister& reg);
    void ld(ByteRegister& reg, uint16_t address);
    void ld(ByteRegister& reg, WordRegister& word_reg);
    void ld(ByteRegister& reg, ByteRegister& reg2);

    void ldi(WordRegister& reg, ByteRegister& byte_reg);
    void ldi(ByteRegister& byte_reg, WordRegister& reg);
    void ldd(WordRegister& reg, ByteRegister& byte_reg);
    void ldd(ByteRegister& byte_reg, WordRegister& reg);

    void inc(WordRegister& reg);
    void inc(ByteRegister& reg);
    void inc(uint16_t address);

    void dec(ByteRegister& reg);
    void dec(WordRegister& reg);
    void dec(uint16_t address);

    void rlca();
    void rrca();
    void rla();
    void rra();

    void jr();
    void jr_cond(bool condition);

    void stop();

    void add(WordRegister& reg, uint16_t value);
    void add(WordRegister& reg, WordRegister& reg2);
    void add(ByteRegister& reg, uint8_t value);
    void add(ByteRegister& reg, ByteRegister& reg2);
    void add(ByteRegister& reg, WordRegister& addr);

    void adc(ByteRegister& reg, uint8_t value);
    void adc(ByteRegister& reg, ByteRegister& reg2);
    void adc(ByteRegister& reg, WordRegister& addr);

    void sub(ByteRegister& reg, uint8_t value);
    void sub(ByteRegister& reg, ByteRegister& reg2);
    void sub(ByteRegister& reg, WordRegister& addr);

    void sbc(ByteRegister& reg, uint8_t value);
    void sbc(ByteRegister& reg, ByteRegister& reg2);
    void sbc(ByteRegister& reg, WordRegister& addr);

    void daa();
    void cpl();
    void scf();
    void ccf();

    void halt();

    void Unimplementedopcode() { std::cout << "opcode is unimplemented.\n"; }

    // Beware below, I didn't want to turn off my auto-formatter

    void opcode00();
    void opcode01();
    void opcode02();
    void opcode03();
    void opcode04();
    void opcode05();
    void opcode06();
    void opcode07();
    void opcode08();
    void opcode09();
    void opcode0A();
    void opcode0B();
    void opcode0C();
    void opcode0D();
    void opcode0E();
    void opcode0F();

    void opcode10();
    void opcode11();
    void opcode12();
    void opcode13();
    void opcode14();
    void opcode15();
    void opcode16();
    void opcode17();
    void opcode18();
    void opcode19();
    void opcode1A();
    void opcode1B();
    void opcode1C();
    void opcode1D();
    void opcode1E();
    void opcode1F();

    void opcode20();
    void opcode21();
    void opcode22();
    void opcode23();
    void opcode24();
    void opcode25();
    void opcode26();
    void opcode27();
    void opcode28();
    void opcode29();
    void opcode2A();
    void opcode2B();
    void opcode2C();
    void opcode2D();
    void opcode2E();
    void opcode2F();

    void opcode30();
    void opcode31();
    void opcode32();
    void opcode33();
    void opcode34();
    void opcode35();
    void opcode36();
    void opcode37();
    void opcode38();
    void opcode39();
    void opcode3A();
    void opcode3B();
    void opcode3C();
    void opcode3D();
    void opcode3E();
    void opcode3F();

    void opcode40();
    void opcode41();
    void opcode42();
    void opcode43();
    void opcode44();
    void opcode45();
    void opcode46();
    void opcode47();
    void opcode48();
    void opcode49();
    void opcode4A();
    void opcode4B();
    void opcode4C();
    void opcode4D();
    void opcode4E();
    void opcode4F();

    void opcode50();
    void opcode51();
    void opcode52();
    void opcode53();
    void opcode54();
    void opcode55();
    void opcode56();
    void opcode57();
    void opcode58();
    void opcode59();
    void opcode5A();
    void opcode5B();
    void opcode5C();
    void opcode5D();
    void opcode5E();
    void opcode5F();

    void opcode60();
    void opcode61();
    void opcode62();
    void opcode63();
    void opcode64();
    void opcode65();
    void opcode66();
    void opcode67();
    void opcode68();
    void opcode69();
    void opcode6A();
    void opcode6B();
    void opcode6C();
    void opcode6D();
    void opcode6E();
    void opcode6F();

    void opcode70();
    void opcode71();
    void opcode72();
    void opcode73();
    void opcode74();
    void opcode75();
    void opcode76();
    void opcode77();
    void opcode78();
    void opcode79();
    void opcode7A();
    void opcode7B();
    void opcode7C();
    void opcode7D();
    void opcode7E();
    void opcode7F();

    void opcode80();
    void opcode81();
    void opcode82();
    void opcode83();
    void opcode84();
    void opcode85();
    void opcode86();
    void opcode87();
    void opcode88();
    void opcode89();
    void opcode8A();
    void opcode8B();
    void opcode8C();
    void opcode8D();
    void opcode8E();
    void opcode8F();

    void opcode90();
    void opcode91();
    void opcode92();
    void opcode93();
    void opcode94();
    void opcode95();
    void opcode96();
    void opcode97();
    void opcode98();
    void opcode99();
    void opcode9A();
    void opcode9B();
    void opcode9C();
    void opcode9D();
    void opcode9E();
    void opcode9F();

    void opcodeA0();
    void opcodeA1();
    void opcodeA2();
    void opcodeA3();
    void opcodeA4();
    void opcodeA5();
    void opcodeA6();
    void opcodeA7();
    void opcodeA8();
    void opcodeA9();
    void opcodeAA();
    void opcodeAB();
    void opcodeAC();
    void opcodeAD();
    void opcodeAE();
    void opcodeAF();

    void opcodeB0();
    void opcodeB1();
    void opcodeB2();
    void opcodeB3();
    void opcodeB4();
    void opcodeB5();
    void opcodeB6();
    void opcodeB7();
    void opcodeB8();
    void opcodeB9();
    void opcodeBA();
    void opcodeBB();
    void opcodeBC();
    void opcodeBD();
    void opcodeBE();
    void opcodeBF();

    void opcodeC0();
    void opcodeC1();
    void opcodeC2();
    void opcodeC3();
    void opcodeC4();
    void opcodeC5();
    void opcodeC6();
    void opcodeC7();
    void opcodeC8();
    void opcodeC9();
    void opcodeCA();
    void opcodeCB();
    void opcodeCC();
    void opcodeCD();
    void opcodeCE();
    void opcodeCF();

    void opcodeD0();
    void opcodeD1();
    void opcodeD2();
    void opcodeD3();
    void opcodeD4();
    void opcodeD5();
    void opcodeD6();
    void opcodeD7();
    void opcodeD8();
    void opcodeD9();
    void opcodeDA();
    void opcodeDB();
    void opcodeDC();
    void opcodeDD();
    void opcodeDE();
    void opcodeDF();

    void opcodeE0();
    void opcodeE1();
    void opcodeE2();
    void opcodeE3();
    void opcodeE4();
    void opcodeE5();
    void opcodeE6();
    void opcodeE7();
    void opcodeE8();
    void opcodeE9();
    void opcodeEA();
    void opcodeEB();
    void opcodeEC();
    void opcodeED();
    void opcodeEE();
    void opcodeEF();

    void opcodeF0();
    void opcodeF1();
    void opcodeF2();
    void opcodeF3();
    void opcodeF4();
    void opcodeF5();
    void opcodeF6();
    void opcodeF7();
    void opcodeF8();
    void opcodeF9();
    void opcodeFA();
    void opcodeFB();
    void opcodeFC();
    void opcodeFD();
    void opcodeFE();
    void opcodeFF();

    void cbopcode00();
    void cbopcode01();
    void cbopcode02();
    void cbopcode03();
    void cbopcode04();
    void cbopcode05();
    void cbopcode06();
    void cbopcode07();
    void cbopcode08();
    void cbopcode09();
    void cbopcode0A();
    void cbopcode0B();
    void cbopcode0C();
    void cbopcode0D();
    void cbopcode0E();
    void cbopcode0F();

    void cbopcode10();
    void cbopcode11();
    void cbopcode12();
    void cbopcode13();
    void cbopcode14();
    void cbopcode15();
    void cbopcode16();
    void cbopcode17();
    void cbopcode18();
    void cbopcode19();
    void cbopcode1A();
    void cbopcode1B();
    void cbopcode1C();
    void cbopcode1D();
    void cbopcode1E();
    void cbopcode1F();

    void cbopcode20();
    void cbopcode21();
    void cbopcode22();
    void cbopcode23();
    void cbopcode24();
    void cbopcode25();
    void cbopcode26();
    void cbopcode27();
    void cbopcode28();
    void cbopcode29();
    void cbopcode2A();
    void cbopcode2B();
    void cbopcode2C();
    void cbopcode2D();
    void cbopcode2E();
    void cbopcode2F();

    void cbopcode30();
    void cbopcode31();
    void cbopcode32();
    void cbopcode33();
    void cbopcode34();
    void cbopcode35();
    void cbopcode36();
    void cbopcode37();
    void cbopcode38();
    void cbopcode39();
    void cbopcode3A();
    void cbopcode3B();
    void cbopcode3C();
    void cbopcode3D();
    void cbopcode3E();
    void cbopcode3F();

    void cbopcode40();
    void cbopcode41();
    void cbopcode42();
    void cbopcode43();
    void cbopcode44();
    void cbopcode45();
    void cbopcode46();
    void cbopcode47();
    void cbopcode48();
    void cbopcode49();
    void cbopcode4A();
    void cbopcode4B();
    void cbopcode4C();
    void cbopcode4D();
    void cbopcode4E();
    void cbopcode4F();

    void cbopcode50();
    void cbopcode51();
    void cbopcode52();
    void cbopcode53();
    void cbopcode54();
    void cbopcode55();
    void cbopcode56();
    void cbopcode57();
    void cbopcode58();
    void cbopcode59();
    void cbopcode5A();
    void cbopcode5B();
    void cbopcode5C();
    void cbopcode5D();
    void cbopcode5E();
    void cbopcode5F();

    void cbopcode60();
    void cbopcode61();
    void cbopcode62();
    void cbopcode63();
    void cbopcode64();
    void cbopcode65();
    void cbopcode66();
    void cbopcode67();
    void cbopcode68();
    void cbopcode69();
    void cbopcode6A();
    void cbopcode6B();
    void cbopcode6C();
    void cbopcode6D();
    void cbopcode6E();
    void cbopcode6F();

    void cbopcode70();
    void cbopcode71();
    void cbopcode72();
    void cbopcode73();
    void cbopcode74();
    void cbopcode75();
    void cbopcode76();
    void cbopcode77();
    void cbopcode78();
    void cbopcode79();
    void cbopcode7A();
    void cbopcode7B();
    void cbopcode7C();
    void cbopcode7D();
    void cbopcode7E();
    void cbopcode7F();

    void cbopcode80();
    void cbopcode81();
    void cbopcode82();
    void cbopcode83();
    void cbopcode84();
    void cbopcode85();
    void cbopcode86();
    void cbopcode87();
    void cbopcode88();
    void cbopcode89();
    void cbopcode8A();
    void cbopcode8B();
    void cbopcode8C();
    void cbopcode8D();
    void cbopcode8E();
    void cbopcode8F();

    void cbopcode90();
    void cbopcode91();
    void cbopcode92();
    void cbopcode93();
    void cbopcode94();
    void cbopcode95();
    void cbopcode96();
    void cbopcode97();
    void cbopcode98();
    void cbopcode99();
    void cbopcode9A();
    void cbopcode9B();
    void cbopcode9C();
    void cbopcode9D();
    void cbopcode9E();
    void cbopcode9F();

    void cbopcodeA0();
    void cbopcodeA1();
    void cbopcodeA2();
    void cbopcodeA3();
    void cbopcodeA4();
    void cbopcodeA5();
    void cbopcodeA6();
    void cbopcodeA7();
    void cbopcodeA8();
    void cbopcodeA9();
    void cbopcodeAA();
    void cbopcodeAB();
    void cbopcodeAC();
    void cbopcodeAD();
    void cbopcodeAE();
    void cbopcodeAF();

    void cbopcodeB0();
    void cbopcodeB1();
    void cbopcodeB2();
    void cbopcodeB3();
    void cbopcodeB4();
    void cbopcodeB5();
    void cbopcodeB6();
    void cbopcodeB7();
    void cbopcodeB8();
    void cbopcodeB9();
    void cbopcodeBA();
    void cbopcodeBB();
    void cbopcodeBC();
    void cbopcodeBD();
    void cbopcodeBE();
    void cbopcodeBF();

    void cbopcodeC0();
    void cbopcodeC1();
    void cbopcodeC2();
    void cbopcodeC3();
    void cbopcodeC4();
    void cbopcodeC5();
    void cbopcodeC6();
    void cbopcodeC7();
    void cbopcodeC8();
    void cbopcodeC9();
    void cbopcodeCA();
    void cbopcodeCB();
    void cbopcodeCC();
    void cbopcodeCD();
    void cbopcodeCE();
    void cbopcodeCF();

    void cbopcodeD0();
    void cbopcodeD1();
    void cbopcodeD2();
    void cbopcodeD3();
    void cbopcodeD4();
    void cbopcodeD5();
    void cbopcodeD6();
    void cbopcodeD7();
    void cbopcodeD8();
    void cbopcodeD9();
    void cbopcodeDA();
    void cbopcodeDB();
    void cbopcodeDC();
    void cbopcodeDD();
    void cbopcodeDE();
    void cbopcodeDF();

    void cbopcodeE0();
    void cbopcodeE1();
    void cbopcodeE2();
    void cbopcodeE3();
    void cbopcodeE4();
    void cbopcodeE5();
    void cbopcodeE6();
    void cbopcodeE7();
    void cbopcodeE8();
    void cbopcodeE9();
    void cbopcodeEA();
    void cbopcodeEB();
    void cbopcodeEC();
    void cbopcodeED();
    void cbopcodeEE();
    void cbopcodeEF();

    void cbopcodeF0();
    void cbopcodeF1();
    void cbopcodeF2();
    void cbopcodeF3();
    void cbopcodeF4();
    void cbopcodeF5();
    void cbopcodeF6();
    void cbopcodeF7();
    void cbopcodeF8();
    void cbopcodeF9();
    void cbopcodeFA();
    void cbopcodeFB();
    void cbopcodeFC();
    void cbopcodeFD();
    void cbopcodeFE();
    void cbopcodeFF();

    const CPUFn opcodes[256] = {
        &CPU::opcode00, &CPU::opcode01, &CPU::opcode02, &CPU::opcode03,
        &CPU::opcode04, &CPU::opcode05, &CPU::opcode06, &CPU::opcode07,
        &CPU::opcode08, &CPU::opcode09, &CPU::opcode0A, &CPU::opcode0B,
        &CPU::opcode0C, &CPU::opcode0D, &CPU::opcode0E, &CPU::opcode0F,

        &CPU::opcode10, &CPU::opcode11, &CPU::opcode12, &CPU::opcode13,
        &CPU::opcode14, &CPU::opcode15, &CPU::opcode16, &CPU::opcode17,
        &CPU::opcode18, &CPU::opcode19, &CPU::opcode1A, &CPU::opcode1B,
        &CPU::opcode1C, &CPU::opcode1D, &CPU::opcode1E, &CPU::opcode1F,

        &CPU::opcode20, &CPU::opcode21, &CPU::opcode22, &CPU::opcode23,
        &CPU::opcode24, &CPU::opcode25, &CPU::opcode26, &CPU::opcode27,
        &CPU::opcode28, &CPU::opcode29, &CPU::opcode2A, &CPU::opcode2B,
        &CPU::opcode2C, &CPU::opcode2D, &CPU::opcode2E, &CPU::opcode2F,

        &CPU::opcode30, &CPU::opcode31, &CPU::opcode32, &CPU::opcode33,
        &CPU::opcode34, &CPU::opcode35, &CPU::opcode36, &CPU::opcode37,
        &CPU::opcode38, &CPU::opcode39, &CPU::opcode3A, &CPU::opcode3B,
        &CPU::opcode3C, &CPU::opcode3D, &CPU::opcode3E, &CPU::opcode3F,

        &CPU::opcode40, &CPU::opcode41, &CPU::opcode42, &CPU::opcode43,
        &CPU::opcode44, &CPU::opcode45, &CPU::opcode46, &CPU::opcode47,
        &CPU::opcode48, &CPU::opcode49, &CPU::opcode4A, &CPU::opcode4B,
        &CPU::opcode4C, &CPU::opcode4D, &CPU::opcode4E, &CPU::opcode4F,

        &CPU::opcode50, &CPU::opcode51, &CPU::opcode52, &CPU::opcode53,
        &CPU::opcode54, &CPU::opcode55, &CPU::opcode56, &CPU::opcode57,
        &CPU::opcode58, &CPU::opcode59, &CPU::opcode5A, &CPU::opcode5B,
        &CPU::opcode5C, &CPU::opcode5D, &CPU::opcode5E, &CPU::opcode5F,

        &CPU::opcode60, &CPU::opcode61, &CPU::opcode62, &CPU::opcode63,
        &CPU::opcode64, &CPU::opcode65, &CPU::opcode66, &CPU::opcode67,
        &CPU::opcode68, &CPU::opcode69, &CPU::opcode6A, &CPU::opcode6B,
        &CPU::opcode6C, &CPU::opcode6D, &CPU::opcode6E, &CPU::opcode6F,

        &CPU::opcode70, &CPU::opcode71, &CPU::opcode72, &CPU::opcode73,
        &CPU::opcode74, &CPU::opcode75, &CPU::opcode76, &CPU::opcode77,
        &CPU::opcode78, &CPU::opcode79, &CPU::opcode7A, &CPU::opcode7B,
        &CPU::opcode7C, &CPU::opcode7D, &CPU::opcode7E, &CPU::opcode7F,

        &CPU::opcode80, &CPU::opcode81, &CPU::opcode82, &CPU::opcode83,
        &CPU::opcode84, &CPU::opcode85, &CPU::opcode86, &CPU::opcode87,
        &CPU::opcode88, &CPU::opcode89, &CPU::opcode8A, &CPU::opcode8B,
        &CPU::opcode8C, &CPU::opcode8D, &CPU::opcode8E, &CPU::opcode8F,

        &CPU::opcode90, &CPU::opcode91, &CPU::opcode92, &CPU::opcode93,
        &CPU::opcode94, &CPU::opcode95, &CPU::opcode96, &CPU::opcode97,
        &CPU::opcode98, &CPU::opcode99, &CPU::opcode9A, &CPU::opcode9B,
        &CPU::opcode9C, &CPU::opcode9D, &CPU::opcode9E, &CPU::opcode9F,

        &CPU::opcodeA0, &CPU::opcodeA1, &CPU::opcodeA2, &CPU::opcodeA3,
        &CPU::opcodeA4, &CPU::opcodeA5, &CPU::opcodeA6, &CPU::opcodeA7,
        &CPU::opcodeA8, &CPU::opcodeA9, &CPU::opcodeAA, &CPU::opcodeAB,
        &CPU::opcodeAC, &CPU::opcodeAD, &CPU::opcodeAE, &CPU::opcodeAF,

        &CPU::opcodeB0, &CPU::opcodeB1, &CPU::opcodeB2, &CPU::opcodeB3,
        &CPU::opcodeB4, &CPU::opcodeB5, &CPU::opcodeB6, &CPU::opcodeB7,
        &CPU::opcodeB8, &CPU::opcodeB9, &CPU::opcodeBA, &CPU::opcodeBB,
        &CPU::opcodeBC, &CPU::opcodeBD, &CPU::opcodeBE, &CPU::opcodeBF,

        &CPU::opcodeC0, &CPU::opcodeC1, &CPU::opcodeC2, &CPU::opcodeC3,
        &CPU::opcodeC4, &CPU::opcodeC5, &CPU::opcodeC6, &CPU::opcodeC7,
        &CPU::opcodeC8, &CPU::opcodeC9, &CPU::opcodeCA, &CPU::opcodeCB,
        &CPU::opcodeCC, &CPU::opcodeCD, &CPU::opcodeCE, &CPU::opcodeCF,

        &CPU::opcodeD0, &CPU::opcodeD1, &CPU::opcodeD2, &CPU::opcodeD3,
        &CPU::opcodeD4, &CPU::opcodeD5, &CPU::opcodeD6, &CPU::opcodeD7,
        &CPU::opcodeD8, &CPU::opcodeD9, &CPU::opcodeDA, &CPU::opcodeDB,
        &CPU::opcodeDC, &CPU::opcodeDD, &CPU::opcodeDE, &CPU::opcodeDF,

        &CPU::opcodeE0, &CPU::opcodeE1, &CPU::opcodeE2, &CPU::opcodeE3,
        &CPU::opcodeE4, &CPU::opcodeE5, &CPU::opcodeE6, &CPU::opcodeE7,
        &CPU::opcodeE8, &CPU::opcodeE9, &CPU::opcodeEA, &CPU::opcodeEB,
        &CPU::opcodeEC, &CPU::opcodeED, &CPU::opcodeEE, &CPU::opcodeEF,

        &CPU::opcodeF0, &CPU::opcodeF1, &CPU::opcodeF2, &CPU::opcodeF3,
        &CPU::opcodeF4, &CPU::opcodeF5, &CPU::opcodeF6, &CPU::opcodeF7,
        &CPU::opcodeF8, &CPU::opcodeF9, &CPU::opcodeFA, &CPU::opcodeFB,
        &CPU::opcodeFC, &CPU::opcodeFD, &CPU::opcodeFE, &CPU::opcodeFF};
    const CPUFn cb_opcodes[256] = {
        &CPU::cbopcode00, &CPU::cbopcode01, &CPU::cbopcode02, &CPU::cbopcode03,
        &CPU::cbopcode04, &CPU::cbopcode05, &CPU::cbopcode06, &CPU::cbopcode07,
        &CPU::cbopcode08, &CPU::cbopcode09, &CPU::cbopcode0A, &CPU::cbopcode0B,
        &CPU::cbopcode0C, &CPU::cbopcode0D, &CPU::cbopcode0E, &CPU::cbopcode0F,

        &CPU::cbopcode10, &CPU::cbopcode11, &CPU::cbopcode12, &CPU::cbopcode13,
        &CPU::cbopcode14, &CPU::cbopcode15, &CPU::cbopcode16, &CPU::cbopcode17,
        &CPU::cbopcode18, &CPU::cbopcode19, &CPU::cbopcode1A, &CPU::cbopcode1B,
        &CPU::cbopcode1C, &CPU::cbopcode1D, &CPU::cbopcode1E, &CPU::cbopcode1F,

        &CPU::cbopcode20, &CPU::cbopcode21, &CPU::cbopcode22, &CPU::cbopcode23,
        &CPU::cbopcode24, &CPU::cbopcode25, &CPU::cbopcode26, &CPU::cbopcode27,
        &CPU::cbopcode28, &CPU::cbopcode29, &CPU::cbopcode2A, &CPU::cbopcode2B,
        &CPU::cbopcode2C, &CPU::cbopcode2D, &CPU::cbopcode2E, &CPU::cbopcode2F,

        &CPU::cbopcode30, &CPU::cbopcode31, &CPU::cbopcode32, &CPU::cbopcode33,
        &CPU::cbopcode34, &CPU::cbopcode35, &CPU::cbopcode36, &CPU::cbopcode37,
        &CPU::cbopcode38, &CPU::cbopcode39, &CPU::cbopcode3A, &CPU::cbopcode3B,
        &CPU::cbopcode3C, &CPU::cbopcode3D, &CPU::cbopcode3E, &CPU::cbopcode3F,

        &CPU::cbopcode40, &CPU::cbopcode41, &CPU::cbopcode42, &CPU::cbopcode43,
        &CPU::cbopcode44, &CPU::cbopcode45, &CPU::cbopcode46, &CPU::cbopcode47,
        &CPU::cbopcode48, &CPU::cbopcode49, &CPU::cbopcode4A, &CPU::cbopcode4B,
        &CPU::cbopcode4C, &CPU::cbopcode4D, &CPU::cbopcode4E, &CPU::cbopcode4F,

        &CPU::cbopcode50, &CPU::cbopcode51, &CPU::cbopcode52, &CPU::cbopcode53,
        &CPU::cbopcode54, &CPU::cbopcode55, &CPU::cbopcode56, &CPU::cbopcode57,
        &CPU::cbopcode58, &CPU::cbopcode59, &CPU::cbopcode5A, &CPU::cbopcode5B,
        &CPU::cbopcode5C, &CPU::cbopcode5D, &CPU::cbopcode5E, &CPU::cbopcode5F,

        &CPU::cbopcode60, &CPU::cbopcode61, &CPU::cbopcode62, &CPU::cbopcode63,
        &CPU::cbopcode64, &CPU::cbopcode65, &CPU::cbopcode66, &CPU::cbopcode67,
        &CPU::cbopcode68, &CPU::cbopcode69, &CPU::cbopcode6A, &CPU::cbopcode6B,
        &CPU::cbopcode6C, &CPU::cbopcode6D, &CPU::cbopcode6E, &CPU::cbopcode6F,

        &CPU::cbopcode70, &CPU::cbopcode71, &CPU::cbopcode72, &CPU::cbopcode73,
        &CPU::cbopcode74, &CPU::cbopcode75, &CPU::cbopcode76, &CPU::cbopcode77,
        &CPU::cbopcode78, &CPU::cbopcode79, &CPU::cbopcode7A, &CPU::cbopcode7B,
        &CPU::cbopcode7C, &CPU::cbopcode7D, &CPU::cbopcode7E, &CPU::cbopcode7F,

        &CPU::cbopcode80, &CPU::cbopcode81, &CPU::cbopcode82, &CPU::cbopcode83,
        &CPU::cbopcode84, &CPU::cbopcode85, &CPU::cbopcode86, &CPU::cbopcode87,
        &CPU::cbopcode88, &CPU::cbopcode89, &CPU::cbopcode8A, &CPU::cbopcode8B,
        &CPU::cbopcode8C, &CPU::cbopcode8D, &CPU::cbopcode8E, &CPU::cbopcode8F,

        &CPU::cbopcode90, &CPU::cbopcode91, &CPU::cbopcode92, &CPU::cbopcode93,
        &CPU::cbopcode94, &CPU::cbopcode95, &CPU::cbopcode96, &CPU::cbopcode97,
        &CPU::cbopcode98, &CPU::cbopcode99, &CPU::cbopcode9A, &CPU::cbopcode9B,
        &CPU::cbopcode9C, &CPU::cbopcode9D, &CPU::cbopcode9E, &CPU::cbopcode9F,

        &CPU::cbopcodeA0, &CPU::cbopcodeA1, &CPU::cbopcodeA2, &CPU::cbopcodeA3,
        &CPU::cbopcodeA4, &CPU::cbopcodeA5, &CPU::cbopcodeA6, &CPU::cbopcodeA7,
        &CPU::cbopcodeA8, &CPU::cbopcodeA9, &CPU::cbopcodeAA, &CPU::cbopcodeAB,
        &CPU::cbopcodeAC, &CPU::cbopcodeAD, &CPU::cbopcodeAE, &CPU::cbopcodeAF,

        &CPU::cbopcodeB0, &CPU::cbopcodeB1, &CPU::cbopcodeB2, &CPU::cbopcodeB3,
        &CPU::cbopcodeB4, &CPU::cbopcodeB5, &CPU::cbopcodeB6, &CPU::cbopcodeB7,
        &CPU::cbopcodeB8, &CPU::cbopcodeB9, &CPU::cbopcodeBA, &CPU::cbopcodeBB,
        &CPU::cbopcodeBC, &CPU::cbopcodeBD, &CPU::cbopcodeBE, &CPU::cbopcodeBF,

        &CPU::cbopcodeC0, &CPU::cbopcodeC1, &CPU::cbopcodeC2, &CPU::cbopcodeC3,
        &CPU::cbopcodeC4, &CPU::cbopcodeC5, &CPU::cbopcodeC6, &CPU::cbopcodeC7,
        &CPU::cbopcodeC8, &CPU::cbopcodeC9, &CPU::cbopcodeCA, &CPU::cbopcodeCB,
        &CPU::cbopcodeCC, &CPU::cbopcodeCD, &CPU::cbopcodeCE, &CPU::cbopcodeCF,

        &CPU::cbopcodeD0, &CPU::cbopcodeD1, &CPU::cbopcodeD2, &CPU::cbopcodeD3,
        &CPU::cbopcodeD4, &CPU::cbopcodeD5, &CPU::cbopcodeD6, &CPU::cbopcodeD7,
        &CPU::cbopcodeD8, &CPU::cbopcodeD9, &CPU::cbopcodeDA, &CPU::cbopcodeDB,
        &CPU::cbopcodeDC, &CPU::cbopcodeDD, &CPU::cbopcodeDE, &CPU::cbopcodeDF,

        &CPU::cbopcodeE0, &CPU::cbopcodeE1, &CPU::cbopcodeE2, &CPU::cbopcodeE3,
        &CPU::cbopcodeE4, &CPU::cbopcodeE5, &CPU::cbopcodeE6, &CPU::cbopcodeE7,
        &CPU::cbopcodeE8, &CPU::cbopcodeE9, &CPU::cbopcodeEA, &CPU::cbopcodeEB,
        &CPU::cbopcodeEC, &CPU::cbopcodeED, &CPU::cbopcodeEE, &CPU::cbopcodeEF,

        &CPU::cbopcodeF0, &CPU::cbopcodeF1, &CPU::cbopcodeF2, &CPU::cbopcodeF3,
        &CPU::cbopcodeF4, &CPU::cbopcodeF5, &CPU::cbopcodeF6, &CPU::cbopcodeF7,
        &CPU::cbopcodeF8, &CPU::cbopcodeF9, &CPU::cbopcodeFA, &CPU::cbopcodeFB,
        &CPU::cbopcodeFC, &CPU::cbopcodeFD, &CPU::cbopcodeFE, &CPU::cbopcodeFF};
};