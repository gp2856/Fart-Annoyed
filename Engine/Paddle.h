#include "Ball.h"
#include "RectF.h"
#include "Colors.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Graphics.h"

class Paddle
{
public:
	Paddle( Vec2 in_pos, float in_half_width, float in_half_height, Color in_color, float in_wing_width, Color in_wing_color);
	void Update(const Keyboard& kbd, const float dt);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
	bool DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	void reset_cooldown();
private:
	float wingWidth;
	float halfWidth;
	float halfHeight;
	Color c;
	Color wingColor;
	Vec2 pos;
	static constexpr float speed = 230.0f;
	bool is_cooldown = false;

};