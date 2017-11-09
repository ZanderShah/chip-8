#ifndef CHIP_H
#define CHIP_H

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef struct {
    unsigned short opcode;
    unsigned char mem[4096];
    unsigned char V[16];
    unsigned short I;
    unsigned short pc;

    // 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
    // 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
    // 0x200-0xFFF - Program ROM and work RAM

    unsigned char gfx[64][32];

	unsigned char delay;
	unsigned char sound;

	unsigned short stack[16];
	unsigned short sp;

    unsigned char key[16];
    
    void initialize();
    void load(const char* path);
    void cycle();
    void setKeys();
} chip8;

#endif