#include <iostream>

using namespace std;

const int L = 100, N = 50;
int** AllocateMemory(int n);
void EnterMatrix(int** arr, int n);
int** CreateMatrix(int**arr, int n);
int FindMax(int** arr, int n, int k, int l);
void DisplayMatrix(int** arr, int n);

int main()
{
	int n;
	{
		cout << "Enter size of matrix: ";
		cin >> n;
		if (n > 0)
			cout << "Error!";
	}
	system("cls");

	int** arr = AllocateMemory(n);
	cout << "Enter ellements of matrix: " << endl;
	EnterMatrix(arr, n);
	system("cls");
	cout << "Sourse matrix: " << endl;
	DisplayMatrix(arr, n);
	int** arr2 = CreateMatrix(arr, n);
	cout << "New matrix: " << endl;
	DisplayMatrix(arr2, n);
	system("pause");
	return 0;
}

int** AllocateMemory(int n)
{
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	return arr;

}

void EnterMatrix(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> arr[i][j];
		}
	}
}

int** CreateMatrix(int**arr, int n)
{
	int**arr2 = AllocateMemory(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr2[i][j] = FindMax(arr, n, i, j);
		}
	}
	return arr2;
}

int FindMax(int** arr, int n, int k, int l)
{
	int up = k, down = k;
	int max = arr[0][0];
	for (int j = l; j >= 0; j--)
	{
		for (int i = up; i <= down; i++)
		{
			if (max < arr[i][j])
				max = arr[i][j];
		}
		if (up > 0) up--;
		if (down < n - 1) down++;
	}
	return max;
}

void DisplayMatrix(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(3);
			cout << arr[i][j];
		}
		cout << endl;
	}
}