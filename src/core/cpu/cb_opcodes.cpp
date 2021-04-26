#include "cpu.h"

void CPU::cbopcode00() { rlc(b); }
void CPU::cbopcode01() { rlc(c); }
void CPU::cbopcode02() { rlc(d); }
void CPU::cbopcode03() { rlc(e); }
void CPU::cbopcode04() { rlc(h); }
void CPU::cbopcode05() { rlc(l); }
void CPU::cbopcode06() { rlc(hl); }
void CPU::cbopcode07() { rlc(a); }
void CPU::cbopcode08() { rrc(b); }
void CPU::cbopcode09() { rrc(c); }
void CPU::cbopcode0A() { rrc(d); }
void CPU::cbopcode0B() { rrc(e); }
void CPU::cbopcode0C() { rrc(h); }
void CPU::cbopcode0D() { rrc(l); }
void CPU::cbopcode0E() { rrc(hl); }
void CPU::cbopcode0F() { rrc(a); }

void CPU::cbopcode10() { rl(b); }
void CPU::cbopcode11() { rl(c); }
void CPU::cbopcode12() { rl(d); }
void CPU::cbopcode13() { rl(e); }
void CPU::cbopcode14() { rl(h); }
void CPU::cbopcode15() { rl(l); }
void CPU::cbopcode16() { rl(hl); }
void CPU::cbopcode17() { rl(a); }
void CPU::cbopcode18() { rr(b); }
void CPU::cbopcode19() { rr(c); }
void CPU::cbopcode1A() { rr(d); }
void CPU::cbopcode1B() { rr(e); }
void CPU::cbopcode1C() { rr(h); }
void CPU::cbopcode1D() { rr(l); }
void CPU::cbopcode1E() { rr(hl); }
void CPU::cbopcode1F() { rr(a); }

void CPU::cbopcode20() { sla(b); }
void CPU::cbopcode21() { sla(c); }
void CPU::cbopcode22() { sla(d); }
void CPU::cbopcode23() { sla(e); }
void CPU::cbopcode24() { sla(h); }
void CPU::cbopcode25() { sla(l); }
void CPU::cbopcode26() { sla(hl); }
void CPU::cbopcode27() { sla(a); }
void CPU::cbopcode28() { sra(b); }
void CPU::cbopcode29() { sra(c); }
void CPU::cbopcode2A() { sra(d); }
void CPU::cbopcode2B() { sra(e); }
void CPU::cbopcode2C() { sra(h); }
void CPU::cbopcode2D() { sra(l); }
void CPU::cbopcode2E() { sra(hl); }
void CPU::cbopcode2F() { sra(a); }

void CPU::cbopcode30() { swap(b); }
void CPU::cbopcode31() { swap(c); }
void CPU::cbopcode32() { swap(d); }
void CPU::cbopcode33() { swap(e); }
void CPU::cbopcode34() { swap(h); }
void CPU::cbopcode35() { swap(l); }
void CPU::cbopcode36() { swap(hl); }
void CPU::cbopcode37() { swap(a); }
void CPU::cbopcode38() { srl(b); }
void CPU::cbopcode39() { srl(c); }
void CPU::cbopcode3A() { srl(d); }
void CPU::cbopcode3B() { srl(e); }
void CPU::cbopcode3C() { srl(h); }
void CPU::cbopcode3D() { srl(l); }
void CPU::cbopcode3E() { srl(hl); }
void CPU::cbopcode3F() { srl(a); }

void CPU::cbopcode40() { bit(0, b); }
void CPU::cbopcode41() { bit(0, c); }
void CPU::cbopcode42() { bit(0, d); }
void CPU::cbopcode43() { bit(0, e); }
void CPU::cbopcode44() { bit(0, h); }
void CPU::cbopcode45() { bit(0, l); }
void CPU::cbopcode46() { bit(0, hl); }
void CPU::cbopcode47() { bit(0, a); }
void CPU::cbopcode48() { bit(1, b); }
void CPU::cbopcode49() { bit(1, c); }
void CPU::cbopcode4A() { bit(1, d); }
void CPU::cbopcode4B() { bit(1, e); }
void CPU::cbopcode4C() { bit(1, h); }
void CPU::cbopcode4D() { bit(1, l); }
void CPU::cbopcode4E() { bit(1, hl); }
void CPU::cbopcode4F() { bit(1, a); }

