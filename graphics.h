#ifndef GRAPHICS_H
#define GRAPHICS_H

#define SCREEN_SIZE 64*32
//#define NUM_ROWS 32
//#define NUM_COLS 64
#define NUM_ROWS 1
#define NUM_COLS 8
#define PIXEL_WIDTH 4
#define PIXEL_HEIGHT 5

#define DIGIT_ONE_MASK 0x80u
#define DIGIT_TWO_MASK 0x40u
#define DIGIT_THREE_MASK 0x20u
#define DIGIT_FOUR_MASK 0x10u

const unsigned pixel_null   [PIXEL_HEIGHT] = {0x00, 0x00, 0x00, 0x00, 0x00};
const unsigned pixel_zero   [PIXEL_HEIGHT] = {0xF0, 0x90, 0x90, 0x90, 0xF0};
const unsigned pixel_one    [PIXEL_HEIGHT] = {0x20, 0x60, 0x20, 0x20, 0x70};
const unsigned pixel_two    [PIXEL_HEIGHT] = {0xF0, 0x10, 0xF0, 0x80, 0xF0};
const unsigned pixel_three  [PIXEL_HEIGHT] = {0xF0, 0x10, 0xF0, 0x10, 0xF0};
const unsigned pixel_four   [PIXEL_HEIGHT] = {0x90, 0x90, 0xF0, 0x10, 0x10};
const unsigned pixel_five   [PIXEL_HEIGHT] = {0xF0, 0x80, 0xF0, 0x10, 0xF0};
const unsigned pixel_six    [PIXEL_HEIGHT] = {0xF0, 0x80, 0xF0, 0x90, 0xF0};
const unsigned pixel_seven  [PIXEL_HEIGHT] = {0xF0, 0x10, 0x20, 0x40, 0x40};
const unsigned pixel_eight  [PIXEL_HEIGHT] = {0xF0, 0x90, 0xF0, 0x90, 0xF0};
const unsigned pixel_nine   [PIXEL_HEIGHT] = {0xF0, 0x90, 0xF0, 0x10, 0xF0};
const unsigned pixel_a      [PIXEL_HEIGHT] = {0xF0, 0x90, 0xF0, 0x90, 0x90};
const unsigned pixel_b      [PIXEL_HEIGHT] = {0xE0, 0x90, 0xE0, 0x90, 0xE0};
const unsigned pixel_c      [PIXEL_HEIGHT] = {0xF0, 0x80, 0x80, 0x80, 0xF0};
const unsigned pixel_d      [PIXEL_HEIGHT] = {0xE0, 0x90, 0x90, 0x90, 0xE0};
const unsigned pixel_e      [PIXEL_HEIGHT] = {0xF0, 0x80, 0xF0, 0x80, 0xF0};
const unsigned pixel_f      [PIXEL_HEIGHT] = {0xF0, 0x80, 0xF0, 0x80, 0x80};


struct pixel
{
    unsigned data[PIXEL_HEIGHT];
};

struct screen
{
    pixel display[NUM_ROWS][NUM_COLS];
    int curr_row;
    int curr_col;

    void setupGraphics();
    void setupInput();
    static void drawScreen();
    void queueString(const char str[NUM_COLS]);

    static const unsigned int * getSprite(const char d);
} myScreen;
#endif // GRAPHICS_H