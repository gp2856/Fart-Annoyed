#include "walls.h"

wall::wall(const float x, const float y)
{
	bounds_.top = y;
	bounds_.left = x;
	bounds_.bottom = bounds_.top + (border_width + border_padding) * 2 + (height);
	bounds_.right = bounds_.left + (border_width + border_padding) * 2 + (width);
}

RectF wall::get_inner_bounds() const
{
	return bounds_;
}

void wall::draw_wall(Graphics & gfx) const
{
	// top
	gfx.DrawRect(bounds_.left, bounds_.top, bounds_.right, bounds_.top + border_width, border_color);
	// bounds_.left
	gfx.DrawRect(bounds_.left, bounds_.top + border_width, bounds_.left + border_width, bounds_.bottom - border_width, border_color);
	// bounds_.right
	gfx.DrawRect(bounds_.right - border_width, bounds_.top + border_width, bounds_.right, bounds_.bottom - border_width, border_color);
	// bounds_.bottom
	gfx.DrawRect(bounds_.left, bounds_.bottom - border_width, bounds_.right, bounds_.bottom, border_color);
}
