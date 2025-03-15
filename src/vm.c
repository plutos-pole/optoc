#include "../includes/vm.h"
#include "../includes/common.h"
#include "../includes/value.h"
#include <stdio.h>

VM vm;

static InterpretResult run(void);

void init_vm()
{
}

void free_vm()
{
}

static InterpretResult run(void)
{
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

	for (;;)
	{
		uint8_t instruction;
		switch (instruction = READ_BYTE())
		{
		case OP_RETURN:
			return INTERPRET_OK;
		case OP_CONSTANT:
		{
			Value constant = READ_CONSTANT();
			print_value(constant);
			printf("\n");
			break;
		}
		};
	}
#undef READ_CONSTANT
#undef READ_BYTE
}

InterpretResult interpret(Chunk *chunk)
{
	vm.chunk = chunk;
	vm.ip = chunk->code;
	return run();
}