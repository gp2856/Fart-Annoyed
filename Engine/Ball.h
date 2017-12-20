#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Vec2.h"


class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	int DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPos() const;
private:
	enum collision_type { left, right, top, bottom };
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;

};