void CPU::cbopcode50() { bit(2, b); }
void CPU::cbopcode51() { bit(2, c); }
void CPU::cbopcode52() { bit(2, d); }
void CPU::cbopcode53() { bit(2, e); }
void CPU::cbopcode54() { bit(2, h); }
void CPU::cbopcode55() { bit(2, l); }
void CPU::cbopcode56() { bit(2, hl); }
void CPU::cbopcode57() { bit(2, a); }
void CPU::cbopcode58() { bit(3, b); }
void CPU::cbopcode59() { bit(3, c); }
void CPU::cbopcode5A() { bit(3, d); }
void CPU::cbopcode5B() { bit(3, e); }
void CPU::cbopcode5C() { bit(3, h); }
void CPU::cbopcode5D() { bit(3, l); }
void CPU::cbopcode5E() { bit(3, hl); }
void CPU::cbopcode5F() { bit(3, a); }

void CPU::cbopcode60() { bit(4, b); }
void CPU::cbopcode61() { bit(4, c); }
void CPU::cbopcode62() { bit(4, d); }
void CPU::cbopcode63() { bit(4, e); }
void CPU::cbopcode64() { bit(4, h); }
void CPU::cbopcode65() { bit(4, l); }
void CPU::cbopcode66() { bit(4, hl); }
void CPU::cbopcode67() { bit(4, a); }
void CPU::cbopcode68() { bit(5, b); }
void CPU::cbopcode69() { bit(5, c); }
void CPU::cbopcode6A() { bit(5, d); }
void CPU::cbopcode6B() { bit(5, e); }
void CPU::cbopcode6C() { bit(5, h); }
void CPU::cbopcode6D() { bit(5, l); }
void CPU::cbopcode6E() { bit(5, hl); }
void CPU::cbopcode6F() { bit(5, a); }

void CPU::cbopcode70() { bit(6, b); }
void CPU::cbopcode71() { bit(6, c); }
void CPU::cbopcode72() { bit(6, d); }
void CPU::cbopcode73() { bit(6, e); }
void CPU::cbopcode74() { bit(6, h); }
void CPU::cbopcode75() { bit(6, l); }
void CPU::cbopcode76() { bit(6, hl); }
void CPU::cbopcode77() { bit(6, a); }
void CPU::cbopcode78() { bit(7, b); }
void CPU::cbopcode79() { bit(7, c); }
void CPU::cbopcode7A() { bit(7, d); }
void CPU::cbopcode7B() { bit(7, e); }
void CPU::cbopcode7C() { bit(7, h); }
void CPU::cbopcode7D() { bit(7, l); }
void CPU::cbopcode7E() { bit(7, hl); }
void CPU::cbopcode7F() { bit(7, a); }

void CPU::cbopcode80() {}
void CPU::cbopcode81() {}
void CPU::cbopcode82() {}
void CPU::cbopcode83() {}
void CPU::cbopcode84() {}
void CPU::cbopcode85() {}
void CPU::cbopcode86() {}
void CPU::cbopcode87() {}
void CPU::cbopcode88() {}
void CPU::cbopcode89() {}
void CPU::cbopcode8A() {}
void CPU::cbopcode8B() {}
void CPU::cbopcode8C() {}
void CPU::cbopcode8D() {}
void CPU::cbopcode8E() {}
void CPU::cbopcode8F() {}

void CPU::cbopcode90() {}
void CPU::cbopcode91() {}
void CPU::cbopcode92() {}
void CPU::cbopcode93() {}
void CPU::cbopcode94() {}
void CPU::cbopcode95() {}
void CPU::cbopcode96() {}
void CPU::cbopcode97() {}
void CPU::cbopcode98() {}
void CPU::cbopcode99() {}
void CPU::cbopcode9A() {}
void CPU::cbopcode9B() {}
void CPU::cbopcode9C() {}
void CPU::cbopcode9D() {}
void CPU::cbopcode9E() {}
void CPU::cbopcode9F() {}

