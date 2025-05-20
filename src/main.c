#include <genesis.h>
#include <resources.h>

Sprite* ball;

int main()
{

	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();

	ball = SPR_addSprite(&imgball, 100, 100, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

	VDP_loadTileSet(bgtile.tileset,1,DMA);
	PAL_setPalette(PAL1, bgtile.palette->data,DMA);
	VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);

    while(1)
    {

		SPR_update();
		SYS_doVBlankProcess();
    }
    return (0);
}
