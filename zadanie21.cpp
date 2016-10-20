#include <iostream>


using namespace std;


bool isSimpleNumber(int);


int main() 

{
	int n = 2, x;
	cout << "Enter diapazon" << endl;
	cin >> x;
	while (x < 1) 
	{
		cout << "Enter a positive number" << endl;
		cin >> x;
	}
	while (n <= x)
	{
		if (isSimpleNumber(n))
			cout << n << "  ";
		n++;
	}
	cout << endl;
	system("pause"); 
	return 0;
}

bool isSimpleNumber(int n) 
{
	int i, res;
	for (i = 2; i <= sqrt(n); i++)
		if (!(n % i))
			return false;
	return true;
}