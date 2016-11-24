#include<iostream>

using namespace std;


void BubbleSort(int[], int);
void RandomArray(int[], int);
void DisplayArray(int[], int);
void Swap(int&, int&);

int main()
{
	const int N = 100;
	int arr[N] = { 0 };
	int n ;
	while (true)
	{
		cout << "Enter n > 0 and n <= " << N << ": ";
		cin >> n;
		if (n > 0 && n <= N)
			break;
	}
	RandomArray(arr, n);
	DisplayArray(arr, n);
	BubbleSort(arr, n);
	cout << endl;
	DisplayArray(arr, n);
	system("pause");
	return 0;
}
void BubbleSort(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] > a[j - 1])
			{
				Swap(a[j], a[j - 1]);
			}
		}
	}
}

void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - i;
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
