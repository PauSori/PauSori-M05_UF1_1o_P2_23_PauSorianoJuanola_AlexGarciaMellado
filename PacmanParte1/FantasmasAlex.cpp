#include "FantasmasAlex.h"

void FantasmasAlex::RandomDirection()
{
	direction = { 0,0 };
	int random = rand() % 4;
	switch (random)
	{
	case 0:
		direction.X = 1;
		break;
	case 1:
		direction.X = -1;
		break;
		direction.X = 1;
	case 2:
		direction.Y = 1;
		break;
	case 3:
		direction.Y = -1;
		break;
	}
}

FantasmasAlex::FantasmasAlex()
{
	spawn = {0,0};
	position = { 10,5 };
	direction = { 0,1 };
}
FantasmasAlex:: FantasmasAlex(COORD _spawn)
	{
	spawn = _spawn;
		position = _spawn;
		direction = { 0,0 };
	}
	

void FantasmasAlex::Draw()
{
	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;

}

FantasmasAlex::ENEMY_STATE FantasmasAlex::Update(Map* _map, COORD _player)
{
	RandomDirection();
	COORD newPosition = position;
	newPosition.X += direction.X;
	newPosition.Y += direction.Y;

	if (newPosition.X < 0)
	{
		newPosition.X = _map->Width - 1;
	}
	newPosition.X %= _map->Width;
	if (newPosition.Y < 0)
	{
		newPosition.Y = _map->Height - 1;
	}
	newPosition.Y %= _map->Height;

	switch (_map->GetTile(newPosition.X, newPosition.Y))
	{
	case Map::MAP_TILES::MAP_WALL:
		newPosition = position;
		break;
	}
	position = newPosition;


	ENEMY_STATE state = ENEMY_STATE::ENEMY_NONE;
	if (position.X == _player.X && position.Y == _player.Y) {
		position = spawn;
		state = ENEMY_STATE::ENEMY_KILLED;
	}
	return state;
}


