#pragma once
#include "Card.h"
class CardTen : public Card
{
	static int CardPrice;
	static int Fees;
	static Player* Owner;
public:
	CardTen(const CellPosition& cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, int Type);

};

