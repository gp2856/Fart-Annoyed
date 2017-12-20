#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Colors.h"

class wall
{
public:
	wall(const float x, const float y);
	RectF get_inner_bounds() const;
	void draw_wall(Graphics& gfx) const;
private:
	RectF bounds_;
	static constexpr Color border_color = Colors::Blue;
	static constexpr float border_width = 4.0f;
	static constexpr float border_padding = 2.0f;
	static constexpr int width = 24;
	static constexpr int height = 24;
	static constexpr int dimension = 10;
};
