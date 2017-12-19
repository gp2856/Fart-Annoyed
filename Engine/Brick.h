#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
#include "Vec2.h"


class Brick
{
public:
	Brick() = default;
	Brick(RectF& in_rect, const Color in_color);
	void Draw(Graphics& gfx) const;
	void Destroy();
	bool CheckBallCollision(Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	bool IsDestroyed() const;
	Vec2 GetCenter() const;

private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float offset = 3.0f;

};