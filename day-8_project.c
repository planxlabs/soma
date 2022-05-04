#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define WIDTH       10
#define HEIGHT      10
#define SCREEN_SIZE WIDTH * HEIGHT

#define array_size(ar) (sizeof(ar) / sizeof(ar[0]))

static uint8_t screen[SCREEN_SIZE];

void clear_screen()
{
    printf("\033[H\033[2J");
    printf("\033[36m");
}

void text_color(uint8_t r, uint8_t g, uint8_t b)
{
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void background_color(uint8_t r, uint8_t g, uint8_t b)
{
    printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void reset_color()
{
    printf("\033[0m");
}

void display()
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", screen[y * WIDTH + x]);
        }
        printf("\n");
    }
}

int main()
{
    memset(screen, '.', array_size(screen));
    
    int step = 2;
    char (*p)[step] = (char (*)[step])screen;

    for (int pos = 0; pos < SCREEN_SIZE / step; pos++) {
        *p[pos] = '*';
    }

    clear_screen();
    text_color(0,0,255);
    background_color(255,255,0);    
    display();
    reset_color();
}
