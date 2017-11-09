#include "chip8.h"

using namespace std;

unsigned char fontset[80] = {
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void chip8::initialize() {
    pc = 0x200;
    opcode = 0;
    I = 0;
    sp = 0;
   
    memset(gfx, 0, sizeof gfx);
    memset(stack, 0, sizeof stack);
    memset(V, 0, sizeof V);
    memset(mem, 0, sizeof mem);
   
    for (int i = 0; i < 80; i++) {
        mem[i] = fontset[i];
    }
   
    delay = 0;
    sound = 0;
}

void chip8::load(const char* path) {
    FILE* rom = fopen(path, "rb");
    fseek(rom, 0, SEEK_END);
    int size = ftell(rom);
    rewind(rom);

    char* buffer = (char*) malloc(sizeof(char) * size);

    int bufferSize = fread(buffer, sizeof(char), size, rom);

    for (int i = 0; i < bufferSize; i++) {
        mem[i + 0x200] = (unsigned char)buffer[i];
    }

    fclose(rom);
    free(buffer);
}

void chip8::cycle() {
    opcode = mem[pc] << 8 | mem[pc + 1];

    switch (opcode & 0xF000) {

    }

    if (delay > 0) {
        delay--;
    } 
    if (sound > 0) {
        if (sound == 1) {
            printf("BEEP\n");
        }
        sound--;
    }
}

void chip8::setKeys() {

}
