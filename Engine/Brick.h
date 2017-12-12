#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(RectF& in_rect, const Color in_color);
	void Draw(Graphics& gfx) const;
public:
	RectF rect;
	Color color;
	bool destroyed = false;

};