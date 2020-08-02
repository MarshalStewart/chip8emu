#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

#include "chip8.h"
#include "graphics.h"

/* Initialize registers and memory, meant to be ran once */
bool chip8::initialize()
{
    pc = 0x200; // Program counter starts at 0x200
    opcode = 0; // Reset current opcode
    I = 0;      // Reset index register
    sp = 0;     // Reset stack pointer

    // Clear Display
    memset(gfx, 0, NUM_PIXELS);
    // Clear stack
    memset(stack, 0, STACK_SIZE);
    // Clear registers V0-VF
    memset(V, 0, GEN_REGS_SIZE);
    // Clear Memory
    memset(memory, 0, MEM_SIZE);
    // Load font set
    for(int i=0; i<80; ++i)
        memory[i] = chip8_fontset[i];
    // Reset timers
    delay_timer = 0;
    sound_timer = 0;

//    myScreen.drawScreen();

    return true;
}

bool chip8::loadGame(const char * game)
{
    int bufferSize = 1;
    int buffer[bufferSize] = {0};
    // Open file in binary mode

    // Load program into memory
    for(int i=0; i<bufferSize; ++i)
        memory[i+512] = buffer[i];
}


/* Complete CPU Cycle */
void chip8::emulateCycle()
{
    // Fetch opcode
    opcode = memory[pc] << BYTE | memory[pc + 1];
    // Decode opcode and execute opcodes
    switch(opcode & 0xF000)
    {
        case 0x0000:
            switch (opcode & 0x000F)
            {
                case 0x0000:
                    break;
                case 0x000E:
                    break;
                default:
                    printf("Unknown opcode: 0x%X\n", opcode);
            }
        case 0x2000:
            stack[sp] = pc;
            ++sp;
            pc = opcode & 0x0FFF;
        case 0xA000:
            I = opcode & 0x0FFF;
            pc += 2;
            break;
        default:
            printf("Invalid opcode: 0x%X\n", opcode);
    }
    // Update Timers
    if(delay_timer > 0)
        --delay_timer;
    if(sound_timer > 0) if (sound_timer == 1)
        {
            printf("BEEP!\n");
            --sound_timer;
        }


}
