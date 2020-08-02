#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

#include "graphics.h"

void screen::setupGraphics() {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            for (unsigned i = 0; i < PIXEL_HEIGHT; i++) {
                display[row][col].data[i] = pixel_null[i];
            }
        }
    }
}

const unsigned* screen::getSprite(const char d){
    switch (d) {
        case '0':
            return pixel_zero;
        case '1':
            return pixel_one;
        case '2':
            return pixel_two;
        case '3':
            return pixel_three;
        case '4':
            return pixel_four;
        case '5':
            return pixel_five;
        case '6':
            return pixel_six;
        case '7':
            return pixel_seven;
        case '8':
            return pixel_eight;
        case '9':
            return pixel_nine;
        case 'A':
            return pixel_a;
        case 'B':
            return pixel_b;
        case 'C':
            return pixel_c;
        case 'D':
            return pixel_d;
        case 'E':
            return pixel_e;
        case 'F':
            return pixel_f;
        case 'N':
            return pixel_null;
        default:
            return nullptr;
    }
}


void screen::queueString(const char str[NUM_COLS])
{
    /* This code should be move to set a character to print */
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            for (int i = 0; i < PIXEL_HEIGHT; i++) {
                display[row][col].data[i] = getSprite(str[col])[i];
            }
        }
    }
}

void screen::drawScreen()
{
    for (unsigned row = 0; row < NUM_ROWS; row++) {
        for (unsigned i = 0; i < PIXEL_HEIGHT; i++) {
            for (unsigned col = 0; col < NUM_COLS; col++) {
                printf("%c", (myScreen.display[row][col].data[i] & DIGIT_ONE_MASK) >> 7u ? 0x2A : 0x20);
                printf("%c", (myScreen.display[row][col].data[i] & DIGIT_TWO_MASK) >> 6u ? 0x2A : 0x20);
                printf("%c", (myScreen.display[row][col].data[i] & DIGIT_THREE_MASK) >> 5u ? 0x2A : 0x20);
                printf("%c", (myScreen.display[row][col].data[i] & DIGIT_FOUR_MASK) >> 4u ? 0x2A : 0x20);
            }
            std::cout << "\n";
        }
    }
}

void screen::setupInput()
{
    return;
}







