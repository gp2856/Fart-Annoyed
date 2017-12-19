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

bool Paddle::DoBallCollision(Ball & ball)
{
	RectF rect = GetRect();
	rect.left -= wingWidth;
	rect.right += wingWidth;
	const Vec2 ball_pos = ball.GetPos();
	if (!is_cooldown)
	{
		if (rect.IsOverlappingWith(ball.GetRect()))
		{
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ball_pos - rect.GetCenter()).x))
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
			is_cooldown = true;
			return true;
		}
	}
	return false;
}

bool Paddle::DoWallCollision(const RectF & walls)
{
	bool collided = false;
	RectF rect = GetRect();
	rect.left -= wingWidth;
	rect.right += wingWidth;
	if (rect.left <= walls.left)
	{
		pos.x += walls.left - rect.left;
		collided = true;
	}
	else if (rect.right >= walls.right)
	{
		pos.x -= rect.right - walls.right;
		collided = true;
	}
	return collided;
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}

void Paddle::reset_cooldown()
{
	is_cooldown = false;
}
