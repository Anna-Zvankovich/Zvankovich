#include<iostream>

using namespace std;


void InsertionSort(int a[], int n);
void RandomArray(int[], int);
void DisplayArray(int[], int);
void Swap(int&, int&);

int main()
{
	const int N = 100;
	int arr[N] = { 0 };
	int n;
	while (true)
	{
		cout << "Enter n > 0 and n <= " << N << ": ";
		cin >> n;
		if (n > 0 && n <= N)
			break;
	}
	RandomArray(arr, n);
	DisplayArray(arr, n);
	InsertionSort(arr, n);
	cout << endl;
	DisplayArray(arr, n);
	system("pause");
	return 0;
}
void InsertionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				for (int k = i - 1; k >= j; k--)
				{
					a[k + 1] = a[k];
				}
				a[j] = temp;
			}
		}
	}
}
void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i - 1;
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
