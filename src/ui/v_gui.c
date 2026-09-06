#include	"v_gui.h"
#include	<string.h>

UIContext ui_ctx;

void ResetUI( void ) {
	ui_ctx.topBarHeight		= 0;
	ui_ctx.bottomPanelHeight	= 0;
}

Rectangle DrawPanel( Rectangle rec, Color outline, Color innerOutline ) {
	Rectangle innerRect = { rec.x + 3, rec.y + 3, rec.width - 6, rec.height - 6 };

	DrawRectangleLinesEx( rec, 1.0f, outline );
	DrawRectangleLinesEx( innerRect, 1.0f, innerOutline );

	return rec;
}

Rectangle DrawRightPanel( int w, Color outline, Color innerOutline ) {
	float	start_y	= ui_ctx.topBarHeight;
	float	end_h	= ui_ctx.topBarHeight + ui_ctx.bottomPanelHeight;
	float	start_x	= GetScreenWidth() - w;

	Rectangle rp = { start_x, start_y, w, GetScreenHeight() - end_h };
	DrawPanel( rp, outline, innerOutline );

	return rp;
}

Rectangle DrawLeftPanel( int w, Color outline, Color innerOutline ) {
	float	start_y = ui_ctx.topBarHeight;
	float	end_h	= ui_ctx.topBarHeight + ui_ctx.bottomPanelHeight;

	Rectangle lp = { 0, start_y, w, GetScreenHeight() - end_h };
	DrawPanel( lp, outline, innerOutline );

	return lp;
}

Rectangle DrawTopBar( int h, Color outline, Color innerOutline ) {
	ui_ctx.topBarHeight = h;

	Rectangle tb = { 0, 0, GetScreenWidth(), h };
	DrawPanel( tb, outline, innerOutline );

	return tb;
}

Rectangle DrawBottomPanel( int h, Color outline, Color innerOutline ) {
	ui_ctx.bottomPanelHeight = h;
	float start_y = GetScreenHeight() - h;

	Rectangle bp = { 0, start_y, GetScreenWidth(), h };
	DrawPanel( bp, outline, innerOutline );

	return bp;
}

void DrawInput(
	Font		font,
	Rectangle	rec,
	char		*buffer,
	int		bufferSize,
	float		fontSize,
	_Bool		isActive,
	Color		outlineColor,
	Color		outlineActive,
	Color		textColor
) {
	if ( isActive ) {
		int len = ( int )strlen( buffer );

		int key = GetCharPressed();
		while ( key > 0 ) {
			if (( key >= 32 ) && ( key <= 125 ) && (len < bufferSize - 1 )) {
				buffer[ len ] = ( char )key;
				buffer[ len + 1] = '\0';
				len++;
			}
			key = GetCharPressed();
		}

		// === USING MANUAL BACKSPACE SOME REASON IsKeyPressedRepeat DOESN'T WORK ==='
		static 	float 	backspaceTimer 	= 0.0f;
		const	float	initialDelay	= 0.3f;
		const	float	repeatRate	= 0.03f;

		if ( IsKeyPressed( KEY_BACKSPACE ) && len > 0 ) {
			buffer[ len - 1 ] = '\0';
			len--;
			backspaceTimer	= 0.0f;
		}
		else if ( IsKeyDown( KEY_BACKSPACE ) && len > 0 ) {
			backspaceTimer += GetFrameTime();

			if ( backspaceTimer >= initialDelay ) {
				buffer[ len - 1 ] = '\0';
				len--;
				backspaceTimer = initialDelay - repeatRate;
			}
		}
		else if ( IsKeyReleased( KEY_BACKSPACE ) ) {
			backspaceTimer = 0.0f;
		}
	}

	Color outline = isActive ? outlineActive : outlineColor;
	DrawRectangleLinesEx( rec, 1.0f, outline );

	float 	padding 	= 8.0f;
	float 	maxTextWidth 	= rec.width - ( padding * 2.0f );
	Vector2 textSize	= MeasureTextEx( font, buffer, fontSize, 1.0f );

	float drawX = rec.x + padding;
	if ( textSize.x > maxTextWidth ) {
		drawX -= ( textSize.x - maxTextWidth );
	}

	BeginScissorMode( ( int )rec.x, ( int )rec.y, ( int )rec.width, ( int )rec.height );
		Vector2 textPos = { drawX, rec.y + ( rec.height - fontSize ) / 2.0f };
		DrawTextEx(font, buffer, textPos, fontSize, 1.0f, textColor );
	EndScissorMode();
}
