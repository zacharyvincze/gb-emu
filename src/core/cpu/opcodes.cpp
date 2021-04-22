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
void CPU::opcode08() { ld(sp); }
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
void CPU::opcode34() { inc(hl.get()); }
void CPU::opcode35() { dec(hl.get()); }
void CPU::opcode36() { ld(hl); }
void CPU::opcode37() { scf(); }
void CPU::opcode38() {}
void CPU::opcode39() {}
void CPU::opcode3A() {}
void CPU::opcode3B() {}
void CPU::opcode3C() {}
void CPU::opcode3D() {}
void CPU::opcode3E() {}
void CPU::opcode3F() {}

void CPU::opcode40() {}
void CPU::opcode41() {}
void CPU::opcode42() {}
void CPU::opcode43() {}
void CPU::opcode44() {}
void CPU::opcode45() {}
void CPU::opcode46() {}
void CPU::opcode47() {}
void CPU::opcode48() {}
void CPU::opcode49() {}
void CPU::opcode4A() {}
void CPU::opcode4B() {}
void CPU::opcode4C() {}
void CPU::opcode4D() {}
void CPU::opcode4E() {}
void CPU::opcode4F() {}

void CPU::opcode50() {}
void CPU::opcode51() {}
void CPU::opcode52() {}
void CPU::opcode53() {}
void CPU::opcode54() {}
void CPU::opcode55() {}
void CPU::opcode56() {}
void CPU::opcode57() {}
void CPU::opcode58() {}
void CPU::opcode59() {}
void CPU::opcode5A() {}
void CPU::opcode5B() {}
void CPU::opcode5C() {}
void CPU::opcode5D() {}
void CPU::opcode5E() {}
void CPU::opcode5F() {}

void CPU::opcode60() {}
void CPU::opcode61() {}
void CPU::opcode62() {}
void CPU::opcode63() {}
void CPU::opcode64() {}
void CPU::opcode65() {}
void CPU::opcode66() {}
void CPU::opcode67() {}
void CPU::opcode68() {}
void CPU::opcode69() {}
void CPU::opcode6A() {}
void CPU::opcode6B() {}
void CPU::opcode6C() {}
void CPU::opcode6D() {}
void CPU::opcode6E() {}
void CPU::opcode6F() {}

void CPU::opcode70() {}
void CPU::opcode71() {}
void CPU::opcode72() {}
void CPU::opcode73() {}
void CPU::opcode74() {}
void CPU::opcode75() {}
void CPU::opcode76() {}
void CPU::opcode77() {}
void CPU::opcode78() {}
void CPU::opcode79() {}
void CPU::opcode7A() {}
void CPU::opcode7B() {}
void CPU::opcode7C() {}
void CPU::opcode7D() {}
void CPU::opcode7E() {}
void CPU::opcode7F() {}

void CPU::opcode80() {}
void CPU::opcode81() {}
void CPU::opcode82() {}
void CPU::opcode83() {}
void CPU::opcode84() {}
void CPU::opcode85() {}
void CPU::opcode86() {}
void CPU::opcode87() {}
void CPU::opcode88() {}
void CPU::opcode89() {}
void CPU::opcode8A() {}
void CPU::opcode8B() {}
void CPU::opcode8C() {}
void CPU::opcode8D() {}
void CPU::opcode8E() {}
void CPU::opcode8F() {}

void CPU::opcode90() {}
void CPU::opcode91() {}
void CPU::opcode92() {}
void CPU::opcode93() {}
void CPU::opcode94() {}
void CPU::opcode95() {}
void CPU::opcode96() {}
void CPU::opcode97() {}
void CPU::opcode98() {}
void CPU::opcode99() {}
void CPU::opcode9A() {}
void CPU::opcode9B() {}
void CPU::opcode9C() {}
void CPU::opcode9D() {}
void CPU::opcode9E() {}
void CPU::opcode9F() {}

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