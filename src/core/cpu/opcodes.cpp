#include "cpu.h"
#include "spdlog/spdlog.h"

void CPU::opcode00() { spdlog::debug("Nop instruction"); }
void CPU::opcode01() { ld(bc); }
void CPU::opcode02() { ld(bc, a); }
void CPU::opcode03() { inc(bc); }
void CPU::opcode04() { inc(b); }
void CPU::opcode05() { dec(b); }
void CPU::opcode06() { ld(b); }
void CPU::opcode07() { rlca(); }
void CPU::opcode08() { ld_sp(sp); }
void CPU::opcode09() { add(hl, bc); }
void CPU::opcode0A() { ld(a, bc); }
void CPU::opcode0B() { dec(bc); }
void CPU::opcode0C() { inc(c); }
void CPU::opcode0D() { dec(c); }
void CPU::opcode0E() { ld(c); }
void CPU::opcode0F() { rrca(); }

void CPU::opcode10() { stop(); }
void CPU::opcode11() { ld(de); }
void CPU::opcode12() { ld(de, a); }
void CPU::opcode13() { inc(de); }
void CPU::opcode14() { inc(d); }
void CPU::opcode15() { dec(d); }
void CPU::opcode16() { ld(d); }
void CPU::opcode17() { rla(); }
void CPU::opcode18() { jr(); }
void CPU::opcode19() { add(hl, de); }
void CPU::opcode1A() { ld(a, de); }
void CPU::opcode1B() { dec(de); }
void CPU::opcode1C() { inc(e); }
void CPU::opcode1D() { dec(e); }
void CPU::opcode1E() { ld(e); }
void CPU::opcode1F() { rra(); }

void CPU::opcode20() { jr_cond(!f.getZero()); }
void CPU::opcode21() { ld(hl); }
void CPU::opcode22() { ldi(hl, a); }
void CPU::opcode23() { inc(hl); }
void CPU::opcode24() { inc(h); }
void CPU::opcode25() { dec(h); }
void CPU::opcode26() { ld(h); }
void CPU::opcode27() { daa(); }
void CPU::opcode28() { jr_cond(f.getZero()); }
void CPU::opcode29() { add(hl, hl); }
void CPU::opcode2A() { ldi(a, hl); }
void CPU::opcode2B() { dec(hl); }
void CPU::opcode2C() { inc(l); }
void CPU::opcode2D() { dec(l); }
void CPU::opcode2E() { ld(l); }
void CPU::opcode2F() { cpl(); }

void CPU::opcode30() { jr_cond(!f.getCarry()); }
void CPU::opcode31() { ld(sp); }
void CPU::opcode32() { ldd(hl, a); }
void CPU::opcode33() { inc(sp); }
void CPU::opcode34() { inc(hl.value()); }
void CPU::opcode35() { dec(hl.value()); }
void CPU::opcode36() { ld(hl); }
void CPU::opcode37() { scf(); }
void CPU::opcode38() { jr_cond(f.getCarry()); }
void CPU::opcode39() { add(hl, sp); }
void CPU::opcode3A() { ldd(a, hl); }
void CPU::opcode3B() { dec(sp); }
void CPU::opcode3C() { inc(a); }
void CPU::opcode3D() { dec(a); }
void CPU::opcode3E() { ld(a); }
void CPU::opcode3F() { ccf(); }

void CPU::opcode40() { ld(b, b); }
void CPU::opcode41() { ld(b, c); }
void CPU::opcode42() { ld(b, d); }
void CPU::opcode43() { ld(b, e); }
void CPU::opcode44() { ld(b, h); }
void CPU::opcode45() { ld(b, l); }
void CPU::opcode46() { ld(b, hl); }
void CPU::opcode47() { ld(b, a); }
void CPU::opcode48() { ld(c, b); }
void CPU::opcode49() { ld(c, c); }
void CPU::opcode4A() { ld(c, d); }
void CPU::opcode4B() { ld(c, e); }
void CPU::opcode4C() { ld(c, h); }
void CPU::opcode4D() { ld(c, l); }
void CPU::opcode4E() { ld(c, hl); }
void CPU::opcode4F() { ld(c, a); }

void CPU::opcode50() { ld(d, b); }
void CPU::opcode51() { ld(d, c); }
void CPU::opcode52() { ld(d, d); }
void CPU::opcode53() { ld(d, e); }
void CPU::opcode54() { ld(d, h); }
void CPU::opcode55() { ld(d, l); }
void CPU::opcode56() { ld(d, hl); }
void CPU::opcode57() { ld(d, a); }
void CPU::opcode58() { ld(e, b); }
void CPU::opcode59() { ld(e, c); }
void CPU::opcode5A() { ld(e, d); }
void CPU::opcode5B() { ld(e, e); }
void CPU::opcode5C() { ld(e, h); }
void CPU::opcode5D() { ld(e, l); }
void CPU::opcode5E() { ld(e, hl); }
void CPU::opcode5F() { ld(e, a); }

