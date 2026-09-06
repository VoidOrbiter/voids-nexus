#ifndef COLORS_H
#define COLORS_H

#include    "raylib.h"

#define C( hex ) GetColor( hex )

#define ColorBg			C( 0x121212FF )
#define ColorBorder		C( 0x616161FF )
#define ColorSecondaryText	C( 0xA0A0A0FF )
#define ColorPrimaryText	C( 0xFFFFFFFF )

#define ColorCrit		C( 0xFF2B2BFF )
#define ColorWarn		C( 0xFFB800FF )
#define ColorSucc		C( 0x00E676FF )
#define ColorInfo		C( 0x00B0FFFF )

#endif
