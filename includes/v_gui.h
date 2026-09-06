#ifndef V_GUI_H
#define V_GUI_H

#include	"raylib.h"

typedef struct {
	Rectangle	rec;

	_Bool		isLeftPressed;
	_Bool		isLeftReleased;

	_Bool		isRightPressed;
	_Bool		isRightReleased;

	_Bool		isHovered;
} Button;

typedef struct {
	float		topBarHeight;
	float		bottomPanelHeight;
} UIContext;

void ResetUI( void );

Rectangle DrawPanel( Rectangle rec, Color outline, Color innerOutline );
Rectangle DrawRightPanel( int w, Color outline, Color innerOutline );
Rectangle DrawLeftPanel( int w, Color outline, Color innerOutline );
Rectangle DrawTopBar( int h, Color outline, Color innerOutline );
Rectangle DrawBottomPanel( int h, Color outline, Color innerOutline );

Button DrawButton(
	Font		font,
	Rectangle	rec,
	const char	*text,
	float		fontSize,
	Color		outlineColor,
	Color		outlineHover,
	Color		textColor
);

void DrawInput(
	Font		font,
	Rectangle	rec,
	char 		*buffer,
	int		bufferSize,
	float		fontSize,
	_Bool		isActive,
	Color		outlineColor,
	Color		outlineActive,
	Color		textColor
);

#endif
