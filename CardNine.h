#pragma once
#include "Card.h"
class CardNine : public Card
{
	static int CardPrice;
	static int Fees;
	static Player* Owner;
	static bool IsSaved;
public:
	CardNine(const CellPosition & cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid,Player* pPlayer);
	Player* GetOwner();
	void SetOwner(Player* pNew);
	int GetCardPrice();
	virtual void Save(ofstream& OutFile, int Type);

};

