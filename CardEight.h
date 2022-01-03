#pragma once
#include"Card.h"

class CardEight : public Card
{
	int Amount;
public:
	CardEight(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight();

};
