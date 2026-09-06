#include	"raylib.h"
#include	"Pages.h"
#include	"Colors.h"
#include	"Configs.h"
#include	"v_gui.h"

typedef enum {
	MainMenuNewGame,
	MainMenuLoadGame,
	MainMenuDevMode,
	MainMenuSettings,
	MainMenuExit,
	MainMenuOptionsCount
} MainMenuOptions;

typedef struct {
	MainMenuOptions currentIdx;
} MainMenuContext;

static MainMenuContext menuCtx = { MainMenuNewGame };

static const char *menuLabel[ MainMenuOptionsCount ] = {
	"New Game",
	"Load Game",
	"Dev Mode",
	"Settings",
	"Exit"
};

void _updateMainMenu() {
	_Bool shiftPressed = IsKeyDown( KEY_LEFT_SHIFT ) || IsKeyDown( KEY_RIGHT_SHIFT );

	if ( IsKeyPressed( KEY_TAB ) ) {
		if ( shiftPressed ) {
			menuCtx.currentIdx = ( menuCtx.currentIdx - 1 + MainMenuOptionsCount ) % MainMenuOptionsCount;
		} else {
			menuCtx.currentIdx = ( menuCtx.currentIdx + 1 ) % MainMenuOptionsCount;
		}
	}

	if ( IsKeyPressed( KEY_DOWN ) ) {
		menuCtx.currentIdx = ( menuCtx.currentIdx + 1 ) % MainMenuOptionsCount;
	}
	if ( IsKeyPressed( KEY_UP ) ) {
		menuCtx.currentIdx = ( menuCtx.currentIdx - 1 + MainMenuOptionsCount ) % MainMenuOptionsCount;
	}

	if ( IsKeyPressed( KEY_ENTER ) || IsKeyPressed( KEY_KP_ENTER ) ) {
		switch ( menuCtx.currentIdx ) {
			case MainMenuNewGame:
				main_ctx.currentState = MainCharCreator;
				break;
			case MainMenuExit:
				main_ctx.currentState = MainExit;
			default:
				break;
		}
	}
}

void _drawMainMenu() {
	BeginDrawing();
		ClearBackground( ColorBg );
		const char *titleText = "Void's Nexus";
		Vector2 titleSize = MeasureTextEx( mainFont, titleText, 32.0f, 1.0f );
		float titleX = ( GetScreenWidth() - titleSize.x ) / 2.0f;
		float titleY = ( GetScreenHeight() - titleSize.y ) / 2.0f;
		DrawTextEx( mainFont, titleText, ( Vector2 ){ titleX, titleY }, 32.0f, 1.0f, ColorPrimaryText );

		int startX 	= GetScreenWidth() - 100;
		int startY 	= GetScreenHeight() / 2;
		int fontSize 	= 16;
		int itemSpacing	= 40;

		for ( int i = 0; i < MainMenuOptionsCount; i++ ) {
			_Bool isSelected = ( menuCtx.currentIdx == ( MainMenuOptions )i);

			Color textColor = isSelected ? ColorPrimaryText : ColorSecondaryText;

			const char *text = menuLabel[ i ];

			if ( isSelected ) {
				DrawTextEx( mainFont, "> ", ( Vector2 ){ startX - 25, startY + ( i * itemSpacing ) }, fontSize, 1.0f, ColorPrimaryText);
			}
			DrawTextEx( mainFont, text, ( Vector2 ){ startX, startY + (i * itemSpacing)}, fontSize, 1.0f, textColor);
		}

	EndDrawing();
}

void MainMenuPage( void ) {
	_updateMainMenu();
	_drawMainMenu();
}
