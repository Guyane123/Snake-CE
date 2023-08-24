#include <tice.h>;
#include <stdlib.h>
#include <keypadc.h>;
#include <player.hpp>
#include <graphx.h>;
#include <ctime>;


Player player;


void handleMovement(void) {
	if (kb_Data[7] & kb_Left) {
		player.Move()
	}
	else if (kb_Data[7] & kb_Right) {
	}
	else if (kb_Data[7] & kb_Up) {
	}
	else if (kb_Data[7] & kb_Down) {
	}
	else {
	}
}


int main() {


	srand(time(0));
	bool game = false;
	kb_key_t keyPressed;


	gfx_Begin();
	drawMenu();

	do {
		//render();
		kb_Scan();

		gfx_SetDrawBuffer();
		gfx_FillScreen(0);

		keyPressed = kb_Data[7];



		switch (keyPressed)
		{
		case kb_Left:
			//go left
			break;
		case kb_Right:
			//go Right
			break;
		case kb_Up:
			//go Up
			break;
		case kb_Down:
			//go Down
			break;
		case kb_Mode:
			//quit
			game = false;

		default:
			break;
		}
	} while (kb_Data[1] != kb_Annul);



	gfx_End();
	return 0;
}


void stop() {

}
void drawMenu() {
	// Draw the background
	gfx_FillScreen(0xC3);

	// Draw The apple
	gfx_SetColor(0xE0);
	gfx_FillCircle(rand() % GFX_LCD_WIDTH, rand() % GFX_LCD_HEIGHT, 10);
	gfx_SetColor(0xFF);
	gfx_SwapDraw();

	// Draw the snake
	gfx_SetColor(0x32);
	gfx_FillRectangle(GFX_LCD_WIDTH / 3, GFX_LCD_WIDTH / 2, 10, 10);
	gfx_SetColor(0xFF);
}