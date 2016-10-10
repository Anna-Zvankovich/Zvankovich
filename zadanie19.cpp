#include <iostream>

using namespace std;

bool f(int n)
{
	int a = n;
	while (a)
	{
		int d = a % 10;
		if (d == 0 || n%d != 0)
			return false;
		a /= 10;
	}
	return true;
}

int main()
{
	int n=999 ;
	for (int i = 100; i < n; i++)
		if (f(i))
			cout << i << endl;
	system("pause");
}