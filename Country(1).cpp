
#include <iostream>
#include "CountryName.h"

using namespace std;

Country::Country()
{

}

Country::~Country()
{

}

void Country::SetName(char* s)
{
	strcpy(Name, s);
}

void Country::SetCapital(char* s)
{
	strcpy(Capital, s);
}

void Country::SetLanguage(char* s)
{
	strcpy(Language, s);
}

void Country::SetPopulation(int PopulationNumber)
{
	this->PopulationNumber = PopulationNumber;
}

void Country::SetTheAria(int AriaNumber)
{
	this->AriaNumber = AriaNumber;
}

void Country::SetMoney(char* s)
{
	strcpy(Money, s);
}

void Country::SetPoliticalSystem(char* s)
{
	strcpy(PoliticalSystem, s);
}
void Country::SetHeadOfState(char* s)
{
	strcpy(HeadOfState, s);
}

void  Country::SetCountry(char* s1, char* s2, char* s3, int n1, int n2, char* s4, char* s5, char* s6)
{
	SetName(s1);
	SetCapital(s2);
	SetLanguage(s3);
	SetPopulation(n1);
	SetTheAria(n2);
	SetMoney(s4);
	SetPoliticalSystem(s5);
	SetHeadOfState(s6);
}


char* Country::GetName()
{
	return Name;
}
char* Country::GetCapital()
{
	return Capital;
}
char* Country::GetLanguage()
{
	return Language;
}
int Country::GetPopulation()
{
	return PopulationNumber;
}
int Country:: GetTheAria()
{
	return AriaNumber;
}
char* Country::GetMoney()
{
	return Money;
}
char* Country::GetPoliticalSystem()
{
	return PoliticalSystem;
}
char* Country::GetHeadOfState()
{
	return HeadOfState;
}


void  Country::DisplayCountry()
{
	cout << endl << Name << " " << Capital << ", \t";
	cout.precision(3);
	cout << Language << "  , \t" << PopulationNumber << "  , \t" << AriaNumber << "  , \t" << Money << "  , \t" << PoliticalSystem << "  , \t" << HeadOfState << ".";

}