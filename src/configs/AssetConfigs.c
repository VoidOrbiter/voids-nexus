#include	"Configs.h"

Font		mainFont	= { 0 };
Font		gameFont	= { 0 };

void LoadAssets( void ) {
	mainFont	= LoadFont("resources/fonts/Xolonium-pn4D.ttf");
	SetTextureFilter( mainFont.texture, TEXTURE_FILTER_POINT );
	gameFont	= LoadFont("resources/fonts/Perfect DOS VGA 437 Win.ttf");
	SetTextureFilter( gameFont.texture, TEXTURE_FILTER_POINT );
}

void UnloadAssets( void ) {
	UnloadFont( mainFont );
	UnloadFont( gameFont );
}
