#ifndef DEBUG_H
#define DEBUG_H

#include "chunk.h"

void disassemble_chunk(Chunk *chunk, const char *name);
int disassmble_instruction(Chunk *chunk, int offset);

#endif