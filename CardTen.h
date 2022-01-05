#pragma once
#include "Card.h"
class CardTen : public Card
{
	static int CardPrice;
	static int Fees;
	static Player* Owner;
	static bool IsSaved ;

public:
	CardTen(const CellPosition& cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	Player* GetOwner();
	void SetOwner(Player* pNew);
	int GetCardPrice();
	virtual void Save(ofstream& OutFile, int Type);

};

