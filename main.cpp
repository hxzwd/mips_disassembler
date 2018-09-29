
#include "main.h"
#include "asm.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#include <iostream>
#include <string>



int main(void)
{

	printf("MIPS_DISASM\n\n");

/*

	Instruction tmp(0x00001812);
	printf("\n0x%s\n", tmp.i2s().c_str());

	uint32_t tmp2;
	tmp2 = u32_from_str_prefix("0xff");
	printf("\n%u\n", tmp2);

	printf("\n%s\n", decode(tmp).c_str());


	if(NULL == decode(tmp))
	{
		printf("\nTRUE\n");
		printf("\n%s\n", reg(RegisterIndex(13)));
	}
*/

	uint32_t buf[2048] = { 0 };
	uint32_t buf_size = 2048;
	uint8_t tmp_buf[4];
	int32_t n_bytes;
	uint32_t tmp_word;

	uint32_t org = 0xbfc00000;
	uint32_t address = org;

	FILE *fn;
	if((fn = fopen("SCPH1001.BIN", "rb")) == NULL)
	{
		printf("OPEN BIN FILE ERROR\n");
		return 1;
	}
	for(int i = 0; i < buf_size; i++)
	{
		n_bytes = fread((void *)&tmp_buf[0], sizeof(uint8_t), 4, fn);
		if(n_bytes <= 0)
		{
			printf("READ BIN FILE ERROR\n");
			fclose(fn);
			return 1;
		}
		uint32_t b0 = tmp_buf[0];
		uint32_t b1 = tmp_buf[1];
		uint32_t b2 = tmp_buf[2];
		uint32_t b3 = tmp_buf[3];

		tmp_word = (b0 | (b1 << 8) | (b2 << 16) | (b3 << 24));
		Instruction instruction(tmp_word);
		buf[i] = tmp_word; 

		printf("0x%08x\t0x%s\t%s\n", address, instruction.i2s().c_str(), decode(instruction).c_str());

		address += sizeof(tmp_word);

	}

	fclose(fn);

	return 0;
}


uint32_t Instruction::function()
{
	return m_data >> 26;
}

uint32_t Instruction::subfunction()
{
	return m_data & 0x3f;
}

uint32_t Instruction::cop_opcode()
{
	return (m_data >> 21) & 0x1f;
}

RegisterIndex Instruction::s()
{
	return RegisterIndex((m_data >> 21) & 0x1f);
}

RegisterIndex Instruction::t()
{
	return RegisterIndex((m_data >> 16) & 0x1f);
}

RegisterIndex Instruction::d()
{
	return RegisterIndex((m_data >> 11) & 0x1f);
}

uint32_t Instruction::imm()
{
	return m_data & 0xffff;
}

uint32_t Instruction::imm_se()
{
	uint16_t value = (uint16_t)(m_data & 0xffff);
	return (uint32_t)value;
}

uint32_t Instruction::shift()
{
	return (m_data >> 6) & 0x1f;
}

uint32_t Instruction::imm_jump()
{
	return m_data & 0x3ffffff;
}


std::string Instruction::i2s()
{
	char buffer[1024] = { 0 };
	sprintf(buffer, "%08x", m_data);
	std::string hexstr(buffer);
	return hexstr;
}

uint32_t u32_from_str_prefix(char * str)
{
	int str_len = strlen(str);
	char *number;
	uint32_t base;
	switch(str_len)
	{
		case 0:
		case 1:
			base = 10;
			number = str;
			break;
		default:
			if(str[0] == '0')
			{
				switch(str[1])
				{
					case 'x':
						base = 16;
						number = str + 2;
						break;
					case 'o':
						base = 8;
						number = str + 2;
						break;
					case 'b':
						base = 2;
						number = str + 2;
						break;
					default:
						base = 10;
						number = str;
				}
			}
			else
			{
				base = 10;
				number = str;
			}
	}
	return (uint32_t)strtoul(number, (char **)NULL, base);

}
