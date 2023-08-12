#include <tice.h>
#include <graphx.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TIWIDTH 320
#define TIHEIGHT 240

#define PLAYERX TIWIDTH / 3
#define PLAYERY TIHEIGHT / 2


struct Player {
    int x;
    int y;
    int length;
};

typedef struct Player Player;

void clearScreen(uint8_t* buffer);
void start_draw();
void game_draw();
void gameOver(int score);
void render(int x, int y, int length);

bool isGame = false;
char playerDirection = 'r';
uint8_t buffer1[TIWIDTH * TIHEIGHT * 2];
uint8_t buffer2[TIWIDTH * TIHEIGHT * 2];
uint8_t* activeBuffer = buffer1;

int main(void) {


    Player player;

    player.x = PLAYERX;
    player.y = PLAYERY;
    player.length = 1;

    srand(time(0));


    //Init Buffers

    clearScreen(buffer1);
    clearScreen(buffer2);




    // Clear everything
    os_ClrHome();
    // Draw start menu
    start_draw();
    // Initialize the graphics system
    while (!os_GetCSC());

    //Game start
    clearScreen(activeBuffer);
    activeBuffer = buffer2;
    isGame = true;
    while (isGame) {


        // Detect user input
        if (os_GetCSC() == sk_Up) {
            if (playerDirection != 'd')
                playerDirection = 'u';
            player.y++;
        }
        if (os_GetCSC() == sk_Right) {
            if(playerDirection != 'l')
                playerDirection = 'r';
            player.x++;
        }
        if (os_GetCSC() == sk_Down) {
            if(playerDirection != 'u')
                playerDirection = 'd';
            player.y--;
        }
        if (os_GetCSC() == sk_Left) {
            if(playerDirection != 'r')
                playerDirection = 'l';
            player.x--;
        }

        switch (playerDirection)
        {
            case 'u':
                player.y++;
                    break;
            case 'r':
                player.x++;
                break;
            case 'd':
                player.y--;
                break;
            case 'l':
                player.x--;
                break;
            default:

                isGame = false;
                gfx_End();
                return 0;
                break;
        }

        render(player.x, player.y, player.length);
        clearScreen(activeBuffer);



        if (os_GetCSC() == sk_Suppr) {
            isGame = false;
            gfx_End();
            return 0;
        }
    }

    //Draw game menu
    game_draw();


    // Set style of the screen
    // Update the screen
    gfx_SwapDraw();

    // Wait for a key press before exiting
    while (!(os_GetCSC() == sk_Suppr));

    // Clean up and exit

    gfx_End();
    return 0;
}

void start_draw() {

    gfx_Begin();

    gfx_SetColor(0xFF);
    gfx_PrintStringXY("SNAKE.", 84, 105);

    gfx_PrintStringXY("Press any key to start...", 84, 210);
    gfx_PrintStringXY("BY Guyane", 135, 230);
}

void game_draw() {

    // Draw the background
    gfx_FillScreen(0xC3);

    // Draw The apple
    gfx_SetColor(0xE0);
    gfx_FillCircle(rand() % TIWIDTH, rand() % TIHEIGHT, 10);
    gfx_SetColor(0xFF);
    gfx_SwapDraw();

    // Draw the snake
    gfx_SetColor(0x32);
    gfx_FillRectangle(TIWIDTH / 3, TIHEIGHT / 2, 10, 10);
    gfx_SetColor(0xFF);


}

void gameOver(int score) {


    clearScreen(activeBuffer);
    activeBuffer = buffer1;
    isGame = false;

    gfx_FillScreen(0xFF);
    gfx_PrintStringXY("SNAKE.", TIWIDTH / 2, 105);
    gfx_PrintStringXY("SCORE: ", TIWIDTH / 2, 150);
    gfx_PrintUInt(score, 3);
}


void render(int x, int y, int length) {

    // Draw the snake

    if ((x > TIWIDTH - TIWIDTH & x < TIWIDTH) && (y > TIHEIGHT - TIHEIGHT && y < TIHEIGHT)) {
        gfx_SetColor(0x32);
        gfx_FillRectangle(x, y, length * 10, length * 10);
        gfx_SetColor(0xFF);
    }
    else {
        gameOver(x - TIWIDTH * 3);
    }
}

void clearScreen(uint8_t* buffer) {
    memset(buffer, 0x00, TIWIDTH * TIHEIGHT * 2);
}
