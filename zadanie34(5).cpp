#include <iostream>


using namespace std;


void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
int InitDimentia();
void localMinMax(int a[], int n, int b[], int& min, int c[], int& max);

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
	system("cls");
	int min = 0;
	int max = 0;
	int b[N] = { 0 };
	int c[N] = { 0 };
	
	localMinMax(a, n, b, min, c, max);
	
	system("pause");
	return 0;


}
void localMinMax(int a[], int n, int b[], int&min, int c[], int&max)
{
	int j = 0, i = 0, l = 0;
	if (a[i] < a[i + 1])
	{
		min++;
		b[j] = a[0];
	}
	if (a[i] > a[i + 1])
	{
		max++;
		c[l] = a[i];
	}

	for ( ; i < (n - 1); i++)
	{
		if (a[i] < a[i + 1] && a[i] < a[i - 1])
		{
			min++;
			b[min] = a[i];
		}
		if (a[i] > a[i + 1] && a[i] > a[i - 1])
		{
			max++;
			b[max] = a[i];
		}
	}
	cout << "Min = " << endl;
	DisplayArray(b, min);
	cout << "Max = " << endl;
	DisplayArray(c, max);
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

