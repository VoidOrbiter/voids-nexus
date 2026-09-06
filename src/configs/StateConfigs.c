#include	"Configs.h"

MainContext	main_ctx	= { 0 };

void ChangePage( MainStates next_state ) {
	main_ctx.currentState = next_state;
}