void CPU::opcode60() { ld(h, b); }
void CPU::opcode61() { ld(h, c); }
void CPU::opcode62() { ld(h, d); }
void CPU::opcode63() { ld(h, e); }
void CPU::opcode64() { ld(h, h); }
void CPU::opcode65() { ld(h, l); }
void CPU::opcode66() { ld(h, hl); }
void CPU::opcode67() { ld(h, a); }
void CPU::opcode68() { ld(l, b); }
void CPU::opcode69() { ld(l, c); }
void CPU::opcode6A() { ld(l, d); }
void CPU::opcode6B() { ld(l, e); }
void CPU::opcode6C() { ld(l, h); }
void CPU::opcode6D() { ld(l, l); }
void CPU::opcode6E() { ld(l, hl); }
void CPU::opcode6F() { ld(l, a); }

void CPU::opcode70() { ld(hl, b); }
void CPU::opcode71() { ld(hl, c); }
void CPU::opcode72() { ld(hl, d); }
void CPU::opcode73() { ld(hl, e); }
void CPU::opcode74() { ld(hl, h); }
void CPU::opcode75() { ld(hl, l); }
void CPU::opcode76() { halt(); }
void CPU::opcode77() { ld(hl, a); }
void CPU::opcode78() { ld(a, b); }
void CPU::opcode79() { ld(a, c); }
void CPU::opcode7A() { ld(a, d); }
void CPU::opcode7B() { ld(a, e); }
void CPU::opcode7C() { ld(a, h); }
void CPU::opcode7D() { ld(a, l); }
void CPU::opcode7E() { ld(a, hl); }
void CPU::opcode7F() { ld(a, a); }

void CPU::opcode80() { add(a, b); }
void CPU::opcode81() { add(a, c); }
void CPU::opcode82() { add(a, d); }
void CPU::opcode83() { add(a, e); }
void CPU::opcode84() { add(a, h); }
void CPU::opcode85() { add(a, l); }
void CPU::opcode86() { add(a, hl); }
void CPU::opcode87() { add(a, a); }
void CPU::opcode88() { adc(a, b); }
void CPU::opcode89() { adc(a, c); }
void CPU::opcode8A() { adc(a, d); }
void CPU::opcode8B() { adc(a, e); }
void CPU::opcode8C() { adc(a, h); }
void CPU::opcode8D() { adc(a, l); }
void CPU::opcode8E() { adc(a, hl); }
void CPU::opcode8F() { adc(a, a); }

void CPU::opcode90() { sub(a, b); }
void CPU::opcode91() { sub(a, c); }
void CPU::opcode92() { sub(a, d); }
void CPU::opcode93() { sub(a, e); }
void CPU::opcode94() { sub(a, h); }
void CPU::opcode95() { sub(a, l); }
void CPU::opcode96() { sub(a, hl); }
void CPU::opcode97() { sub(a, a); }
void CPU::opcode98() { sbc(a, b); }
void CPU::opcode99() { sbc(a, c); }
void CPU::opcode9A() { sbc(a, d); }
void CPU::opcode9B() { sbc(a, e); }
void CPU::opcode9C() { sbc(a, h); }
void CPU::opcode9D() { sbc(a, l); }
void CPU::opcode9E() { sbc(a, hl); }
void CPU::opcode9F() { sbc(a, a); }

void CPU::opcodeA0() { op_and(a, b); }
void CPU::opcodeA1() { op_and(a, c); }
void CPU::opcodeA2() { op_and(a, d); }
void CPU::opcodeA3() { op_and(a, e); }
void CPU::opcodeA4() { op_and(a, h); }
void CPU::opcodeA5() { op_and(a, l); }
void CPU::opcodeA6() { op_and(a, hl); }
void CPU::opcodeA7() { op_and(a, a); }
void CPU::opcodeA8() { op_xor(a, b); }
void CPU::opcodeA9() { op_xor(a, c); }
void CPU::opcodeAA() { op_xor(a, d); }
void CPU::opcodeAB() { op_xor(a, e); }
void CPU::opcodeAC() { op_xor(a, h); }
void CPU::opcodeAD() { op_xor(a, l); }
void CPU::opcodeAE() { op_xor(a, hl); }
void CPU::opcodeAF() { op_xor(a, a); }

