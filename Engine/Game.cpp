/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Vec2.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	walls(0.0f, (float)gfx.ScreenWidth, 0.0f, (float)gfx.ScreenHeight),
	a_ball(Vec2(240.0f, 240.0f), Vec2(300.0f, -300.0f)),
	paddle(Vec2((Graphics::ScreenWidth / 2), (Graphics::ScreenHeight - 100)), 50, 10, Colors::White, 8.0f, Colors::Red),
	brickSound(L"Sounds\\arkbrick.wav"),
	padSound(L"Sounds\\arkpad.wav")
	
{
	const Color colors[4] = { Colors::Red, Colors::Green, Colors::Blue, Colors::Cyan };

	const Vec2 topLeft(100.0f, 100.0f);
	int i = 0;

	for (int y = 0; y < nBricksDown; y++)
	{
		const Color c = colors[y];
		for (int x = 0; x < nBricksAcross; x++)
		{
			bricks[i] = Brick(RectF(
				topLeft + Vec2(x * brickWidth, y * brickHeight), 
				brickWidth, brickHeight ), c);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsed = ft.Mark();
	while (elapsed > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsed);
		UpdateModel(dt);
		elapsed -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{

	a_ball.Update(dt);
	a_ball.DoWallCollision(walls);
	paddle.Update(wnd.kbd, dt);
	if (paddle.DoBallCollision(a_ball))
	{
		padSound.Play();
	}
	paddle.DoWallCollision(walls);


	bool collision_happened = false;
	float cur_col_dist_sq;
	int cur_col_index;

	for (int i = 0; i < nBricks; i++)
	{
		if (bricks[i].CheckBallCollision(a_ball))
		{
			const float new_col_dist_sq = (a_ball.GetPos() - bricks[i].GetCenter()).GetLengthSq();
			
			if (collision_happened)
			{
				if (new_col_dist_sq > cur_col_dist_sq)
				{
					cur_col_dist_sq = new_col_dist_sq;
					cur_col_index = i;
				}
			}
			else
			{
				cur_col_dist_sq = new_col_dist_sq;
				cur_col_index = i;
				collision_happened = true;
			}
		}
	}
	if (collision_happened)
	{
		bricks[cur_col_index].ExecuteBallCollision(a_ball);
		score += 10;
		brickSound.Play();
	}
}

void Game::ComposeFrame()
{
	a_ball.Draw(gfx);
	paddle.Draw(gfx);

	for (const Brick& b : bricks)
	{
		b.Draw(gfx);
	}
}
