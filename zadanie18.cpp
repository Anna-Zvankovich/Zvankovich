#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long n;
	int b = 0, x, m;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter X: ";
	cin >> x;
	cout << "Enter M: ";
	cin >> m;
	long long tmp1 = 0; 
	int i = 0;
	while (n)
	{
		int tmp;
		if (n == 0) break;
		tmp = n % 10;
		if (tmp == x)
			tmp = m;
		n = n / 10;
		tmp1 = tmp1 + tmp*pow(10, i);
		i++;
	}
	cout << tmp1 << endl;
	system("pause");
	return 0;
}
