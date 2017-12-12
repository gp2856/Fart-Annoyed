#include "Brick.h"

Brick::Brick(RectF & in_rect, const Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, color);
}
