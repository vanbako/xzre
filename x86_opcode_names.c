/*
 * Copyright (C) 2024 Stefano Moioli <smxdev4@gmail.com>
 **/
#include "xzre.h"

/**
Source: https://github.com/torvalds/linux/blob/690ca3a3067f760bef92ca5db1c42490498ab5de/arch/x86/lib/x86-opcode-map.txt
*/
const char *X86_OPCODE_NAMES[] = {
"ADD Eb,Gb",
"ADD Ev,Gv",
"ADD Gb,Eb",
"ADD Gv,Ev",
"ADD AL,Ib",
"ADD rAX,Iz",
"PUSH ES (i64)",
"POP ES (i64)",
"OR Eb,Gb",
"OR Ev,Gv",
"OR Gb,Eb",
"OR Gv,Ev",
"OR AL,Ib",
"OR rAX,Iz",
"PUSH CS (i64)",
"escape", // 2-byte escape
"ADC Eb,Gb",
"ADC Ev,Gv",
"ADC Gb,Eb",
"ADC Gv,Ev",
"ADC AL,Ib",
"ADC rAX,Iz",
"PUSH SS (i64)",
"POP SS (i64)",
"SBB Eb,Gb",
"SBB Ev,Gv",
"SBB Gb,Eb",
"SBB Gv,Ev",
"SBB AL,Ib",
"SBB rAX,Iz",
"PUSH DS (i64)",
"POP DS (i64)",
"AND Eb,Gb",
"AND Ev,Gv",
"AND Gb,Eb",
"AND Gv,Ev",
"AND AL,Ib",
"AND rAx,Iz",
"SEG=ES (Prefix)",
"DAA (i64)",
"SUB Eb,Gb",
"SUB Ev,Gv",
"SUB Gb,Eb",
"SUB Gv,Ev",
"SUB AL,Ib",
"SUB rAX,Iz",
"SEG=CS (Prefix)",
"DAS (i64)",
"XOR Eb,Gb",
"XOR Ev,Gv",
"XOR Gb,Eb",
"XOR Gv,Ev",
"XOR AL,Ib",
"XOR rAX,Iz",
"SEG=SS (Prefix)",
"AAA (i64)",
"CMP Eb,Gb",
"CMP Ev,Gv",
"CMP Gb,Eb",
"CMP Gv,Ev",
"CMP AL,Ib",
"CMP rAX,Iz",
"SEG=DS (Prefix)",
"AAS (i64)",
"INC eAX (i64) | REX (o64)",
"INC eCX (i64) | REX.B (o64)",
"INC eDX (i64) | REX.X (o64)",
"INC eBX (i64) | REX.XB (o64)",
"INC eSP (i64) | REX.R (o64)",
"INC eBP (i64) | REX.RB (o64)",
"INC eSI (i64) | REX.RX (o64)",
"INC eDI (i64) | REX.RXB (o64)",
"DEC eAX (i64) | REX.W (o64)",
"DEC eCX (i64) | REX.WB (o64)",
"DEC eDX (i64) | REX.WX (o64)",
"DEC eBX (i64) | REX.WXB (o64)",
"DEC eSP (i64) | REX.WR (o64)",
"DEC eBP (i64) | REX.WRB (o64)",
"DEC eSI (i64) | REX.WRX (o64)",
"DEC eDI (i64) | REX.WRXB (o64)",
"PUSH rAX/r8 (d64)",
"PUSH rCX/r9 (d64)",
"PUSH rDX/r10 (d64)",
"PUSH rBX/r11 (d64)",
"PUSH rSP/r12 (d64)",
"PUSH rBP/r13 (d64)",
"PUSH rSI/r14 (d64)",
"PUSH rDI/r15 (d64)",
"POP rAX/r8 (d64)",
"POP rCX/r9 (d64)",
"POP rDX/r10 (d64)",
"POP rBX/r11 (d64)",
"POP rSP/r12 (d64)",
"POP rBP/r13 (d64)",
"POP rSI/r14 (d64)",
"POP rDI/r15 (d64)",
"PUSHA/PUSHAD (i64)",
"POPA/POPAD (i64)",
"BOUND Gv,Ma (i64) | EVEX (Prefix)",
"ARPL Ew,Gw (i64) | MOVSXD Gv,Ev (o64)",
"SEG=FS (Prefix)",
"SEG=GS (Prefix)",
"Operand-Size (Prefix)",
"Address-Size (Prefix)",
"PUSH Iz",
"IMUL Gv,Ev,Iz",
"PUSH Ib (d64)",
"IMUL Gv,Ev,Ib",
"INS/INSB Yb,DX",
"INS/INSW/INSD Yz,DX",
"OUTS/OUTSB DX,Xb",
"OUTS/OUTSW/OUTSD DX,Xz",
"JO Jb (!REX2)",
"JNO Jb (!REX2)",
"JB/JNAE/JC Jb (!REX2)",
"JNB/JAE/JNC Jb (!REX2)",
"JZ/JE Jb (!REX2)",
"JNZ/JNE Jb (!REX2)",
"JBE/JNA Jb (!REX2)",
"JNBE/JA Jb (!REX2)",
"JS Jb (!REX2)",
"JNS Jb (!REX2)",
"JP/JPE Jb (!REX2)",
"JNP/JPO Jb (!REX2)",
"JL/JNGE Jb (!REX2)",
"JNL/JGE Jb (!REX2)",
"JLE/JNG Jb (!REX2)",
"JNLE/JG Jb (!REX2)",
"Grp1 Eb,Ib (1A)",
"Grp1 Ev,Iz (1A)",
"Grp1 Eb,Ib (1A),(i64)",
"Grp1 Ev,Ib (1A)",
"TEST Eb,Gb",
"TEST Ev,Gv",
"XCHG Eb,Gb",
"XCHG Ev,Gv",
"MOV Eb,Gb",
"MOV Ev,Gv",
"MOV Gb,Eb",
"MOV Gv,Ev",
"MOV Ev,Sw",
"LEA Gv,M",
"MOV Sw,Ew",
"Grp1A (1A) | POP Ev (d64)",
"NOP | PAUSE (F3) | XCHG r8,rAX",
"XCHG rCX/r9,rAX",
"XCHG rDX/r10,rAX",
"XCHG rBX/r11,rAX",
"XCHG rSP/r12,rAX",
"XCHG rBP/r13,rAX",
"XCHG rSI/r14,rAX",
"XCHG rDI/r15,rAX",
"CBW/CWDE/CDQE",
"CWD/CDQ/CQO",
"CALLF Ap (i64)",
"FWAIT/WAIT",
"PUSHF/D/Q Fv (d64)",
"POPF/D/Q Fv (d64)",
"SAHF",
"LAHF",
"MOV AL,Ob (!REX2)",
"MOV rAX,Ov (!REX2) | JMPABS O (REX2),(o64)",
"MOV Ob,AL (!REX2)",
"MOV Ov,rAX (!REX2)",
"MOVS/B Yb,Xb (!REX2)",
"MOVS/W/D/Q Yv,Xv (!REX2)",
"CMPS/B Xb,Yb (!REX2)",
"CMPS/W/D Xv,Yv (!REX2)",
"TEST AL,Ib (!REX2)",
"TEST rAX,Iz (!REX2)",
"STOS/B Yb,AL (!REX2)",
"STOS/W/D/Q Yv,rAX (!REX2)",
"LODS/B AL,Xb (!REX2)",
"LODS/W/D/Q rAX,Xv (!REX2)",
"SCAS/B AL,Yb (!REX2)",
"SCAS/W/D/Q rAX,Yv (!REX2)",
"MOV AL/R8L,Ib",
"MOV CL/R9L,Ib",
"MOV DL/R10L,Ib",
"MOV BL/R11L,Ib",
"MOV AH/R12L,Ib",
"MOV CH/R13L,Ib",
"MOV DH/R14L,Ib",
"MOV BH/R15L,Ib",
"MOV rAX/r8,Iv",
"MOV rCX/r9,Iv",
"MOV rDX/r10,Iv",
"MOV rBX/r11,Iv",
"MOV rSP/r12,Iv",
"MOV rBP/r13,Iv",
"MOV rSI/r14,Iv",
"MOV rDI/r15,Iv",
"Grp2 Eb,Ib (1A)",
"Grp2 Ev,Ib (1A)",
"RETN Iw (f64)",
"RETN",
"LES Gz,Mp (i64) | VEX+2byte (Prefix)",
"LDS Gz,Mp (i64) | VEX+1byte (Prefix)",
"Grp11A Eb,Ib (1A)",
"Grp11B Ev,Iz (1A)",
"ENTER Iw,Ib",
"LEAVE (d64)",
"RETF Iw",
"RETF",
"INT3",
"INT Ib",
"INTO (i64)",
"IRET/D/Q",
"Grp2 Eb,1 (1A)",
"Grp2 Ev,1 (1A)",
"Grp2 Eb,CL (1A)",
"Grp2 Ev,CL (1A)",
"AAM Ib (i64)",
"AAD Ib (i64) | REX2 (Prefix),(o64)",
"",
"XLAT/XLATB",
"ESC",
"ESC",
"ESC",
"ESC",
"ESC",
"ESC",
"ESC",
"ESC",
"LOOPNE/LOOPNZ Jb (f64) (!REX2)",
"LOOPE/LOOPZ Jb (f64) (!REX2)",
"LOOP Jb (f64) (!REX2)",
"JrCXZ Jb (f64) (!REX2)",
"IN AL,Ib (!REX2)",
"IN eAX,Ib (!REX2)",
"OUT Ib,AL (!REX2)",
"OUT Ib,eAX (!REX2)",
"CALL Jz (f64) (!REX2)",
"JMP-near Jz (f64) (!REX2)",
"JMP-far Ap (i64) (!REX2)",
"JMP-short Jb (f64) (!REX2)",
"IN AL,DX (!REX2)",
"IN eAX,DX (!REX2)",
"OUT DX,AL (!REX2)",
"OUT DX,eAX (!REX2)",
"LOCK (Prefix)",
"",
"REPNE (Prefix) | XACQUIRE (Prefix)",
"REP/REPE (Prefix) | XRELEASE (Prefix)",
"HLT",
"CMC",
"Grp3_1 Eb (1A)",
"Grp3_2 Ev (1A)",
"CLC",
"STC",
"CLI",
"STI",
"CLD",
"STD",
"Grp4 (1A)",
"Grp5 (1A)"
};

const int X86_OPCODE_NAMES_COUNT = ARRAY_SIZE(X86_OPCODE_NAMES);
