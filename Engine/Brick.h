#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& in_rect, const Color in_color);
	void Draw(Graphics& gfx) const;
	void Destroy();
	void DoBallCollision(Ball& ball);
private:
	RectF rect;
	Color color;
	bool destroyed = false;

};