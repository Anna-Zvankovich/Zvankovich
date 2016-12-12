#include <iostream>

using namespace std;

const int L = 100, N = 50;
void DisplayMatrix(int matrix[][N], int n, int m);
void EnterMatrix(int matrix[][N], int n, int m);
void RandomMatrix(int matrix[][N], int n, int m);
void TranspouseString(int matrix[][N], int n, int m);

void Swap(int &a, int &b);

int main()
{
	int matrix[L][N] = { { 0 } };
	int n, m;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	RandomMatrix(matrix, n, m);
	DisplayMatrix(matrix, n, m);
	TranspouseString(matrix, n, m);
	cout << endl;
	DisplayMatrix(matrix, n, m);
	system("pause");
	return 0;
}

void EnterMatrix(int a[][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "]=";
			cin >> a[i][j];
		}
	}
}

void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void DisplayMatrix(int matrix[][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(3); //выравнивание по правому краю
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


void TranspouseString(int matrix[][N], int n, int m) //меняет местами столбцы 
{
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < m; j++)
			Swap(matrix[i][j], matrix[n-i-1][j ]);
}


void RandomMatrix(int matrix[][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 10;
			//matrix[i][j] = i + 1;
		}
	}
}