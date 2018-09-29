
#pragma once

#include "main.h"

#include "stdio.h"
#include "stdlib.h"

#include <iostream>
#include <string>

std::string decode(Instruction instruction);

char * reg(RegisterIndex idx);


char * op_sll(Instruction instruction);
char * op_srl(Instruction instruction);
char * op_sra(Instruction instruction);
char * op_sllv(Instruction instruction);
char * op_srlv(Instruction instruction);
char * op_srav(Instruction instruction);
char * op_jr(Instruction instruction);
char * op_jalr(Instruction instruction);
char * op_syscall(Instruction instruction);
char * op_break(Instruction instruction);
char * op_mfhi(Instruction instruction);
char * op_mthi(Instruction instruction);
char * op_mflo(Instruction instruction);
char * op_mtlo(Instruction instruction);
char * op_mult(Instruction instruction);
char * op_multu(Instruction instruction);
char * op_div(Instruction instruction);
char * op_divu(Instruction instruction);
char * op_add(Instruction instruction);
char * op_addu(Instruction instruction);
char * op_sub(Instruction instruction);
char * op_subu(Instruction instruction);
char * op_and(Instruction instruction);
char * op_or(Instruction instruction);
char * op_xor(Instruction instruction);
char * op_nor(Instruction instruction);
char * op_slt(Instruction instruction);
char * op_sltu(Instruction instruction);
char * op_bxx(Instruction instruction);
char * op_j(Instruction instruction);
char * op_jal(Instruction instruction);
char * op_beq(Instruction instruction);
char * op_bne(Instruction instruction);
char * op_blez(Instruction instruction);
char * op_bgtz(Instruction instruction);
char * op_addi(Instruction instruction);
char * op_addiu(Instruction instruction);
char * op_slti(Instruction instruction);
char * op_sltiu(Instruction instruction);
char * op_andi(Instruction instruction);
char * op_ori(Instruction instruction);
char * op_xori(Instruction instruction);
char * op_lui(Instruction instruction);
char * op_cop0(Instruction instruction);
char * op_cop1(Instruction instruction);
char * op_cop2(Instruction instruction);
char * op_cop3(Instruction instruction);
char * op_lb(Instruction instruction);
char * op_lh(Instruction instruction);
char * op_lwl(Instruction instruction);
char * op_lw(Instruction instruction);
char * op_lbu(Instruction instruction);
char * op_lhu(Instruction instruction);
char * op_lwr(Instruction instruction);
char * op_sb(Instruction instruction);
char * op_sh(Instruction instruction);
char * op_swl(Instruction instruction);
char * op_sw(Instruction instruction);
char * op_swr(Instruction instruction);
char * op_lwc0(Instruction instruction);
char * op_lwc1(Instruction instruction);
char * op_lwc2(Instruction instruction);
char * op_lwc3(Instruction instruction);
char * op_swc0(Instruction instruction);
char * op_swc1(Instruction instruction);
char * op_swc2(Instruction instruction);
char * op_swc3(Instruction instruction);


char * op_mfc0(Instruction instruction);
char * op_mtc0(Instruction instruction);
char * op_rfe(Instruction instruction);



/*

char * op_sll
char * op_srl
char * op_sra
char * op_sllv
char * op_srlv
char * op_srav
char * op_jr
char * op_jalr
char * op_syscall
char * op_break
char * op_mfhi
char * op_mthi
char * op_mflo
char * op_mtlo
char * op_mult
char * op_multu
char * op_div
char * op_divu
char * op_add
char * op_addu
char * op_sub
char * op_subu
char * op_and
char * op_or
char * op_xor
char * op_nor
char * op_slt
char * op_sltu
char * op_bxx
char * op_j
char * op_jal
char * op_beq
char * op_bne
char * op_blez
char * op_bgtz
char * op_addi
char * op_addiu
char * op_slti
char * op_sltiu
char * op_andi
char * op_ori
char * op_xori
char * op_lui
char * op_cop0
char * op_cop1
char * op_cop2
char * op_cop3
char * op_lb
char * op_lh
char * op_lwl
char * op_lw
char * op_lbu
char * op_lhu
char * op_lwr
char * op_sb
char * op_sh
char * op_swl
char * op_sw
char * op_swr
char * op_lwc0
char * op_lwc1
char * op_lwc2
char * op_lwc3
char * op_swc0
char * op_swc1
char * op_swc2
char * op_swc3

*/
