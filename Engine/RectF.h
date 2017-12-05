#pragma once
#include "Vec2.h"


class RectF
{
public:
	// Constructors
	RectF() = default;
	RectF(float top_in, float bottom_in, float left_in, float right_in);
	RectF(const Vec2& top_left, const Vec2& bottom_right);
	RectF(const Vec2& top_left, float width, float height);

	// Member functions
	//bool IsOverlappingWith(const RectF& other) const;

public:
	float left;
	float right;
	float top;
	float bottom;
};