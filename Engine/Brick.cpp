#include "Brick.h"

Brick::Brick(RectF & in_rect, const Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect, color);
	}
}

void Brick::Destroy()
{
	destroyed = true;
}

bool Brick::DoBallCollision(Ball & ball)
{
	if (rect.IsOverlappingWith(ball.GetRect()) && !destroyed)
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
}
