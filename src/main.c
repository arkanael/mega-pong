#include <genesis.h>
#include <resources.h>

Sprite* ball;

int ball_pos_x = 100;
int ball_pos_y = 100;
int ball_vel_x = 1;
int ball_vel_y = 1;
int ball_width = 8;
int ball_height = 8;

/*CONSTANTES PARA FAZER A BOLA QUICAR*/
const int LEFT_EDGE = 0;
const int RIGHT_EDGE = 320;
const int TOP_EDGE = 0;
const int BOTTOM_EDGE = 224;

int main()
{

	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();

	ball = SPR_addSprite(&imgball, 100, 100, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

	VDP_loadTileSet(bgtile.tileset,1,DMA);
	PAL_setPalette(PAL1, bgtile.palette->data,DMA);
	VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);



	/*FUNCOES */

	/*MOVER A BOLA*/
	void moveBall()
	{
		if(ball_pos_x <= LEFT_EDGE || ball_pos_x >= RIGHT_EDGE - ball_width)
		{
			ball_vel_x = -ball_vel_x;
		}else if(ball_pos_y <= TOP_EDGE || ball_pos_y >= BOTTOM_EDGE - ball_height)
		{
			ball_vel_y = -ball_vel_y;
		}

		ball_pos_x += ball_vel_x;
		ball_pos_y += ball_vel_y;

		SPR_setPosition(ball, ball_pos_x, ball_pos_y);
	}

    while(1)
    {

		moveBall();
		SPR_update();
		SYS_doVBlankProcess();
    }
    return (0);
}
