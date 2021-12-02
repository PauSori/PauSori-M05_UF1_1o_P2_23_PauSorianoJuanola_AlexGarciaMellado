#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include <stdlib.h>
#include <time.h>
class FantasmasAlex
{
private:
	COORD spawn;
	COORD position;
	COORD direction;
	char character = 'A';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
	void RandomDirection();

public:
	enum ENEMY_STATE {ENEMY_NONE, ENEMY_KILLED, ENEMY_DEAD};
	FantasmasAlex();
	FantasmasAlex(COORD _spawn);
	void Draw();
	ENEMY_STATE Update(Map*_map, COORD _player);
};
