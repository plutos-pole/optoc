#include <stdio.h>
#include "../includes/debug.h"

static int simple_instruction(const char *name, int offset);

void disassemble_chunk(Chunk *chunk, const char *name)
{
	printf("==%s ==\n", name);

	for (int offset = 0; offset < chunk->count;)
	{
		offset = disassmble_instruction(chunk, offset);
	}
}

int disassmble_instruction(Chunk *chunk, int offset)
{
	printf("%04d ", offset);

	uint8_t instruction = chunk->code[offset];

	switch (instruction)
	{
	case OP_RETURN:
		return simple_instruction("OP_RETURN", offset);
	default:
		printf("Unknown opcode %d\n", instruction);
		return offset + 1;
	}
}

static int simple_instruction(const char *name, int offset)
{
	printf("%s\n", name);
	return offset + 1;
}