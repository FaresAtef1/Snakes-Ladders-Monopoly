#include "CardTwelve.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "Player.h"

CardTwelve::CardTwelve(const CellPosition& cellposition) :Card(cellposition)
{
	cardNumber = 12;
}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CardNine* C9=NULL;
	CardTen* C10=NULL;
	CardEleven* C11=NULL;
	int Preventer = 0;    // this variable prevents printing the last message if the Current Player does not have any cards
	int MaxPrice;
	Output* pOut = pGrid->GetOutput();
	Player* NewOwner = pGrid->GetPoorest(); // fy mo4kla law el current hwa el poorest b2a
	int IndexOfPoorestPlayer = NewOwner->getPlayerNum();
	//bool Test = pPlayer->IsEqualWallets();
	bool Test=true;
	if (pPlayer->IsEqualWallets() && (pPlayer->GetEqualWallets() != NewOwner->GetWallet()))
		Test = false;
	
	if (Test)
		NewOwner = NULL;

		if (C9->GetOwner() == pPlayer)
		{
			MaxPrice = C9->GetCardPrice();
			if (C10->GetOwner() == pPlayer)
				if (C10->GetCardPrice() > MaxPrice)
					MaxPrice = C10->GetCardPrice();
			if (C11->GetOwner() == pPlayer)
				if (C11->GetCardPrice() > MaxPrice)
					MaxPrice = C11->GetCardPrice();
			if (NewOwner)
			{
				if (MaxPrice == C9->GetCardPrice())
				{
					C9->SetOwner(NewOwner);
					pOut->PrintMessage("Now the new owner of Card9 is p(" + to_string(IndexOfPoorestPlayer) + ")");
				}
				if (MaxPrice == C10->GetCardPrice())
				{
					C10->SetOwner(NewOwner);
					pOut->PrintMessage("Now the new owner of Card10 is p(" + to_string(IndexOfPoorestPlayer) + ")");
				}
				if (MaxPrice == C11->GetCardPrice())
				{
					C11->SetOwner(NewOwner);
					pOut->PrintMessage("Now the new owner of Card11 is p(" + to_string(IndexOfPoorestPlayer) + ")");
				}
			}
		}
		else if (C10->GetOwner() == pPlayer)
		{
			MaxPrice = C10->GetCardPrice();
			if (C11->GetOwner() == pPlayer)
				if (C11->GetCardPrice() > MaxPrice)
					MaxPrice = C11->GetCardPrice();
			if (NewOwner)	
			{
				if (MaxPrice == C10->GetCardPrice())
				{
					C10->SetOwner(NewOwner);
					pOut->PrintMessage("Now the new owner of Card10 is p(" + to_string(IndexOfPoorestPlayer) + ")");
				}
				if (MaxPrice == C11->GetCardPrice())
				{
					C11->SetOwner(NewOwner);
					pOut->PrintMessage("Now the new owner of Card11 is p(" + to_string(IndexOfPoorestPlayer) + ")");
				}
			}
		}
		else if (C11->GetOwner() == pPlayer && NewOwner)
		{
			C11->SetOwner(NewOwner);
			pOut->PrintMessage("Now the new owner of Card11 is p(" + to_string(IndexOfPoorestPlayer) + ")");
		}
		else
		{
			pOut->PrintMessage("Current Player does not have any cards");
			Preventer = 1;
		}
	
		if (Test&&Preventer==0)
			pOut->PrintMessage("There are Two poorest players have the same amount of money");
}

void CardTwelve::Save(ofstream& OutFile, int Type)
{
	if (Type == 2) {
		Card::Save(OutFile, Type);
		OutFile << endl;

	}
}