#ifndef CHIP8_H
#define CHIP8_H
/* Sizes */
#define MEM_SIZE 4096
#define GEN_REGS_SIZE 16
#define STACK_SIZE 4096
#define NUM_PIXELS 64*32
#define KEYPAD_SIZE 16
#define BYTE 8

/* OPCODES */

/* MASKS */
#define CLEAR_SCREEN_MASK 0x00E0
//#define DRAW_SPRITE_MASK 0xDXYN

enum generalRegs {
    V0 = 0,
    V1,     // 1
    V2,     // 2
    V3,     // 3
    V4,     // 4
    V5,     // 5
    V6,     // 6
    V7,     // 7
    V8,     // 8
    V9,     // 9
    VA,     // 10
    VB,     // 11
    VC,     // 12
    VD,     // 13
    VE,     // 14
    VF      // 15
};

unsigned char chip8_fontset[80] =
        {
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

struct chip8
{
    /* Memory Map
     * 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
     * 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
     * 0x200-0xFFF - Program ROM and work RAM
     */
    /* 35 opcodes of length 2 bytes */
    unsigned short opcode = 0;
    /* 4k memory */
    unsigned char memory[MEM_SIZE] = {0};
    /* 15 8-bit general purpose registers */
    unsigned char V[GEN_REGS_SIZE] = {0};
    /* Stack */
    unsigned char stack[STACK_SIZE] = {0};
    /* Index register and program counter (0x000->0xFFF) */
    unsigned short I = 0;
    unsigned short pc = 0;
    unsigned short sp = 0;
    /* Black and White graphics with 2048 pixels (64x32) */
    unsigned char gfx[NUM_PIXELS] = {0};
    /* Timing registers */
    unsigned char delay_timer = 0;
    unsigned char sound_timer = 0;
    /* HEX based keypad (0x0-0xF) */
    unsigned char key[KEYPAD_SIZE] = {0};

    /* Function declarations */
    bool initialize();
    bool loadGame(const char *);
    void emulateCycle();

} myChip8;
#endif // CHIP8_H