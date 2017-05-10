#include <iostream>
#include "CountryName.h"

using namespace std;

Country InitCountry();// сммотреть что за студент 
Country* InitArray(int);
void DisplayArray(Country*, int);
void EnterArray(int*, int);
void SortFirstName(Country*, int);
void Swap(Country&, Country&);

int main()
{
	int n;
	cout << "Enter the number of Countries:";
	cin >> n;
	system("cls");
	Country* country = InitArray(n);
	if (!country)
	{
		cout << "\nDynamic array doesn't exist!\n";
		system("pause");
		return 0;
	}
	cout << "The list of Country : " << endl << endl;
	DisplayArray(country, n);



	cout << "The sorting list of Country:" << endl;;
	SortFirstName(country, n);
	DisplayArray(country, n);
	delete[] country;
	system("pause");
	return 0;
}

Country InitCountry()
{
	char SetName[N] = "", SetCapital[N] = "", SetLanguage[N] = "", SetMoney[N] = "", SetPoliticalSystem[N] = "", SetMonSetHeadOfState[N] = "";
	cout << "Enter the name of the country: " << endl;
	cin.ignore();
	cin.get(SetName, N, '\n');
	cout << "Enter the capital: " << endl;
	cin.ignore();
	cin.get(SetCapital, N, '\n');
	cout << "Enter the language: " << endl;
	cin.ignore();
	cin.get(SetLanguage, N, '\n');
	cout << "Enter money : " << endl;
	cin.ignore();
	cin.get(SetMoney, N, '\n');
	cout << "Enter the Political System : " << endl;
	cin.ignore();
	cin.get(SetPoliticalSystem, N, '\n');
	cout << "Enter the Mon Set Head Of State : " << endl;
	cin.ignore();
	cin.get(SetMonSetHeadOfState, N, '\n');

	int SetPopulation, SetTheAria;
	cout << "Enter the population number: " << endl;
	cin >> SetPopulation;
	cout << "Enter the aria number: " << endl;
	cin >> SetTheAria;
	


	Country country;
	country.SetCountry(SetName, SetCapital, SetLanguage, SetPopulation, SetTheAria, SetMoney, SetPoliticalSystem, SetMonSetHeadOfState);
	return country;
}

Country* InitArray(int n)
{
	Country* array = new Country[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the information about " << (i + 1) << "  Country\n" << endl;
		array[i] = InitCountry();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

void DisplayArray(Country* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayCountry();
	cout << endl;
}

void SortFirstName(Country* array, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(array[j].GetName(), array[j - 1].GetName()) < 0)
				Swap(array[j], array[j - 1]);
}

void Swap(Country &a, Country &b)
{
	Country t = a;
	a = b;
	b = t;
}