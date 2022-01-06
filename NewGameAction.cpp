#include "NewGameAction.h"
#include "Grid.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}
void NewGameAction::ReadActionParameters()
{
}
void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pGrid->Restart();
	pOut->ClearStatusBar();
}
NewGameAction::~NewGameAction()
{
}