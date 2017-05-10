#pragma once

const int N = 20;
const int M = 5;
class Country
{
public:
	Country();
	~Country();

	void SetName(char*);
	void SetCapital(char*);
	void SetLanguage(char*);
	void SetPopulation(int);
	void SetTheAria(int);
	void SetMoney(char*);
	void SetPoliticalSystem(char*);
	void SetHeadOfState(char*);
	void SetCountry(char*, char*, char*, int, int, char*, char*,char*);

	void DisplayCountry();


	char* GetName();
	char* GetCapital();
	char* GetLanguage();
	int GetPopulation();
	int GetTheAria();
	char* GetMoney();
	char* GetPoliticalSystem();
	char* GetHeadOfState();


private:
	char Name[N], Capital[N], Language[N], Money[N], PoliticalSystem[N], HeadOfState[N];
	int PopulationNumber, AriaNumber;

}; 
