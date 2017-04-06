#include <iostream> 
#include <cmath>
#include <iomanip>
using namespace std;

double ryadSin(double, double);
double ryadCos(double, double);
double ryadExp(double, double);
void give_memory(double**&, int, int);
void delete_memory(double**&, int);
void printArray(double**, int, int);

void libraryArr(double**, int, int, double);
void rowArr(double**, int, int, double);


int main()
{
	int rows, cols;
	double**arr;
	double**arr2;

	cout << "Type rows and cols\n";
	cin >> rows >> cols;

	cout << "Type accuracy\n";
	double eps;
	cin >> eps;

	give_memory(arr, rows, cols);
	give_memory(arr2, rows, cols);


	rowArr(arr, rows, cols, eps);
	libraryArr(arr2, rows, cols, eps);
	cout << "Decomposition matrix\n";

	printArray(arr, rows, cols);

	cout << "Libary matrix\n";
	printArray(arr2, rows, cols);

	delete_memory(arr, rows);
	delete_memory(arr2, rows);
	system("pause");

}

void give_memory(double**&arr, int rows, int cols)
{
	try {
		arr = new double*[rows];
		for (int i = 0; i != rows; i++)
			arr[i] = new double[cols];
	}
	catch (...) {
		cout << "Allocation failed" << endl;
		system("pause");
	}

}
void delete_memory(double**&arr, int rows) {
	for (int i = 0; i < rows; i++) delete[] arr[i];

	delete[] arr;
}
void printArray(double** arr, int rows, int cols)
{
	for (int i = 0; i != rows; i++) {
		for (int j = 0; j != cols; j++) {
			cout << setprecision(3) << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
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
void rowArr(double**arr, int rows, int cols, double eps) {
	double rE, rrE, rSin, rCos;
	for (int i = 0; i < rows; i++) {
		rSin = ryadSin(eps, ((i + 1)*(i + 1))*1.0);
		for (int j = 0; j < cols; j++) {
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
void libraryArr(double**arr, int rows, int cols, double eps) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == j)arr[i][j] = 0;
			else arr[i][j] = (exp(sin(i + j)) + cos((i + j)*(i + j)))*1.0 / (sin((i + 1)*(i + 1)))*1.0;
		}
	}
}
