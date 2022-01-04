#include "CardNine.h"
int  CardNine::CardPrice=0;
int  CardNine::Fees=0;
Player* CardNine::Owner=nullptr;

CardNine::CardNine(const CellPosition& cellposition) :Card(cellposition)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid) 
{   
	if (Fees==0) {
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pGrid->PrintErrorMessage("Card Nine : Station 1 , click to continue..");
		pOut->PrintMessage("Enter its Price :  ");
		int t;
		do
		{
			t = pIn->GetInteger(pOut);
			if (t > 0)
			{
				CardPrice = t;
			}
			else pOut->PrintMessage("Invalid Price ! please try again.");
		} while (t <= 0);
		pOut->PrintMessage("Enter its Fees :  ");
		do
		{
			t = pIn->GetInteger(pOut);
			if (t > 0)
			{
				Fees = t;
			}
			else pOut->PrintMessage("Invalid Fees value ! please try again.");
		} while (t <= 0);
		pOut->ClearStatusBar();
	}
	
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (!Owner)
	{
		Card::Apply(pGrid, pPlayer);
		pGrid->PrintErrorMessage("This is station 1 , Price : " + to_string(CardPrice) + "  Fees : " + to_string(Fees) + " click to continue...");
		pOut->PrintMessage("Would you like to purchase ? Yes(y) or No(n)");
		string t;
		do
		{
			t = pIn->GetSrting(pOut);
			if (t == "y")
			{
				if (pPlayer->GetWallet() >= CardPrice) {
					pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
					Owner = pPlayer;
					pOut->PrintMessage("Purchase complete .");
				}
				else
				{
					pGrid->PrintErrorMessage("Insufficient wallet, click to continue.. ");
				}
			}
			else if (t != "n") {
				pOut->PrintMessage("Invalid input !  please try again. ");
			}

		} while (t!="y" && t!="n");
		
	} 
	else 
	{
		if (Owner != pPlayer)
		{
			pOut->PrintMessage("Stepped on a card owned by p(" + to_string(Owner->getPlayerNum()) + ") pay : " + to_string(Fees));
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			Owner->SetWallet(Owner->GetWallet() + Fees);
		}
	}
}

void CardNine::Save(ofstream& OutFile, int Type)
{
	if (Type == 2) {
		Card::Save(OutFile, Type);
		OutFile << CardPrice << " " << Fees << endl;
	}
}