#pragma once
#include"Card.h"
class CardThree : public Card
{
public:
	CardThree(const CellPosition& cellposition);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	
};

