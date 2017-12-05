#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2 & top_left, const Vec2 & bottom_right)
{
	RectF(top_left.x, bottom_right.x, top_left.y, bottom_right.y);
}

RectF::RectF(const Vec2 & top_left, float width, float height)
{
	RectF(top_left, top_left + Vec2(width, height));
}