void CPU::opcodeB0() { op_or(a, b); }
void CPU::opcodeB1() { op_or(a, c); }
void CPU::opcodeB2() { op_or(a, d); }
void CPU::opcodeB3() { op_or(a, e); }
void CPU::opcodeB4() { op_or(a, h); }
void CPU::opcodeB5() { op_or(a, l); }
void CPU::opcodeB6() { op_or(a, hl); }
void CPU::opcodeB7() { op_or(a, a); }
void CPU::opcodeB8() { cp(a, b); }
void CPU::opcodeB9() { cp(a, c); }
void CPU::opcodeBA() { cp(a, d); }
void CPU::opcodeBB() { cp(a, e); }
void CPU::opcodeBC() { cp(a, h); }
void CPU::opcodeBD() { cp(a, l); }
void CPU::opcodeBE() { cp(a, hl); }
void CPU::opcodeBF() { cp(a, a); }

void CPU::opcodeC0() { ret(!f.getZero()); }
void CPU::opcodeC1() { pop(bc); }
void CPU::opcodeC2() { jp(!f.getZero()); }
void CPU::opcodeC3() { jp(); }
void CPU::opcodeC4() { call(!f.getZero()); }
void CPU::opcodeC5() { push(bc); }
void CPU::opcodeC6() { add(a); }
void CPU::opcodeC7() { rst(0x00); }
void CPU::opcodeC8() { ret(f.getZero()); }
void CPU::opcodeC9() { ret(); }
void CPU::opcodeCA() { jp(f.getZero()); }
void CPU::opcodeCB() {
    spdlog::error("Recieved CB opcode offset in regular opcode table.");
}
void CPU::opcodeCC() { call(f.getZero()); }
void CPU::opcodeCD() { call(); }
void CPU::opcodeCE() { adc(a); }
void CPU::opcodeCF() { rst(0x08); }

void CPU::opcodeD0() { ret(!f.getCarry()); }
void CPU::opcodeD1() { pop(de); }
void CPU::opcodeD2() { jp(!f.getCarry()); }
void CPU::opcodeD3() { unimplimentedOpcode(); }
void CPU::opcodeD4() { call(!f.getCarry()); }
void CPU::opcodeD5() { push(de); }
void CPU::opcodeD6() { sub(a); }
void CPU::opcodeD7() { rst(0x10); }
void CPU::opcodeD8() { ret(f.getCarry()); }
void CPU::opcodeD9() { reti(); }
void CPU::opcodeDA() { jp(f.getCarry()); }
void CPU::opcodeDB() { unimplimentedOpcode(); }
void CPU::opcodeDC() { call(f.getCarry()); }
void CPU::opcodeDD() { unimplimentedOpcode(); }
void CPU::opcodeDE() { sbc(a); }
void CPU::opcodeDF() { rst(0x18); }

void CPU::opcodeE0() { ld(0xFF00 + getNextByte(), a); }
void CPU::opcodeE1() { pop(hl); }
void CPU::opcodeE2() { ld(0xFF00 + c.value(), a); }
void CPU::opcodeE3() { unimplimentedOpcode(); }
void CPU::opcodeE4() { unimplimentedOpcode(); }
void CPU::opcodeE5() { push(hl); }
void CPU::opcodeE6() { op_and(a); }
void CPU::opcodeE7() { rst(0x20); }
void CPU::opcodeE8() { add_signed(sp); }
void CPU::opcodeE9() { jp(hl); }
void CPU::opcodeEA() { ld(getNextWord(), a); }
void CPU::opcodeEB() { unimplimentedOpcode(); }
void CPU::opcodeEC() { unimplimentedOpcode(); }
void CPU::opcodeED() { unimplimentedOpcode(); }
void CPU::opcodeEE() { op_xor(a); }
void CPU::opcodeEF() { rst(0x28); }

void CPU::opcodeF0() { ld(a, (0xFF00 + getNextByte())); }
void CPU::opcodeF1() { pop(af); }
void CPU::opcodeF2() { ld(a, (0xFF00 + c.value())); }
void CPU::opcodeF3() { di(); }
void CPU::opcodeF4() { unimplimentedOpcode(); }
void CPU::opcodeF5() { push(af); }
void CPU::opcodeF6() { op_or(a); }
void CPU::opcodeF7() { rst(0x30); }
void CPU::opcodeF8() { ld_hl_sp(); }
void CPU::opcodeF9() { ld(sp, hl); }
void CPU::opcodeFA() { ld(a, getNextWord()); }
void CPU::opcodeFB() { ei(); }
void CPU::opcodeFC() { unimplimentedOpcode(); }
void CPU::opcodeFD() { unimplimentedOpcode(); }
void CPU::opcodeFE() { cp(a, getNextByte()); }
void CPU::opcodeFF() { rst(0x38); }