#include <iostream>

using namespace std;

int main()
{
	int  long long n, x;
	int b = 0;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter N: ";
	cin >> x;

	while (n)
	{
		if (n % 10 != x) b = b * 10 + n % 10;
		n /= 10;
	}
	while (b)
	{
		n = n * 10 + b % 10;
		b /= 10;
	}
	cout << n << endl;
	system("pause");
	return 0;
}