void CPU::cbopcodeA0() {}
void CPU::cbopcodeA1() {}
void CPU::cbopcodeA2() {}
void CPU::cbopcodeA3() {}
void CPU::cbopcodeA4() {}
void CPU::cbopcodeA5() {}
void CPU::cbopcodeA6() {}
void CPU::cbopcodeA7() {}
void CPU::cbopcodeA8() {}
void CPU::cbopcodeA9() {}
void CPU::cbopcodeAA() {}
void CPU::cbopcodeAB() {}
void CPU::cbopcodeAC() {}
void CPU::cbopcodeAD() {}
void CPU::cbopcodeAE() {}
void CPU::cbopcodeAF() {}

void CPU::cbopcodeB0() {}
void CPU::cbopcodeB1() {}
void CPU::cbopcodeB2() {}
void CPU::cbopcodeB3() {}
void CPU::cbopcodeB4() {}
void CPU::cbopcodeB5() {}
void CPU::cbopcodeB6() {}
void CPU::cbopcodeB7() {}
void CPU::cbopcodeB8() {}
void CPU::cbopcodeB9() {}
void CPU::cbopcodeBA() {}
void CPU::cbopcodeBB() {}
void CPU::cbopcodeBC() {}
void CPU::cbopcodeBD() {}
void CPU::cbopcodeBE() {}
void CPU::cbopcodeBF() {}

void CPU::cbopcodeC0() {}
void CPU::cbopcodeC1() {}
void CPU::cbopcodeC2() {}
void CPU::cbopcodeC3() {}
void CPU::cbopcodeC4() {}
void CPU::cbopcodeC5() {}
void CPU::cbopcodeC6() {}
void CPU::cbopcodeC7() {}
void CPU::cbopcodeC8() {}
void CPU::cbopcodeC9() {}
void CPU::cbopcodeCA() {}
void CPU::cbopcodeCB() {}
void CPU::cbopcodeCC() {}
void CPU::cbopcodeCD() {}
void CPU::cbopcodeCE() {}
void CPU::cbopcodeCF() {}

void CPU::cbopcodeD0() {}
void CPU::cbopcodeD1() {}
void CPU::cbopcodeD2() {}
void CPU::cbopcodeD3() {}
void CPU::cbopcodeD4() {}
void CPU::cbopcodeD5() {}
void CPU::cbopcodeD6() {}
void CPU::cbopcodeD7() {}
void CPU::cbopcodeD8() {}
void CPU::cbopcodeD9() {}
void CPU::cbopcodeDA() {}
void CPU::cbopcodeDB() {}
void CPU::cbopcodeDC() {}
void CPU::cbopcodeDD() {}
void CPU::cbopcodeDE() {}
void CPU::cbopcodeDF() {}

void CPU::cbopcodeE0() {}
void CPU::cbopcodeE1() {}
void CPU::cbopcodeE2() {}
void CPU::cbopcodeE3() {}
void CPU::cbopcodeE4() {}
void CPU::cbopcodeE5() {}
void CPU::cbopcodeE6() {}
void CPU::cbopcodeE7() {}
void CPU::cbopcodeE8() {}
void CPU::cbopcodeE9() {}
void CPU::cbopcodeEA() {}
void CPU::cbopcodeEB() {}
void CPU::cbopcodeEC() {}
void CPU::cbopcodeED() {}
void CPU::cbopcodeEE() {}
void CPU::cbopcodeEF() {}

void CPU::cbopcodeF0() {}
void CPU::cbopcodeF1() {}
void CPU::cbopcodeF2() {}
void CPU::cbopcodeF3() {}
void CPU::cbopcodeF4() {}
void CPU::cbopcodeF5() {}
void CPU::cbopcodeF6() {}
void CPU::cbopcodeF7() {}
void CPU::cbopcodeF8() {}
void CPU::cbopcodeF9() {}
void CPU::cbopcodeFA() {}
void CPU::cbopcodeFB() {}
void CPU::cbopcodeFC() {}
void CPU::cbopcodeFD() {}
void CPU::cbopcodeFE() {}
void CPU::cbopcodeFF() {}