#include "CopyCardAction.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	
}
void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("CopyCardAction: Click on the source card !");
    cardPos = pIn->GetCellClicked();
}
void CopyCardAction::Execute()
{
		ReadActionParameters();
	if (cardPos.IsValidCell()) {
		Grid* pGrid = pManager->GetGrid();
		GameObject* pObj = pGrid->GetGameObjectOfCell(cardPos);
		if (dynamic_cast<Card*>(pObj))
		{
			pGrid->SetClipboard((Card*)pObj);
		}
	}
}