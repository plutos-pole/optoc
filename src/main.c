#include "../includes/common.h"
#include "../includes/chunk.h"
#include "../includes/debug.h"

int main(void)
{
	Chunk chunk;
	init_chunk(&chunk);
	int constant = add_constant(&chunk, 1.2);
	write_chunk(&chunk, OP_CONSTANT);
	write_chunk(&chunk, constant);
	write_chunk(&chunk, OP_RETURN);
	disassemble_chunk(&chunk, "test_chunk");

	free_chunk(&chunk);

	return 0;
}