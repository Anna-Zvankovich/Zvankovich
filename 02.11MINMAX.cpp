#include <iostream>

using namespace std;

void EnterArray(int a[], int n);
int MinMax(int a[], int n);
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

	int i = MinMax(a, n), j = MinMax(a, n);
	cout << "min = " << a[i] << "  max = " << a[j] << endl;
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


int MinMax(int a[], int n)


{
	int min = 0, i = 1;
	if (a[min] > a[i])
	{

		for (int i = 1; i < n; i++)
			min = i;
		return min;
	}
	int max = 0;
	if (a[max] < a[i])
	{
		for (int i = 1; i < n; i++)
			max = i;
		return max;
	}
}


void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{

		a[i] = i + 1;
	}
}