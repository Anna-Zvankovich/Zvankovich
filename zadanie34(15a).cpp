#include <iostream>


using namespace std;



void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
int InitDimentia();
void SortArray(int a[], int n);
void kol(int a[], int n);

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
	SortArray( a, n);
	DisplayArray(a, n);
	kol(a, n);
	system("pause");
	return 0;


}

void SortArray(int a[], int n)
{
	int tmp;
	for (int i = 0, j = 0; i<n; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 1) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j +1] = tmp;
	}
}

void kol(int a[], int n)
{
	int j = 0, k = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
			k++;
		if (a[i] != a[i + 1])
		{
			cout << "kol-vo " << a[i] << " = "  << k << endl;
			k = 1;
		}

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