#include "CardTwelve.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

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
	CardNine* C9;
	CardTen* C10;
	CardEleven* C11;
	int MaxPrice;
	int Arr[3];
	Arr[0] = C9->GetCardPrice();
	Arr[1] = C10->GetCardPrice();
	Arr[2] = C11->GetCardPrice();


	if (C9->GetOwner() == pPlayer)
	{
		MaxPrice = C9->GetCardPrice();
		if (C10->GetOwner() == pPlayer)
			if (C10->GetCardPrice() > MaxPrice)
				MaxPrice = C10->GetCardPrice();
		if (C11->GetOwner() == pPlayer)
			if (C11->GetCardPrice() > MaxPrice)
				MaxPrice = C11->GetCardPrice();
		for (int i = 0; i < 3; i++)
		{
			//if (MaxPrice==Arr[i])
			
		}
	}
	else if (C10->GetOwner() == pPlayer)
	{
		MaxPrice = C10->GetCardPrice();
		if (C11->GetOwner() == pPlayer)
			if (C11->GetCardPrice() > MaxPrice)
				MaxPrice = C11->GetCardPrice();
	}
	else if (C11->GetOwner() == pPlayer)
	{

	}



}