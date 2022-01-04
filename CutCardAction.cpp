#include "CutCardAction.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("CutCardAction: Click on the source card !");
	cardPos = pIn->GetCellClicked();
}
void CutCardAction::Execute()
{
		ReadActionParameters();
	if (cardPos.IsValidCell())
	{
		Grid* pGrid = pManager->GetGrid();
		GameObject* pObj = pGrid->GetGameObjectOfCell(cardPos);
		if (dynamic_cast<Card*>(pObj))
		{
			pObj = pGrid->RemoveObjectFromCell(cardPos);
			pGrid->SetClipboard((Card*)pObj);
		}
	}
}