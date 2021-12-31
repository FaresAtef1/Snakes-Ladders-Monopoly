#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& cellposition) : Card(cellposition) {
	cardNumber = 2;
}

void CardTwo::Apply(Grid* pGrid,Player* pPlayer) {
	Ladder* P = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	pGrid->UpdatePlayerCell(pPlayer, P->GetPosition());
	pGrid->PrintErrorMessage("You've reached card 2 !  moving to the next ladder, click anywhere to continue...");
	P->Apply(pGrid,pPlayer);
 }