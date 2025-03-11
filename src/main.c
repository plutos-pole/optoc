#include "../includes/common.h"
#include "../includes/chunk.h"
#include "../includes/debug.h"

int main(void)
{
	Chunk chunk;
	init_chunk(&chunk);
	write_chunk(&chunk, OP_RETURN);
	write_chunk(&chunk, OP_RETURN);

	disassemble_chunk(&chunk, "test_chunk");

	free_chunk(&chunk);

	return 0;
}