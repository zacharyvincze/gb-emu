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
void CPU::opcode5D() { ld(e, l) }
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

void CPU::opcodeA0() {}
void CPU::opcodeA1() {}
void CPU::opcodeA2() {}
void CPU::opcodeA3() {}
void CPU::opcodeA4() {}
void CPU::opcodeA5() {}
void CPU::opcodeA6() {}
void CPU::opcodeA7() {}
void CPU::opcodeA8() {}
void CPU::opcodeA9() {}
void CPU::opcodeAA() {}
void CPU::opcodeAB() {}
void CPU::opcodeAC() {}
void CPU::opcodeAD() {}
void CPU::opcodeAE() {}
void CPU::opcodeAF() {}

void CPU::opcodeB0() {}
void CPU::opcodeB1() {}
void CPU::opcodeB2() {}
void CPU::opcodeB3() {}
void CPU::opcodeB4() {}
void CPU::opcodeB5() {}
void CPU::opcodeB6() {}
void CPU::opcodeB7() {}
void CPU::opcodeB8() {}
void CPU::opcodeB9() {}
void CPU::opcodeBA() {}
void CPU::opcodeBB() {}
void CPU::opcodeBC() {}
void CPU::opcodeBD() {}
void CPU::opcodeBE() {}
void CPU::opcodeBF() {}

void CPU::opcodeC0() {}
void CPU::opcodeC1() {}
void CPU::opcodeC2() {}
void CPU::opcodeC3() {}
void CPU::opcodeC4() {}
void CPU::opcodeC5() {}
void CPU::opcodeC6() {}
void CPU::opcodeC7() {}
void CPU::opcodeC8() {}
void CPU::opcodeC9() {}
void CPU::opcodeCA() {}
void CPU::opcodeCB() {}
void CPU::opcodeCC() {}
void CPU::opcodeCD() {}
void CPU::opcodeCE() {}
void CPU::opcodeCF() {}

void CPU::opcodeD0() {}
void CPU::opcodeD1() {}
void CPU::opcodeD2() {}
void CPU::opcodeD3() {}
void CPU::opcodeD4() {}
void CPU::opcodeD5() {}
void CPU::opcodeD6() {}
void CPU::opcodeD7() {}
void CPU::opcodeD8() {}
void CPU::opcodeD9() {}
void CPU::opcodeDA() {}
void CPU::opcodeDB() {}
void CPU::opcodeDC() {}
void CPU::opcodeDD() {}
void CPU::opcodeDE() {}
void CPU::opcodeDF() {}

void CPU::opcodeE0() {}
void CPU::opcodeE1() {}
void CPU::opcodeE2() {}
void CPU::opcodeE3() {}
void CPU::opcodeE4() {}
void CPU::opcodeE5() {}
void CPU::opcodeE6() {}
void CPU::opcodeE7() {}
void CPU::opcodeE8() {}
void CPU::opcodeE9() {}
void CPU::opcodeEA() {}
void CPU::opcodeEB() {}
void CPU::opcodeEC() {}
void CPU::opcodeED() {}
void CPU::opcodeEE() {}
void CPU::opcodeEF() {}

void CPU::opcodeF0() {}
void CPU::opcodeF1() {}
void CPU::opcodeF2() {}
void CPU::opcodeF3() {}
void CPU::opcodeF4() {}
void CPU::opcodeF5() {}
void CPU::opcodeF6() {}
void CPU::opcodeF7() {}
void CPU::opcodeF8() {}
void CPU::opcodeF9() {}
void CPU::opcodeFA() {}
void CPU::opcodeFB() {}
void CPU::opcodeFC() {}
void CPU::opcodeFD() {}
void CPU::opcodeFE() {}
void CPU::opcodeFF() {}