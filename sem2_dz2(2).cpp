#include <iostream> 

using namespace std;

double ryadSin(double, double);
double ryadCos(double, double);
double ryadExp(double, double);
void Allocate_memory(double**&, int);
void delete_memory(double**&, int);
void printArray(double**, int);

void libraryArr(double**, int, double);
void rowArr(double**, int, double);


int main()
{
	int rows;
	double**arr;
	double**arr2;

	cout << "Type rows \n";
	cin >> rows;

	cout << "Type accuracy\n";
	double eps;
	cin >> eps;

	Allocate_memory(arr, rows);
	Allocate_memory(arr2, rows);


	rowArr(arr, rows, eps);
	libraryArr(arr2, rows, eps);
	cout << "Decomposition matrix\n";

	printArray(arr, rows);

	cout << "Libary matrix\n";
	printArray(arr2, rows);

	delete_memory(arr, rows);
	delete_memory(arr2, rows);
	system("pause");

}

void Allocate_memory(double**&arr, int rows)
{
	
		arr = new double*[rows];
		for (int i = 0; i != rows; i++)
			arr[i] = new double[rows];
	

}
void delete_memory(double**&arr, int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];

	delete[] arr;
}
void printArray(double** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout.width(7);
			cout << arr[i][j];
		}
		cout << endl;
	}

}
double ryadSin(double eps, double x)
{
	double ad = 1, s = 0;
	int i = 1, p = 1;
	while (abs(ad) > eps)
	{
		ad *= (x*1.0 / (i*1.0));//слагаемое
		s += p*ad;//сумма
		i += 2;//знаменатель
		p *= -1;//переключатель знака
		ad *= x / (i - 1);

	}
	return s;
}
double ryadCos(double eps, double x)
{
	double ad = 1, s = 0;
	int i = 1, p = 1;
	while (abs(ad) > eps)
	{
		s += p*ad;//сумма
		ad *= (x*1.0 / (i*1.0));//слагаемое
		i += 2;//знаменатель
		p *= -1;//переключатель знака
		ad *= x / (i - 1);

	}
	return s;
}
double ryadExp(double eps, double x)
{
	double ad = 1, s = 0;
	int i = 1;
	while (abs(ad) > eps)
	{
		s += ad;//сумма
		ad *= (x*1.0 / (i*1.0));//слагаемое
		i++;//знаменатель
	}
	return s;
}
void rowArr(double**arr, int rows, double eps) {
	double rE, rrE, rSin, rCos;
	for (int i = 0; i < rows; i++) {
		rSin = ryadSin(eps, ((i + 1)*(i + 1))*1.0);
		for (int j = 0; j < rows; j++) {
			if (i == j) arr[i][j] = 0;
			else {
				rCos = ryadCos(eps, ((i + j)*(i + j))*1.0);
				rrE = ryadSin(eps, (i + j)*1.0);
				rE = ryadExp(eps, rrE);
				arr[i][j] = (rE + rCos)*1.0 / (rSin*1.0);
			}
		}
	}
}
void libraryArr(double**arr, int rows, double eps)
{

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (i == j)arr[i][j] = 0;
			else arr[i][j] = (exp(sin(i + j)) + cos((i + j)*(i + j)))*1.0 / (sin((i + 1)*(i + 1)))*1.0;
		}
	}
}
