#include "Paddle.h"

Paddle::Paddle( Vec2 in_pos, float in_half_width, float in_half_height, Color in_color, float in_wing_width, Color in_wing_color)
:
	pos(in_pos),
	halfWidth(in_half_width),
	halfHeight(in_half_height),
	c(in_color),
	wingWidth(in_wing_width),
	wingColor(in_wing_color)
{
}

void Paddle::Update(const Keyboard & kbd, const float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed(0x41))
	{
		pos.x -= speed * dt;
	}
	else if ( kbd.KeyIsPressed(VK_RIGHT) || kbd.KeyIsPressed(0x44))
	{
		pos.x += speed * dt;
	}
}

void Paddle::Draw(Graphics & gfx) const
{
	RectF rect = GetRect();
	rect.left -= wingWidth;
	rect.right += wingWidth;

	gfx.DrawRect(rect, wingColor);

	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, c);
}

void Paddle::DoBallCollision(Ball & ball) const
{
	RectF rect = GetRect();
	rect.left -= wingWidth;
	rect.right += wingWidth;
	if (rect.IsOverlappingWith(ball.GetRect()) && ball.GetVelocity().y >= 0)
	{
		ball.ReboundY();
	}
}

void Paddle::DoWallCollision(const RectF & walls)
{
	RectF rect = GetRect();
	rect.left -= wingWidth;
	rect.right += wingWidth;
	if (rect.left <= walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right >= walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
