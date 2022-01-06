#include "NewGameAction.h"
#include "Grid.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"



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
	CardNine* C9 = NULL;
	CardTen* C10 = NULL;
	CardEleven* C11 = NULL;

	C9->SetOwner(NULL);
	C10->SetOwner(NULL);
	C11->SetOwner(NULL);

	pGrid->Restart();
	pOut->ClearStatusBar();
}
NewGameAction::~NewGameAction()
{
}