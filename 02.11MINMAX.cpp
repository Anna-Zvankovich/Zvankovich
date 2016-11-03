#include <iostream>

using namespace std;

void EnterArray(int a[], int n);
void MinMax(int a[], int n, int& , int& );
void RandomArray(int a[], int n);
void DisplayArray(int a[], int n);

const int N = 100;


int main()
{
	int a[N] = { 0 };
	int n;
	while (true)
	{
		cout << "Enter n > 0 and n <= " << N << ": ";
		cin >> n;
		if (n > 0 && n <= N)
			break;
	}

	RandomArray(a, n);
	cout << "Source array" << endl;
	DisplayArray(a, n);
	cout << endl;
	//EnterArray(a, n);
	int min=0, max=0;
	MinMax(a, n,min , max );
	cout << "min index = " << min << endl;
	cout << "max index = " << max << endl;
	system("pause");
	return 0;
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


void MinMax(int a[], int n, int& min, int& max)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[min])
			min = i;
		if (a[i] > a[max])
			max = i;

	}

}
void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{

		a[i] = i + 1;
	}
}