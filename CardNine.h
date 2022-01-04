#pragma once
#include "Card.h"
class CardNine : public Card
{
	static int CardPrice;
	static int Fees;
	static Player* Owner;
public:
	CardNine(const CellPosition & cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid,Player* pPlayer);
	virtual void Save(ofstream& OutFile, int Type);

};

