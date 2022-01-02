#include "CardTwelve.h"

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
	

}