#include <iostream>

using namespace std;

int main()
{

	double a, b, c;
	cout << "Enter coeff." << endl;
	cout << "a : ";
	cin >> a;
	if (a == 0)
	{
		cout << "Input error!" << endl;
		system("pause");
		return 0;
	}
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	if (a == 1)
		cout << "x^2";
		
	else if (a == -1)
		cout << "-x^2";
	else
		cout << a << "*x^2";
	if (b != 0)
	{
		if (b == 1)
			cout << " + x";
		else if (b == -1)
			cout << " -x";
		else if (b > 0)
			cout << " + " << b << "*x";
		else
			cout << " " << b << "*x";
	}
	if (c != 0)
		if (c > 0)
			cout << " + " << c << endl;
		else
			cout << " " << c << endl;
	system(" pause");
	return 0;

	}