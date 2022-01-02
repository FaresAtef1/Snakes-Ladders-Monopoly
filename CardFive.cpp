#include "CardFive.h"

#include "Player.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

CardFive::~CardFive()
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Move backward with the rolled dice number...");
	CellPosition NewPosition = pPlayer->GetCell()->GetCellPosition();
	NewPosition.AddCellNum(-2 * pPlayer->GetjustRolledDiceNum());
	
	pGrid->UpdatePlayerCell(pPlayer, NewPosition);


}

