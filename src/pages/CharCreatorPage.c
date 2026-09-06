#include	"Pages.h"
#include	"Configs.h"
#include	"Colors.h"
#include	"v_gui.h"
#include	"raylib.h"

typedef enum {
	CharCreatorPlayerFirstName,
	CharCreatorPlayerMiddleName,
	CharCreatorPlayerLastName,
	CharCreatorPlayerAge,
	CharCreatorPlayerSex,
	CharCreatorPlayerBackground,
	CharCreatorOptionsCount
} CharCreatorStates;

typedef struct {
	CharCreatorStates	currentIdx;
	char			playerFirstName[ 16 ];
	char			playerMiddleName[ 16 ];
	char			playerLastName[ 16 ];

	int			playerAge;
	_Bool			isMale;
} CharCreatorContext;

static CharCreatorContext char_creator_ctx;

void _updateCreatorPanel( void ) {
	_Bool shiftPressed = IsKeyDown( KEY_LEFT_SHIFT ) || IsKeyDown( KEY_RIGHT_SHIFT );

	if ( IsKeyPressed( KEY_TAB ) ) {
		if ( shiftPressed ) {
			char_creator_ctx.currentIdx = ( char_creator_ctx.currentIdx - 1 + CharCreatorOptionsCount ) % CharCreatorOptionsCount;
		} else {
			char_creator_ctx.currentIdx = ( char_creator_ctx.currentIdx + 1 ) % CharCreatorOptionsCount;
		}
	}
}

void _drawPlayerInfoBar( Rectangle panel ){
	Rectangle playerInf = { panel.x, panel.y, panel.width, 32 };
	DrawPanel( playerInf, ColorBorder, ColorBorder );

	// ====== INPUT RECTS ======
	Rectangle playerNameRec 	= { panel.x + 300, panel.y + 3, 200, 24 };
	Rectangle playerMiddleRec 	= { playerNameRec.x + playerNameRec.width + 150, 				playerNameRec.y, 200, 24
	};
	Rectangle playerLastRec		= { playerMiddleRec.x + playerMiddleRec.width + 150,
		playerMiddleRec.y, 200, 24
	};

	// ====== TEXT ======
	DrawTextEx( mainFont, "First Name", ( Vector2 ){ playerNameRec.x - 90, playerNameRec.y + 5}, 16.0f, 1.0f, ColorPrimaryText
	);
	DrawTextEx( mainFont, "Middle Name", ( Vector2 ){ playerMiddleRec.x - 110, playerMiddleRec.y + 5}, 16.0f, 1.0f, ColorPrimaryText
	);
	DrawTextEx( mainFont, "Last Name", ( Vector2 ){ playerLastRec.x - 90, playerLastRec.y + 5 }, 16.0f, 1.0f, ColorPrimaryText
	);
	// ====== INPUT FIELDS ======
	DrawInput( gameFont, playerNameRec, char_creator_ctx.playerFirstName, 						sizeof(char_creator_ctx.playerFirstName), 16.0f, (char_creator_ctx.currentIdx == 			CharCreatorPlayerFirstName), ColorBorder, ColorInfo, ColorPrimaryText );

	DrawInput( gameFont, playerMiddleRec, char_creator_ctx.playerMiddleName,
		  sizeof( char_creator_ctx.playerMiddleName ), 16.0f, ( char_creator_ctx.currentIdx == CharCreatorPlayerMiddleName), ColorBorder, ColorInfo, ColorPrimaryText );

	DrawInput( gameFont, playerLastRec, char_creator_ctx.playerLastName,
		  sizeof( char_creator_ctx.playerLastName ), 16.0f, ( char_creator_ctx.currentIdx == CharCreatorPlayerLastName), ColorBorder, ColorInfo, ColorPrimaryText
	);

}

void _drawCreatorPanel( void ) {
	BeginDrawing();
		ClearBackground( ColorBg );

		Rectangle backPanel	= { GetScreenWidth()/2 - 800, 0, 1600, GetScreenHeight() };
		DrawPanel( backPanel, ColorBorder, ColorInfo );
		_drawPlayerInfoBar( backPanel );
	EndDrawing();
}

void CharCreatorPage( void ) {
	_updateCreatorPanel();
	_drawCreatorPanel();
}
