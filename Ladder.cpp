#include "Ladder.h"


Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}


bool Ladder::IsOverlapping(GameObject* newObj) const {



	if (newObj->GetPosition().VCell() == GetEndPosition().VCell())
		return true;

	Ladder* pLad = dynamic_cast<Ladder*>(newObj);
	if (pLad) {
		if (pLad->GetEndPosition().VCell() <= GetPosition().VCell() && pLad->GetPosition().VCell() >= GetPosition().VCell()) {
			return true;
		}
		if (GetEndPosition().VCell() <= newObj->GetPosition().VCell() && GetPosition().VCell() >= newObj->GetPosition().VCell()) {
			return true;
		}
	}

	return false;
}





Ladder::~Ladder()
{
}