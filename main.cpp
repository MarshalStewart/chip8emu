#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

#include "graphics.cpp"
#include "chip8.cpp"

int main(int argc, char **argv)
{

    // Set up render system and register input callbacks
    myScreen.setupGraphics();
//    myScreen.setupInput();

    // Initialize the Chip8 system and load the game into the memory
    myChip8.initialize();
    myChip8.loadGame("pong");

    // Emulation loop
    for(;;)
    {
        myScreen.queueString("0N1N2N3N4");
        myScreen.drawScreen();

        sleep(5);

#if 0
        // Emulate one cycle
        myChip8.emulateCycle();
        // If the draw flag is set, update the screen
        if(myChip8.drawFlag)
            drawGraphics();

        // Store key press state (Press and Release)
        myChip8.setKeys();
#endif
    }

    return 0;
}


