#include <iostream>

using namespace std;
const int L = 100, N = 50;
void DisplayMatrix(int matrix[][N], int n, int m);
void F1(int matrix[][N], int m, int n);
void Swap(int& a, int& b);
int main()
{
	int n = 10, m = 10;
	int matrix[L][N] = { { 0,3,5,-1,8,0,7,1,3,4 },{ -5,2,8,6,4,4,5,3,7,2 },{ 8,0,2,0,-7,4,7,9,3,5 },{ 6,4,4,8,2,0,3,5,-2,1 },{ 5,-8,2,0,0,7,4,0,5,2 },{ 4,1,0,7,0,-4,3,5,0,4 },{ 6,2,3,8,3,4,5,-9,8,1 },{ 0,8,0,7,4,3,3,5,2,-6 },{ 1,2,-3,3,5,5,3,8,6,0, },{ 4,8,2,9,0,9,-5,5,2,7 } };
	DisplayMatrix(matrix, n, m);
	cout << endl;
	cout << "New matrix: ";
	cout << endl;
	F1(matrix, m, n);
	DisplayMatrix(matrix, n, m);
	system("pause");
	return 0;
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

void F1(int matrix[][N], int n, int m)//ставит по диагонали отрицательные числа
{
	for (int j = 0; j < n; j++)
	{
		int i = 0;
		for (; matrix[i][j] >= 0; i++);
		{
			if (i == j) continue;
			else
				for (int k = 0; k < n; k++)
					Swap(matrix[j][k], matrix[i][k]);
		}
	}
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
