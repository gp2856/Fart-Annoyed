#include "Brick.h"
#include <assert.h>

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
		gfx.DrawRect(rect.GetExpanded(-offset), color);
	}
}

void Brick::Destroy()
{
	destroyed = true;
}

bool Brick::CheckBallCollision(Ball & ball) const
{
	return rect.IsOverlappingWith(ball.GetRect()) && !destroyed;
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	assert(CheckBallCollision(ball));

	const Vec2 ball_pos = ball.GetPos();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ball_pos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ball_pos.x >= rect.left && ball_pos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;	
}

bool Brick::IsDestroyed() const
{
	return destroyed;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
