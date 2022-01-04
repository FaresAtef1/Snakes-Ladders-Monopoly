#pragma once
#include "Card.h"
class CardEleven : public Card
{
	static int CardPrice;
	static int Fees;
	static bool Placed;
	static bool Owned;
	static Player* Owner;
public:
	CardEleven(const CellPosition& cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	Player* GetOwner();
	void SetOwner(Player* pNew);
	int GetCardPrice();
};

