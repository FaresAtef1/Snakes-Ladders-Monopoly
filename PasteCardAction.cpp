#include "PasteCardAction.h"
#include"AddCardAction.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("PasteCardAction: Click on the desired cell !");
	cardPos = pIn->GetCellClicked();
}
void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* Clip = pGrid->GetClipboard();
	if ( (bool)Clip && cardPos.IsValidCell())
	{
		Card* Pasted;
		switch (Clip->GetCardNumber())
		{

		case 1:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardOne(cardPos);
				Card  temp = *Pasted;
				*((CardOne*)Pasted) = *((CardOne*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardOne temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
				pGrid->SetClipboard(nullptr);
			}
			break;
		case 2:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardTwo(cardPos);
				Card  temp = *Pasted;
				*((CardTwo*)Pasted) = *((CardTwo*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardTwo temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
				pGrid->SetClipboard(nullptr);
			}
			break;
		case 3:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardThree(cardPos);
				Card  temp = *Pasted;
				*((CardThree*)Pasted) = *((CardThree*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardThree temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
				pGrid->SetClipboard(nullptr);
			}
			break;
		case 4:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardFour(cardPos);
				Card  temp = *Pasted;
				*((CardFour*)Pasted) = *((CardFour*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardFour temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
			}
			break;
			/*case 5:
				pCard = new Cardfive(cardPosition);
				break;*/
		case 6:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardSix(cardPos);
				Card  temp = *Pasted;
				*((CardSix*)Pasted) = *((CardSix*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardSix temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
			}
			break;
		case 7:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardSeven(cardPos);
				Card  temp = *Pasted;
				*((CardSeven*)Pasted) = *((CardSeven*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardSeven temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
			}
			break;
			/*case 8:
				pCard = new Cardeigth(cardPosition);
				break;*/
		case 9:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardNine(cardPos);
				Card  temp = *Pasted;
				*((CardNine*)Pasted) = *((CardNine*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardNine temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
			}
			break;
		case 10:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardTen(cardPos);
				Card  temp = *Pasted;
				*((CardTen*)Pasted) = *((CardTen*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardTen temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
			}
			break;
		case 11:
			if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
			{
				Pasted = new CardEleven(cardPos);
				Card  temp = *Pasted;
				*((CardEleven*)Pasted) = *((CardEleven*)Clip);
				*Pasted = temp;
				pGrid->AddObjectToCell(Pasted);
			}
			else
			{
				CardEleven temp(cardPos);
				*Clip = (Card)temp;
				pGrid->AddObjectToCell(Clip);
			}
			break;
			/*case 12:
				pCard = new Cardtwelve(cardPosition);
				break;
				*/
		}
	}
}