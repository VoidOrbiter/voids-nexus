#include	"Pages.h"
#include	"raylib.h"
#include	"Colors.h"
#include	"Configs.h"
#include	"v_gui.h"

void _updateEditorPage( void ) {

}

void _drawEditorPage( void ) {
	BeginDrawing();
		ClearBackground( ColorBg );
	EndDrawing();
}

void EditorPage( void ) {
	_updateEditorPage();
	_drawEditorPage();
}