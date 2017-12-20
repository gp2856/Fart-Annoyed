#include "Ball.h"
#include "SpriteCodex.h"
#include "RectF.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

int Ball::DoWallCollision(const RectF & walls)
{
	const RectF rect = GetRect();
	int collision_type = -1;

	if (rect.left <= walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collision_type = left;
	}
	else if (rect.right >= walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collision_type = right;
	}
	if (rect.top <= walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collision_type = top;
	}
	else if (rect.bottom >= walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collision_type = bottom;
	}
	return collision_type;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetPos() const
{
	return pos;
}
