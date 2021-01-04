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

   private:
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

    MMU& mmu;

    void UnimplementedOpcode() { std::cout << "Opcode is unimplemented.\n"; }

    // Beware below, I didn't want to turn off my auto-formatter

    void Opcode00();
    void Opcode01();
    void Opcode02();
    void Opcode03();
    void Opcode04();
    void Opcode05();
    void Opcode06();
    void Opcode07();
    void Opcode08();
    void Opcode09();
    void Opcode0A();
    void Opcode0B();
    void Opcode0C();
    void Opcode0D();
    void Opcode0E();
    void Opcode0F();

    void Opcode10();
    void Opcode11();
    void Opcode12();
    void Opcode13();
    void Opcode14();
    void Opcode15();
    void Opcode16();
    void Opcode17();
    void Opcode18();
    void Opcode19();
    void Opcode1A();
    void Opcode1B();
    void Opcode1C();
    void Opcode1D();
    void Opcode1E();
    void Opcode1F();

    void Opcode20();
    void Opcode21();
    void Opcode22();
    void Opcode23();
    void Opcode24();
    void Opcode25();
    void Opcode26();
    void Opcode27();
    void Opcode28();
    void Opcode29();
    void Opcode2A();
    void Opcode2B();
    void Opcode2C();
    void Opcode2D();
    void Opcode2E();
    void Opcode2F();

    void Opcode30();
    void Opcode31();
    void Opcode32();
    void Opcode33();
    void Opcode34();
    void Opcode35();
    void Opcode36();
    void Opcode37();
    void Opcode38();
    void Opcode39();
    void Opcode3A();
    void Opcode3B();
    void Opcode3C();
    void Opcode3D();
    void Opcode3E();
    void Opcode3F();

    void Opcode40();
    void Opcode41();
    void Opcode42();
    void Opcode43();
    void Opcode44();
    void Opcode45();
    void Opcode46();
    void Opcode47();
    void Opcode48();
    void Opcode49();
    void Opcode4A();
    void Opcode4B();
    void Opcode4C();
    void Opcode4D();
    void Opcode4E();
    void Opcode4F();

    void Opcode50();
    void Opcode51();
    void Opcode52();
    void Opcode53();
    void Opcode54();
    void Opcode55();
    void Opcode56();
    void Opcode57();
    void Opcode58();
    void Opcode59();
    void Opcode5A();
    void Opcode5B();
    void Opcode5C();
    void Opcode5D();
    void Opcode5E();
    void Opcode5F();

    void Opcode60();
    void Opcode61();
    void Opcode62();
    void Opcode63();
    void Opcode64();
    void Opcode65();
    void Opcode66();
    void Opcode67();
    void Opcode68();
    void Opcode69();
    void Opcode6A();
    void Opcode6B();
    void Opcode6C();
    void Opcode6D();
    void Opcode6E();
    void Opcode6F();

    void Opcode70();
    void Opcode71();
    void Opcode72();
    void Opcode73();
    void Opcode74();
    void Opcode75();
    void Opcode76();
    void Opcode77();
    void Opcode78();
    void Opcode79();
    void Opcode7A();
    void Opcode7B();
    void Opcode7C();
    void Opcode7D();
    void Opcode7E();
    void Opcode7F();

    void Opcode80();
    void Opcode81();
    void Opcode82();
    void Opcode83();
    void Opcode84();
    void Opcode85();
    void Opcode86();
    void Opcode87();
    void Opcode88();
    void Opcode89();
    void Opcode8A();
    void Opcode8B();
    void Opcode8C();
    void Opcode8D();
    void Opcode8E();
    void Opcode8F();

    void Opcode90();
    void Opcode91();
    void Opcode92();
    void Opcode93();
    void Opcode94();
    void Opcode95();
    void Opcode96();
    void Opcode97();
    void Opcode98();
    void Opcode99();
    void Opcode9A();
    void Opcode9B();
    void Opcode9C();
    void Opcode9D();
    void Opcode9E();
    void Opcode9F();

    void OpcodeA0();
    void OpcodeA1();
    void OpcodeA2();
    void OpcodeA3();
    void OpcodeA4();
    void OpcodeA5();
    void OpcodeA6();
    void OpcodeA7();
    void OpcodeA8();
    void OpcodeA9();
    void OpcodeAA();
    void OpcodeAB();
    void OpcodeAC();
    void OpcodeAD();
    void OpcodeAE();
    void OpcodeAF();

    void OpcodeB0();
    void OpcodeB1();
    void OpcodeB2();
    void OpcodeB3();
    void OpcodeB4();
    void OpcodeB5();
    void OpcodeB6();
    void OpcodeB7();
    void OpcodeB8();
    void OpcodeB9();
    void OpcodeBA();
    void OpcodeBB();
    void OpcodeBC();
    void OpcodeBD();
    void OpcodeBE();
    void OpcodeBF();

    void OpcodeC0();
    void OpcodeC1();
    void OpcodeC2();
    void OpcodeC3();
    void OpcodeC4();
    void OpcodeC5();
    void OpcodeC6();
    void OpcodeC7();
    void OpcodeC8();
    void OpcodeC9();
    void OpcodeCA();
    void OpcodeCB();
    void OpcodeCC();
    void OpcodeCD();
    void OpcodeCE();
    void OpcodeCF();

    void OpcodeD0();
    void OpcodeD1();
    void OpcodeD2();
    void OpcodeD3();
    void OpcodeD4();
    void OpcodeD5();
    void OpcodeD6();
    void OpcodeD7();
    void OpcodeD8();
    void OpcodeD9();
    void OpcodeDA();
    void OpcodeDB();
    void OpcodeDC();
    void OpcodeDD();
    void OpcodeDE();
    void OpcodeDF();

    void OpcodeE0();
    void OpcodeE1();
    void OpcodeE2();
    void OpcodeE3();
    void OpcodeE4();
    void OpcodeE5();
    void OpcodeE6();
    void OpcodeE7();
    void OpcodeE8();
    void OpcodeE9();
    void OpcodeEA();
    void OpcodeEB();
    void OpcodeEC();
    void OpcodeED();
    void OpcodeEE();
    void OpcodeEF();

    void OpcodeF0();
    void OpcodeF1();
    void OpcodeF2();
    void OpcodeF3();
    void OpcodeF4();
    void OpcodeF5();
    void OpcodeF6();
    void OpcodeF7();
    void OpcodeF8();
    void OpcodeF9();
    void OpcodeFA();
    void OpcodeFB();
    void OpcodeFC();
    void OpcodeFD();
    void OpcodeFE();
    void OpcodeFF();

    void CbOpcode00();
    void CbOpcode01();
    void CbOpcode02();
    void CbOpcode03();
    void CbOpcode04();
    void CbOpcode05();
    void CbOpcode06();
    void CbOpcode07();
    void CbOpcode08();
    void CbOpcode09();
    void CbOpcode0A();
    void CbOpcode0B();
    void CbOpcode0C();
    void CbOpcode0D();
    void CbOpcode0E();
    void CbOpcode0F();

    void CbOpcode10();
    void CbOpcode11();
    void CbOpcode12();
    void CbOpcode13();
    void CbOpcode14();
    void CbOpcode15();
    void CbOpcode16();
    void CbOpcode17();
    void CbOpcode18();
    void CbOpcode19();
    void CbOpcode1A();
    void CbOpcode1B();
    void CbOpcode1C();
    void CbOpcode1D();
    void CbOpcode1E();
    void CbOpcode1F();

    void CbOpcode20();
    void CbOpcode21();
    void CbOpcode22();
    void CbOpcode23();
    void CbOpcode24();
    void CbOpcode25();
    void CbOpcode26();
    void CbOpcode27();
    void CbOpcode28();
    void CbOpcode29();
    void CbOpcode2A();
    void CbOpcode2B();
    void CbOpcode2C();
    void CbOpcode2D();
    void CbOpcode2E();
    void CbOpcode2F();

    void CbOpcode30();
    void CbOpcode31();
    void CbOpcode32();
    void CbOpcode33();
    void CbOpcode34();
    void CbOpcode35();
    void CbOpcode36();
    void CbOpcode37();
    void CbOpcode38();
    void CbOpcode39();
    void CbOpcode3A();
    void CbOpcode3B();
    void CbOpcode3C();
    void CbOpcode3D();
    void CbOpcode3E();
    void CbOpcode3F();

    void CbOpcode40();
    void CbOpcode41();
    void CbOpcode42();
    void CbOpcode43();
    void CbOpcode44();
    void CbOpcode45();
    void CbOpcode46();
    void CbOpcode47();
    void CbOpcode48();
    void CbOpcode49();
    void CbOpcode4A();
    void CbOpcode4B();
    void CbOpcode4C();
    void CbOpcode4D();
    void CbOpcode4E();
    void CbOpcode4F();

    void CbOpcode50();
    void CbOpcode51();
    void CbOpcode52();
    void CbOpcode53();
    void CbOpcode54();
    void CbOpcode55();
    void CbOpcode56();
    void CbOpcode57();
    void CbOpcode58();
    void CbOpcode59();
    void CbOpcode5A();
    void CbOpcode5B();
    void CbOpcode5C();
    void CbOpcode5D();
    void CbOpcode5E();
    void CbOpcode5F();

    void CbOpcode60();
    void CbOpcode61();
    void CbOpcode62();
    void CbOpcode63();
    void CbOpcode64();
    void CbOpcode65();
    void CbOpcode66();
    void CbOpcode67();
    void CbOpcode68();
    void CbOpcode69();
    void CbOpcode6A();
    void CbOpcode6B();
    void CbOpcode6C();
    void CbOpcode6D();
    void CbOpcode6E();
    void CbOpcode6F();

    void CbOpcode70();
    void CbOpcode71();
    void CbOpcode72();
    void CbOpcode73();
    void CbOpcode74();
    void CbOpcode75();
    void CbOpcode76();
    void CbOpcode77();
    void CbOpcode78();
    void CbOpcode79();
    void CbOpcode7A();
    void CbOpcode7B();
    void CbOpcode7C();
    void CbOpcode7D();
    void CbOpcode7E();
    void CbOpcode7F();

    void CbOpcode80();
    void CbOpcode81();
    void CbOpcode82();
    void CbOpcode83();
    void CbOpcode84();
    void CbOpcode85();
    void CbOpcode86();
    void CbOpcode87();
    void CbOpcode88();
    void CbOpcode89();
    void CbOpcode8A();
    void CbOpcode8B();
    void CbOpcode8C();
    void CbOpcode8D();
    void CbOpcode8E();
    void CbOpcode8F();

    void CbOpcode90();
    void CbOpcode91();
    void CbOpcode92();
    void CbOpcode93();
    void CbOpcode94();
    void CbOpcode95();
    void CbOpcode96();
    void CbOpcode97();
    void CbOpcode98();
    void CbOpcode99();
    void CbOpcode9A();
    void CbOpcode9B();
    void CbOpcode9C();
    void CbOpcode9D();
    void CbOpcode9E();
    void CbOpcode9F();

    void CbOpcodeA0();
    void CbOpcodeA1();
    void CbOpcodeA2();
    void CbOpcodeA3();
    void CbOpcodeA4();
    void CbOpcodeA5();
    void CbOpcodeA6();
    void CbOpcodeA7();
    void CbOpcodeA8();
    void CbOpcodeA9();
    void CbOpcodeAA();
    void CbOpcodeAB();
    void CbOpcodeAC();
    void CbOpcodeAD();
    void CbOpcodeAE();
    void CbOpcodeAF();

    void CbOpcodeB0();
    void CbOpcodeB1();
    void CbOpcodeB2();
    void CbOpcodeB3();
    void CbOpcodeB4();
    void CbOpcodeB5();
    void CbOpcodeB6();
    void CbOpcodeB7();
    void CbOpcodeB8();
    void CbOpcodeB9();
    void CbOpcodeBA();
    void CbOpcodeBB();
    void CbOpcodeBC();
    void CbOpcodeBD();
    void CbOpcodeBE();
    void CbOpcodeBF();

    void CbOpcodeC0();
    void CbOpcodeC1();
    void CbOpcodeC2();
    void CbOpcodeC3();
    void CbOpcodeC4();
    void CbOpcodeC5();
    void CbOpcodeC6();
    void CbOpcodeC7();
    void CbOpcodeC8();
    void CbOpcodeC9();
    void CbOpcodeCA();
    void CbOpcodeCB();
    void CbOpcodeCC();
    void CbOpcodeCD();
    void CbOpcodeCE();
    void CbOpcodeCF();

    void CbOpcodeD0();
    void CbOpcodeD1();
    void CbOpcodeD2();
    void CbOpcodeD3();
    void CbOpcodeD4();
    void CbOpcodeD5();
    void CbOpcodeD6();
    void CbOpcodeD7();
    void CbOpcodeD8();
    void CbOpcodeD9();
    void CbOpcodeDA();
    void CbOpcodeDB();
    void CbOpcodeDC();
    void CbOpcodeDD();
    void CbOpcodeDE();
    void CbOpcodeDF();

    void CbOpcodeE0();
    void CbOpcodeE1();
    void CbOpcodeE2();
    void CbOpcodeE3();
    void CbOpcodeE4();
    void CbOpcodeE5();
    void CbOpcodeE6();
    void CbOpcodeE7();
    void CbOpcodeE8();
    void CbOpcodeE9();
    void CbOpcodeEA();
    void CbOpcodeEB();
    void CbOpcodeEC();
    void CbOpcodeED();
    void CbOpcodeEE();
    void CbOpcodeEF();

    void CbOpcodeF0();
    void CbOpcodeF1();
    void CbOpcodeF2();
    void CbOpcodeF3();
    void CbOpcodeF4();
    void CbOpcodeF5();
    void CbOpcodeF6();
    void CbOpcodeF7();
    void CbOpcodeF8();
    void CbOpcodeF9();
    void CbOpcodeFA();
    void CbOpcodeFB();
    void CbOpcodeFC();
    void CbOpcodeFD();
    void CbOpcodeFE();
    void CbOpcodeFF();

    const CPUFn opcodes[256] = {
        &CPU::Opcode00, &CPU::Opcode01, &CPU::Opcode02, &CPU::Opcode03,
        &CPU::Opcode04, &CPU::Opcode05, &CPU::Opcode06, &CPU::Opcode07,
        &CPU::Opcode08, &CPU::Opcode09, &CPU::Opcode0A, &CPU::Opcode0B,
        &CPU::Opcode0C, &CPU::Opcode0D, &CPU::Opcode0E, &CPU::Opcode0F,

        &CPU::Opcode10, &CPU::Opcode11, &CPU::Opcode12, &CPU::Opcode13,
        &CPU::Opcode14, &CPU::Opcode15, &CPU::Opcode16, &CPU::Opcode17,
        &CPU::Opcode18, &CPU::Opcode19, &CPU::Opcode1A, &CPU::Opcode1B,
        &CPU::Opcode1C, &CPU::Opcode1D, &CPU::Opcode1E, &CPU::Opcode1F,

        &CPU::Opcode20, &CPU::Opcode21, &CPU::Opcode22, &CPU::Opcode23,
        &CPU::Opcode24, &CPU::Opcode25, &CPU::Opcode26, &CPU::Opcode27,
        &CPU::Opcode28, &CPU::Opcode29, &CPU::Opcode2A, &CPU::Opcode2B,
        &CPU::Opcode2C, &CPU::Opcode2D, &CPU::Opcode2E, &CPU::Opcode2F,

        &CPU::Opcode30, &CPU::Opcode31, &CPU::Opcode32, &CPU::Opcode33,
        &CPU::Opcode34, &CPU::Opcode35, &CPU::Opcode36, &CPU::Opcode37,
        &CPU::Opcode38, &CPU::Opcode39, &CPU::Opcode3A, &CPU::Opcode3B,
        &CPU::Opcode3C, &CPU::Opcode3D, &CPU::Opcode3E, &CPU::Opcode3F,

        &CPU::Opcode40, &CPU::Opcode41, &CPU::Opcode42, &CPU::Opcode43,
        &CPU::Opcode44, &CPU::Opcode45, &CPU::Opcode46, &CPU::Opcode47,
        &CPU::Opcode48, &CPU::Opcode49, &CPU::Opcode4A, &CPU::Opcode4B,
        &CPU::Opcode4C, &CPU::Opcode4D, &CPU::Opcode4E, &CPU::Opcode4F,

        &CPU::Opcode50, &CPU::Opcode51, &CPU::Opcode52, &CPU::Opcode53,
        &CPU::Opcode54, &CPU::Opcode55, &CPU::Opcode56, &CPU::Opcode57,
        &CPU::Opcode58, &CPU::Opcode59, &CPU::Opcode5A, &CPU::Opcode5B,
        &CPU::Opcode5C, &CPU::Opcode5D, &CPU::Opcode5E, &CPU::Opcode5F,

        &CPU::Opcode60, &CPU::Opcode61, &CPU::Opcode62, &CPU::Opcode63,
        &CPU::Opcode64, &CPU::Opcode65, &CPU::Opcode66, &CPU::Opcode67,
        &CPU::Opcode68, &CPU::Opcode69, &CPU::Opcode6A, &CPU::Opcode6B,
        &CPU::Opcode6C, &CPU::Opcode6D, &CPU::Opcode6E, &CPU::Opcode6F,

        &CPU::Opcode70, &CPU::Opcode71, &CPU::Opcode72, &CPU::Opcode73,
        &CPU::Opcode74, &CPU::Opcode75, &CPU::Opcode76, &CPU::Opcode77,
        &CPU::Opcode78, &CPU::Opcode79, &CPU::Opcode7A, &CPU::Opcode7B,
        &CPU::Opcode7C, &CPU::Opcode7D, &CPU::Opcode7E, &CPU::Opcode7F,

        &CPU::Opcode80, &CPU::Opcode81, &CPU::Opcode82, &CPU::Opcode83,
        &CPU::Opcode84, &CPU::Opcode85, &CPU::Opcode86, &CPU::Opcode87,
        &CPU::Opcode88, &CPU::Opcode89, &CPU::Opcode8A, &CPU::Opcode8B,
        &CPU::Opcode8C, &CPU::Opcode8D, &CPU::Opcode8E, &CPU::Opcode8F,

        &CPU::Opcode90, &CPU::Opcode91, &CPU::Opcode92, &CPU::Opcode93,
        &CPU::Opcode94, &CPU::Opcode95, &CPU::Opcode96, &CPU::Opcode97,
        &CPU::Opcode98, &CPU::Opcode99, &CPU::Opcode9A, &CPU::Opcode9B,
        &CPU::Opcode9C, &CPU::Opcode9D, &CPU::Opcode9E, &CPU::Opcode9F,

        &CPU::OpcodeA0, &CPU::OpcodeA1, &CPU::OpcodeA2, &CPU::OpcodeA3,
        &CPU::OpcodeA4, &CPU::OpcodeA5, &CPU::OpcodeA6, &CPU::OpcodeA7,
        &CPU::OpcodeA8, &CPU::OpcodeA9, &CPU::OpcodeAA, &CPU::OpcodeAB,
        &CPU::OpcodeAC, &CPU::OpcodeAD, &CPU::OpcodeAE, &CPU::OpcodeAF,

        &CPU::OpcodeB0, &CPU::OpcodeB1, &CPU::OpcodeB2, &CPU::OpcodeB3,
        &CPU::OpcodeB4, &CPU::OpcodeB5, &CPU::OpcodeB6, &CPU::OpcodeB7,
        &CPU::OpcodeB8, &CPU::OpcodeB9, &CPU::OpcodeBA, &CPU::OpcodeBB,
        &CPU::OpcodeBC, &CPU::OpcodeBD, &CPU::OpcodeBE, &CPU::OpcodeBF,

        &CPU::OpcodeC0, &CPU::OpcodeC1, &CPU::OpcodeC2, &CPU::OpcodeC3,
        &CPU::OpcodeC4, &CPU::OpcodeC5, &CPU::OpcodeC6, &CPU::OpcodeC7,
        &CPU::OpcodeC8, &CPU::OpcodeC9, &CPU::OpcodeCA, &CPU::OpcodeCB,
        &CPU::OpcodeCC, &CPU::OpcodeCD, &CPU::OpcodeCE, &CPU::OpcodeCF,

        &CPU::OpcodeD0, &CPU::OpcodeD1, &CPU::OpcodeD2, &CPU::OpcodeD3,
        &CPU::OpcodeD4, &CPU::OpcodeD5, &CPU::OpcodeD6, &CPU::OpcodeD7,
        &CPU::OpcodeD8, &CPU::OpcodeD9, &CPU::OpcodeDA, &CPU::OpcodeDB,
        &CPU::OpcodeDC, &CPU::OpcodeDD, &CPU::OpcodeDE, &CPU::OpcodeDF,

        &CPU::OpcodeE0, &CPU::OpcodeE1, &CPU::OpcodeE2, &CPU::OpcodeE3,
        &CPU::OpcodeE4, &CPU::OpcodeE5, &CPU::OpcodeE6, &CPU::OpcodeE7,
        &CPU::OpcodeE8, &CPU::OpcodeE9, &CPU::OpcodeEA, &CPU::OpcodeEB,
        &CPU::OpcodeEC, &CPU::OpcodeED, &CPU::OpcodeEE, &CPU::OpcodeEF,

        &CPU::OpcodeF0, &CPU::OpcodeF1, &CPU::OpcodeF2, &CPU::OpcodeF3,
        &CPU::OpcodeF4, &CPU::OpcodeF5, &CPU::OpcodeF6, &CPU::OpcodeF7,
        &CPU::OpcodeF8, &CPU::OpcodeF9, &CPU::OpcodeFA, &CPU::OpcodeFB,
        &CPU::OpcodeFC, &CPU::OpcodeFD, &CPU::OpcodeFE, &CPU::OpcodeFF};
    const CPUFn cb_opcodes[256] = {
        &CPU::CbOpcode00, &CPU::CbOpcode01, &CPU::CbOpcode02, &CPU::CbOpcode03,
        &CPU::CbOpcode04, &CPU::CbOpcode05, &CPU::CbOpcode06, &CPU::CbOpcode07,
        &CPU::CbOpcode08, &CPU::CbOpcode09, &CPU::CbOpcode0A, &CPU::CbOpcode0B,
        &CPU::CbOpcode0C, &CPU::CbOpcode0D, &CPU::CbOpcode0E, &CPU::CbOpcode0F,

        &CPU::CbOpcode10, &CPU::CbOpcode11, &CPU::CbOpcode12, &CPU::CbOpcode13,
        &CPU::CbOpcode14, &CPU::CbOpcode15, &CPU::CbOpcode16, &CPU::CbOpcode17,
        &CPU::CbOpcode18, &CPU::CbOpcode19, &CPU::CbOpcode1A, &CPU::CbOpcode1B,
        &CPU::CbOpcode1C, &CPU::CbOpcode1D, &CPU::CbOpcode1E, &CPU::CbOpcode1F,

        &CPU::CbOpcode20, &CPU::CbOpcode21, &CPU::CbOpcode22, &CPU::CbOpcode23,
        &CPU::CbOpcode24, &CPU::CbOpcode25, &CPU::CbOpcode26, &CPU::CbOpcode27,
        &CPU::CbOpcode28, &CPU::CbOpcode29, &CPU::CbOpcode2A, &CPU::CbOpcode2B,
        &CPU::CbOpcode2C, &CPU::CbOpcode2D, &CPU::CbOpcode2E, &CPU::CbOpcode2F,

        &CPU::CbOpcode30, &CPU::CbOpcode31, &CPU::CbOpcode32, &CPU::CbOpcode33,
        &CPU::CbOpcode34, &CPU::CbOpcode35, &CPU::CbOpcode36, &CPU::CbOpcode37,
        &CPU::CbOpcode38, &CPU::CbOpcode39, &CPU::CbOpcode3A, &CPU::CbOpcode3B,
        &CPU::CbOpcode3C, &CPU::CbOpcode3D, &CPU::CbOpcode3E, &CPU::CbOpcode3F,

        &CPU::CbOpcode40, &CPU::CbOpcode41, &CPU::CbOpcode42, &CPU::CbOpcode43,
        &CPU::CbOpcode44, &CPU::CbOpcode45, &CPU::CbOpcode46, &CPU::CbOpcode47,
        &CPU::CbOpcode48, &CPU::CbOpcode49, &CPU::CbOpcode4A, &CPU::CbOpcode4B,
        &CPU::CbOpcode4C, &CPU::CbOpcode4D, &CPU::CbOpcode4E, &CPU::CbOpcode4F,

        &CPU::CbOpcode50, &CPU::CbOpcode51, &CPU::CbOpcode52, &CPU::CbOpcode53,
        &CPU::CbOpcode54, &CPU::CbOpcode55, &CPU::CbOpcode56, &CPU::CbOpcode57,
        &CPU::CbOpcode58, &CPU::CbOpcode59, &CPU::CbOpcode5A, &CPU::CbOpcode5B,
        &CPU::CbOpcode5C, &CPU::CbOpcode5D, &CPU::CbOpcode5E, &CPU::CbOpcode5F,

        &CPU::CbOpcode60, &CPU::CbOpcode61, &CPU::CbOpcode62, &CPU::CbOpcode63,
        &CPU::CbOpcode64, &CPU::CbOpcode65, &CPU::CbOpcode66, &CPU::CbOpcode67,
        &CPU::CbOpcode68, &CPU::CbOpcode69, &CPU::CbOpcode6A, &CPU::CbOpcode6B,
        &CPU::CbOpcode6C, &CPU::CbOpcode6D, &CPU::CbOpcode6E, &CPU::CbOpcode6F,

        &CPU::CbOpcode70, &CPU::CbOpcode71, &CPU::CbOpcode72, &CPU::CbOpcode73,
        &CPU::CbOpcode74, &CPU::CbOpcode75, &CPU::CbOpcode76, &CPU::CbOpcode77,
        &CPU::CbOpcode78, &CPU::CbOpcode79, &CPU::CbOpcode7A, &CPU::CbOpcode7B,
        &CPU::CbOpcode7C, &CPU::CbOpcode7D, &CPU::CbOpcode7E, &CPU::CbOpcode7F,

        &CPU::CbOpcode80, &CPU::CbOpcode81, &CPU::CbOpcode82, &CPU::CbOpcode83,
        &CPU::CbOpcode84, &CPU::CbOpcode85, &CPU::CbOpcode86, &CPU::CbOpcode87,
        &CPU::CbOpcode88, &CPU::CbOpcode89, &CPU::CbOpcode8A, &CPU::CbOpcode8B,
        &CPU::CbOpcode8C, &CPU::CbOpcode8D, &CPU::CbOpcode8E, &CPU::CbOpcode8F,

        &CPU::CbOpcode90, &CPU::CbOpcode91, &CPU::CbOpcode92, &CPU::CbOpcode93,
        &CPU::CbOpcode94, &CPU::CbOpcode95, &CPU::CbOpcode96, &CPU::CbOpcode97,
        &CPU::CbOpcode98, &CPU::CbOpcode99, &CPU::CbOpcode9A, &CPU::CbOpcode9B,
        &CPU::CbOpcode9C, &CPU::CbOpcode9D, &CPU::CbOpcode9E, &CPU::CbOpcode9F,

        &CPU::CbOpcodeA0, &CPU::CbOpcodeA1, &CPU::CbOpcodeA2, &CPU::CbOpcodeA3,
        &CPU::CbOpcodeA4, &CPU::CbOpcodeA5, &CPU::CbOpcodeA6, &CPU::CbOpcodeA7,
        &CPU::CbOpcodeA8, &CPU::CbOpcodeA9, &CPU::CbOpcodeAA, &CPU::CbOpcodeAB,
        &CPU::CbOpcodeAC, &CPU::CbOpcodeAD, &CPU::CbOpcodeAE, &CPU::CbOpcodeAF,

        &CPU::CbOpcodeB0, &CPU::CbOpcodeB1, &CPU::CbOpcodeB2, &CPU::CbOpcodeB3,
        &CPU::CbOpcodeB4, &CPU::CbOpcodeB5, &CPU::CbOpcodeB6, &CPU::CbOpcodeB7,
        &CPU::CbOpcodeB8, &CPU::CbOpcodeB9, &CPU::CbOpcodeBA, &CPU::CbOpcodeBB,
        &CPU::CbOpcodeBC, &CPU::CbOpcodeBD, &CPU::CbOpcodeBE, &CPU::CbOpcodeBF,

        &CPU::CbOpcodeC0, &CPU::CbOpcodeC1, &CPU::CbOpcodeC2, &CPU::CbOpcodeC3,
        &CPU::CbOpcodeC4, &CPU::CbOpcodeC5, &CPU::CbOpcodeC6, &CPU::CbOpcodeC7,
        &CPU::CbOpcodeC8, &CPU::CbOpcodeC9, &CPU::CbOpcodeCA, &CPU::CbOpcodeCB,
        &CPU::CbOpcodeCC, &CPU::CbOpcodeCD, &CPU::CbOpcodeCE, &CPU::CbOpcodeCF,

        &CPU::CbOpcodeD0, &CPU::CbOpcodeD1, &CPU::CbOpcodeD2, &CPU::CbOpcodeD3,
        &CPU::CbOpcodeD4, &CPU::CbOpcodeD5, &CPU::CbOpcodeD6, &CPU::CbOpcodeD7,
        &CPU::CbOpcodeD8, &CPU::CbOpcodeD9, &CPU::CbOpcodeDA, &CPU::CbOpcodeDB,
        &CPU::CbOpcodeDC, &CPU::CbOpcodeDD, &CPU::CbOpcodeDE, &CPU::CbOpcodeDF,

        &CPU::CbOpcodeE0, &CPU::CbOpcodeE1, &CPU::CbOpcodeE2, &CPU::CbOpcodeE3,
        &CPU::CbOpcodeE4, &CPU::CbOpcodeE5, &CPU::CbOpcodeE6, &CPU::CbOpcodeE7,
        &CPU::CbOpcodeE8, &CPU::CbOpcodeE9, &CPU::CbOpcodeEA, &CPU::CbOpcodeEB,
        &CPU::CbOpcodeEC, &CPU::CbOpcodeED, &CPU::CbOpcodeEE, &CPU::CbOpcodeEF,

        &CPU::CbOpcodeF0, &CPU::CbOpcodeF1, &CPU::CbOpcodeF2, &CPU::CbOpcodeF3,
        &CPU::CbOpcodeF4, &CPU::CbOpcodeF5, &CPU::CbOpcodeF6, &CPU::CbOpcodeF7,
        &CPU::CbOpcodeF8, &CPU::CbOpcodeF9, &CPU::CbOpcodeFA, &CPU::CbOpcodeFB,
        &CPU::CbOpcodeFC, &CPU::CbOpcodeFD, &CPU::CbOpcodeFE, &CPU::CbOpcodeFF};
};