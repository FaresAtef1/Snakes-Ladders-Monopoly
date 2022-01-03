#pragma once
#include "Card.h"
class CardTwelve :public Card
{
	CardTwelve(const CellPosition& cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
};

