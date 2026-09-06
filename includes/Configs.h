#ifndef CONFIGS_H
#define CONFIGS_H

#include	"raylib.h"

typedef enum {
	MainMenu,
	MainCharCreator,
	MainLoadGame,
	MainSettings,
	MainEditor,
	MainPlaying,
	MainExit
} MainStates;

typedef struct {
	MainStates	currentState;
} MainContext;

extern MainContext main_ctx;

void ChangePage( MainStates next_state );

// ====== ASSET CONFIGS ======
extern	Font		mainFont;
extern 	Font		gameFont;

void LoadAssets( void );
void UnloadAssets( void );

// ====== CONTROL CONFIGS =====
extern	Vector2		mousePos;

#endif
