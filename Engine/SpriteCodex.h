#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vec2& center,Graphics& gfx );
	static void draw_title(const int x, const int y, Graphics& gfx);
	static void draw_game_over(const int x, const int y, Graphics& gfx);
};