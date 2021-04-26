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

void CPU::cbopcode80() { res(0, b); }
void CPU::cbopcode81() { res(0, c); }
void CPU::cbopcode82() { res(0, d); }
void CPU::cbopcode83() { res(0, e); }
void CPU::cbopcode84() { res(0, h); }
void CPU::cbopcode85() { res(0, l); }
void CPU::cbopcode86() { res(0, hl); }
void CPU::cbopcode87() { res(0, a); }
void CPU::cbopcode88() { res(1, b); }
void CPU::cbopcode89() { res(1, c); }
void CPU::cbopcode8A() { res(1, d); }
void CPU::cbopcode8B() { res(1, e); }
void CPU::cbopcode8C() { res(1, h); }
void CPU::cbopcode8D() { res(1, l); }
void CPU::cbopcode8E() { res(1, hl); }
void CPU::cbopcode8F() { res(1, a); }

void CPU::cbopcode90() { res(2, b); }
void CPU::cbopcode91() { res(2, c); }
void CPU::cbopcode92() { res(2, d); }
void CPU::cbopcode93() { res(2, e); }
void CPU::cbopcode94() { res(2, h); }
void CPU::cbopcode95() { res(2, l); }
void CPU::cbopcode96() { res(2, hl); }
void CPU::cbopcode97() { res(2, a); }
void CPU::cbopcode98() { res(3, b); }
void CPU::cbopcode99() { res(3, c); }
void CPU::cbopcode9A() { res(3, d); }
void CPU::cbopcode9B() { res(3, e); }
void CPU::cbopcode9C() { res(3, h); }
void CPU::cbopcode9D() { res(3, l); }
void CPU::cbopcode9E() { res(3, hl); }
void CPU::cbopcode9F() { res(3, a); }

void CPU::cbopcodeA0() { res(4, b); }
void CPU::cbopcodeA1() { res(4, c); }
void CPU::cbopcodeA2() { res(4, d); }
void CPU::cbopcodeA3() { res(4, e); }
void CPU::cbopcodeA4() { res(4, h); }
void CPU::cbopcodeA5() { res(4, l); }
void CPU::cbopcodeA6() { res(4, hl); }
void CPU::cbopcodeA7() { res(4, a); }
void CPU::cbopcodeA8() { res(5, b); }
void CPU::cbopcodeA9() { res(5, c); }
void CPU::cbopcodeAA() { res(5, d); }
void CPU::cbopcodeAB() { res(5, e); }
void CPU::cbopcodeAC() { res(5, h); }
void CPU::cbopcodeAD() { res(5, l); }
void CPU::cbopcodeAE() { res(5, hl); }
void CPU::cbopcodeAF() { res(5, a); }

void CPU::cbopcodeB0() { res(6, b); }
void CPU::cbopcodeB1() { res(6, c); }
void CPU::cbopcodeB2() { res(6, d); }
void CPU::cbopcodeB3() { res(6, e); }
void CPU::cbopcodeB4() { res(6, h); }
void CPU::cbopcodeB5() { res(6, l); }
void CPU::cbopcodeB6() { res(6, hl); }
void CPU::cbopcodeB7() { res(6, a); }
void CPU::cbopcodeB8() { res(7, b); }
void CPU::cbopcodeB9() { res(7, c); }
void CPU::cbopcodeBA() { res(7, d); }
void CPU::cbopcodeBB() { res(7, e); }
void CPU::cbopcodeBC() { res(7, h); }
void CPU::cbopcodeBD() { res(7, l); }
void CPU::cbopcodeBE() { res(7, hl); }
void CPU::cbopcodeBF() { res(7, a); }

void CPU::cbopcodeC0() { set(0, b); }
void CPU::cbopcodeC1() { set(0, c); }
void CPU::cbopcodeC2() { set(0, d); }
void CPU::cbopcodeC3() { set(0, e); }
void CPU::cbopcodeC4() { set(0, h); }
void CPU::cbopcodeC5() { set(0, l); }
void CPU::cbopcodeC6() { set(0, hl); }
void CPU::cbopcodeC7() { set(0, a); }
void CPU::cbopcodeC8() { set(1, b); }
void CPU::cbopcodeC9() { set(1, c); }
void CPU::cbopcodeCA() { set(1, d); }
void CPU::cbopcodeCB() { set(1, e); }
void CPU::cbopcodeCC() { set(1, h); }
void CPU::cbopcodeCD() { set(1, l); }
void CPU::cbopcodeCE() { set(1, hl); }
void CPU::cbopcodeCF() { set(1, a); }

void CPU::cbopcodeD0() { set(2, b); }
void CPU::cbopcodeD1() { set(2, c); }
void CPU::cbopcodeD2() { set(2, d); }
void CPU::cbopcodeD3() { set(2, e); }
void CPU::cbopcodeD4() { set(2, h); }
void CPU::cbopcodeD5() { set(2, l); }
void CPU::cbopcodeD6() { set(2, hl); }
void CPU::cbopcodeD7() { set(2, a); }
void CPU::cbopcodeD8() { set(3, b); }
void CPU::cbopcodeD9() { set(3, c); }
void CPU::cbopcodeDA() { set(3, d); }
void CPU::cbopcodeDB() { set(3, e); }
void CPU::cbopcodeDC() { set(3, h); }
void CPU::cbopcodeDD() { set(3, l); }
void CPU::cbopcodeDE() { set(3, hl); }
void CPU::cbopcodeDF() { set(3, a); }

void CPU::cbopcodeE0() { set(4, b); }
void CPU::cbopcodeE1() { set(4, c); }
void CPU::cbopcodeE2() { set(4, d); }
void CPU::cbopcodeE3() { set(4, e); }
void CPU::cbopcodeE4() { set(4, h); }
void CPU::cbopcodeE5() { set(4, l); }
void CPU::cbopcodeE6() { set(4, hl); }
void CPU::cbopcodeE7() { set(4, a); }
void CPU::cbopcodeE8() { set(5, b); }
void CPU::cbopcodeE9() { set(5, c); }
void CPU::cbopcodeEA() { set(5, d); }
void CPU::cbopcodeEB() { set(5, e); }
void CPU::cbopcodeEC() { set(5, h); }
void CPU::cbopcodeED() { set(5, l); }
void CPU::cbopcodeEE() { set(5, hl); }
void CPU::cbopcodeEF() { set(5, a); }

void CPU::cbopcodeF0() { set(6, b); }
void CPU::cbopcodeF1() { set(6, c); }
void CPU::cbopcodeF2() { set(6, d); }
void CPU::cbopcodeF3() { set(6, e); }
void CPU::cbopcodeF4() { set(6, h); }
void CPU::cbopcodeF5() { set(6, l); }
void CPU::cbopcodeF6() { set(6, hl); }
void CPU::cbopcodeF7() { set(6, a); }
void CPU::cbopcodeF8() { set(7, b); }
void CPU::cbopcodeF9() { set(7, c); }
void CPU::cbopcodeFA() { set(7, d); }
void CPU::cbopcodeFB() { set(7, e); }
void CPU::cbopcodeFC() { set(7, h); }
void CPU::cbopcodeFD() { set(7, l); }
void CPU::cbopcodeFE() { set(7, hl); }
void CPU::cbopcodeFF() { set(7, a); }