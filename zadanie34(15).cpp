#include <iostream>


using namespace std;



void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
int InitDimentia();
void Kol(int a[], int n,  int& pos, int& neg);

const int N = 100;

int main()
{
	int a[N] = { 0 };
	int n = InitDimentia();
	while (true)
	{
		cout << "Enter n > 0 and n <= " << N << ": ";
		cin >> n;
		if (n > 0 && n <= N)
			break;
	}
	EnterArray(a, n);
	//DisplayArray(a, n);
	//system("cls");
	int  pos = 0, neg = 0;
	Kol(a, n, pos, neg);
	cout << "kollichestvo positive=" << pos << endl;
	cout << "kollichestvo negatie=" << neg << endl;
	system("pause");
	return 0;


}

void Kol(int a[],int n, int& pos, int& neg )
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			pos++;
		if (a[i] < 0)
			neg++;

	}
}





void EnterArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "] = ";
		cin >> a[i];
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

int InitDimentia()
{
	int n;
	while (true)
	{
		cout << "Enter the number";
		cin >> n;
		if (n > 0 || n <= N)
			return N;
		cout << " input Error! Tray again" << endl;

	}
}