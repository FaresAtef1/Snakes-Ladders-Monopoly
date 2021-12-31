#include "CardThree.h"
CardThree::CardThree(const CellPosition& cellposition) : Card(cellposition) {
	cardNumber = 3;
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->DecrementCurrPlayer();
	pGrid->PrintErrorMessage("You've reached card 3 ! You get another turn, click anywhere to continue...");
 }