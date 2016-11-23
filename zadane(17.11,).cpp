#include<iostream>

using namespace std;


void ChoiceSort(int[], int);
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
	ChoiceSort(arr, n);
	cout << endl;
	DisplayArray(arr, n);
	system("pause");
	return 0;
}
void ChoiceSort(int a[], int n)
{
	for (int i = n-1; i > n; i--)
	{
		int max = i;
		for (int j = i - 1; j > n; j--)
		{
			if (a[j] < a[max]) max = j;

		}
		Swap(a[i], a[max]);
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
