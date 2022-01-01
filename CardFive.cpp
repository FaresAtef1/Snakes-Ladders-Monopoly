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

	/*pPlayer->Move(pGrid, (-2 * pPlayer->GetjustRolledDiceNum()));*/

}

