#include	"raylib.h"
#include	"Configs.h"
#include	"Pages.h"


int main( void ) {
	main_ctx.currentState = MainMenu; // Switch Back to MainMenu

	SetConfigFlags( FLAG_WINDOW_UNDECORATED );
	InitWindow( 1920, 1080, "voids-nexus" );
	SetTargetFPS( 60 );
	SetExitKey( KEY_NULL );

	LoadAssets();

	while ( !WindowShouldClose() && main_ctx.currentState != MainExit ) {
	    mousePos	= GetMousePosition();
		switch( main_ctx.currentState ) {
			case MainMenu:
				MainMenuPage();
				break;
			case MainCharCreator:
				CharCreatorPage();
				break;
			case MainEditor:
				EditorPage();
				break;
			default:
				break;
		}
	}
	UnloadAssets();
	CloseWindow();
	return 0;
}
