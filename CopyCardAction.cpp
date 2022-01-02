#include "CopyCardAction.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
}
	
void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell !");
	CellPosition cellPosition = pIn->GetCellClicked();
	GameObject* pObj = pGrid->GetGameObjectOfCell(cellPosition);
	Card* CopiedCard = dynamic_cast<Card*>(pObj);
	if (CopiedCard) 
	{
		pGrid->SetClipboard(CopiedCard);
	}
}