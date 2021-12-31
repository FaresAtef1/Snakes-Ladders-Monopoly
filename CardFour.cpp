#include "CardFour.h"
CardFour::CardFour(const CellPosition& cellposition) : Card(cellposition){
	cardNumber = 4;
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer) {
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You've reached card 4 ! prevents you from rolling next turn...");
	pPlayer->SetTurnsDisabled(1);

}