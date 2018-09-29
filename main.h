#pragma once

#include "stdint.h"
#include <iostream>
#include <string>

uint32_t u32_from_str_prefix(char *str);


struct RegisterIndex
{
	RegisterIndex(uint32_t index) :
		m_index(index)
	{
	}

	uint32_t m_index;

};

struct Instruction
{

	Instruction(uint32_t data) :
		m_data(data)
	{
	}

	uint32_t m_data;


	uint32_t function();
	uint32_t subfunction();
	uint32_t cop_opcode();
	RegisterIndex s();
	RegisterIndex t();
	RegisterIndex d();
	uint32_t imm();
	uint32_t imm_se();
	uint32_t shift();
	uint32_t imm_jump();


	std::string i2s();

};
