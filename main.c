#include	"raylib.h"

int main( void ) {
	InitWindow( 1920, 1080, "voids-nexus" );
	SetTargetFPS( 60 );
	SetExitKey( KEY_NULL );

	while ( !WindowShouldClose() ) {
		BeginDrawing();
			ClearBackground( BLACK );
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
