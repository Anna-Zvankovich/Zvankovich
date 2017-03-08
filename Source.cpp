#include <iostream> 

using namespace std;

int**AllocateMemory(int n, int*arr);
int*AllocateMemory(int n);
int SumArr(int*arr, int n);
int*CreateSumRows(int**matrix, int*arr, int n);
void SortBySumRows2(int**matrix, int n, int*arr);
void SortBySumRows1(int**matrix, int*arr, int n, int*d);
void Swap(int*&a, int*&b);
void Swap(int&a, int&b);
void RandomMatrix(int**matrix, int n, int*arr);
void DisplayMatrix(int**matrix, int n, int*arr);
void DisplayArray(int*arr, int n);
void RandomArray(int *arr, int n);

int main()
{
	int n;
	cout << "Enter the number of rows:  ";
	cin >> n;
	int *arr = AllocateMemory(n);
	RandomArray(arr, n);
	int **matrix = AllocateMemory(n, arr);
	DisplayArray(arr, n);
	cout << endl;
	RandomMatrix(matrix, n, arr);
	DisplayMatrix(matrix, n, arr);
	cout << endl;
	int*d = CreateSumRows(matrix, arr, n);
	SortBySumRows2(matrix, n, arr);
	//SortBySumRows1(matrix, d, arr, n);
	DisplayMatrix(matrix, n, arr);
	system("pause");
	return 0;
}


int**AllocateMemory(int n, int*arr)
{
	int**matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[arr[i]];
		for (int j = 0; j < arr[j]; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

int*AllocateMemory(int n)
{
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	return arr;
}


int SumArr(int*arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int*CreateSumRows(int**matrix, int*arr, int n)
{
	int*d = AllocateMemory(n);
	for (int i = 0; i < n; i++)
	{
		d[i] = SumArr(matrix[i], arr[i]);
	}
	return d;
}

void SortBySumRows1(int**matrix, int*arr, int n, int*d)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
			if (d[j] < d[j - 1])
			{
				Swap(d[j], d[j - 1]);
				Swap(matrix[j], matrix[j - 1]);
				Swap(arr[j], arr[j - 1]);
			}
	}
	delete[]d;
}

void SortBySumRows2(int**matrix, int n, int*arr)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j >= i; j--)
			if (SumArr(matrix[j], arr[j]) <= SumArr(matrix[j - 1], arr[j - 1]))
			{
				Swap(matrix[j], matrix[j - 1]);
				Swap(arr[j], arr[j - 1]);
			}
}

void Swap(int&a, int&b)
{
	int t = a;
	a = b;
	b = t;
}

void Swap(int*&a, int*&b)
{
	int*t = a;
	a = b;
	b = t;
}


void RandomMatrix(int**matrix, int n, int*arr)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = (rand() % 100);
}

void DisplayMatrix(int**matrix, int n, int*arr)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < arr[i]; j++)
			cout << " " << matrix[i][j];
		cout << endl;
	}
}

void DisplayArray(int*arr, int n)
{
	for (int*i = arr; i < arr + n; i++)
	{
		cout << " " << *i;
	}
}

void RandomArray(int *arr, int n)
{
	for (int* i = arr; i < arr + n; i++)
	{
		*i = rand() % 10 + 1;
	}
}