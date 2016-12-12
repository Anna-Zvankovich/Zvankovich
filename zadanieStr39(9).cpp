#include <iostream>

using namespace std;

const int L = 100, N = 50;
void DisplayMatrix(int matrix[][N], int n, int m);
void EnterMatrix(int matrix[][N], int n, int m);
void RandomMatrix(int matrix[][N], int n, int m);
void TranspouseColumn(int matrix[][N], int n, int m);

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
	TranspouseColumn(matrix, n, m);
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
void TranspouseColumn(int matrix[][N], int n, int m) //меняет местами столбцы 
{
	for (int j = 0; j < m / 2; j++)
		for (int i = 0; i < n; i++)
			Swap(matrix[i][j], matrix[i][m - j - 1]);
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