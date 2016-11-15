#include <iostream>


using namespace std;


void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
int InitDimentia();
void ShiftRight(int a[], int n);
void shiftLeft(int a[], int n, int& k);

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
	DisplayArray(a, n);
	system("pause");
	system("cls");
	ShiftRight(a, n);
	DisplayArray(a, n);
	system("pause");
	return 0;


}


void ShiftRight(int a[], int n)
{   
	int i = 2;
	int temp = a[i - 1];
	for (int i=n-2; i >= 0; i--)
		a[i + 1] = a[i];
	a[0] = temp;
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
		cin >> n;
		if (n > 0 || n <= N)
			return N;
		cout << " input Error! Tray again" << endl;

	}
}