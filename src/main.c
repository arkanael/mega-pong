#include <genesis.h>
#include <resources.h>

Sprite* ball;
Sprite* player;

/*VARIAVEIS PARA DEFINIR A BOLA*/
int ball_pos_x = 100;
int ball_pos_y = 100;
int ball_vel_x = 1;
int ball_vel_y = 1;
int ball_width = 8;
int ball_height = 8;

/*VARIAVEIS PARA DEFINIR O PLAYER*/
int player_pos_x = 144;
const int player_pos_y = 200;
int player_vel_x = 0;
const int player_width = 32;
const int player_height = 8;

/*CONSTANTES PARA FAZER A BOLA QUICAR*/
const int LEFT_EDGE = 0;
const int RIGHT_EDGE = 320;
const int TOP_EDGE = 0;
const int BOTTOM_EDGE = 224;

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

void joyHandler (u16 joy,u16 changed, u16 state)
{
	/*Set player velocity if left or right are pressed;
		*set velocity to 0 if no direction is pressed */
		if (state & BUTTON_RIGHT)
		{
			player_vel_x = 3;
		}
		else if (state & BUTTON_LEFT)
		{
			player_vel_x = -3;
		} else{
			if( (changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) ){
				player_vel_x = 0;
			}
		}
}

void positionPlayer(){
	/*Add the player's velocity to its position*/
	player_pos_x += player_vel_x;

	/*Keep the player within the bounds of the screen*/
	if(player_pos_x < LEFT_EDGE) player_pos_x = LEFT_EDGE;
	if(player_pos_x + player_width > RIGHT_EDGE) player_pos_x = RIGHT_EDGE - player_width;

	/*Let the Sprite engine position the sprite*/
	SPR_setPosition(player,player_pos_x,player_pos_y);
}
int main()
{

	SPR_init();
	JOY_init();

	JOY_setEventHandler(&joyHandler);

	VDP_setScreenWidth320();
	VDP_setScreenHeight224();

	ball = SPR_addSprite(&imgball, 100, 100, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
	player = SPR_addSprite(&paddle, player_pos_x, player_pos_y, TILE_ATTR(PAL1, 0, FALSE, FALSE));

	VDP_loadTileSet(bgtile.tileset,1,DMA);
	PAL_setPalette(PAL1, bgtile.palette->data,DMA);
	VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);

    while(1)
    {

		moveBall();
		positionPlayer();
		SPR_update();
		SYS_doVBlankProcess();
    }
    return (0);
}
