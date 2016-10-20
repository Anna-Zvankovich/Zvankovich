#include <iostream>

using namespace std;

int main() 

{
	int k, i = 100;
	int a, copy;
	int sum = 0, k = 0;
	while (i < 1000)
	{
		k = 0;
		copy = i;
		while (k < 3)
		{
			a = copy % 10;
			if (a % 2 == 0)
				break;
			copy /= 10;
			k++;
		}
		if (k == 3)
			sum += i;
		i++;
	}

	int copys = sum;
	while (copys)

	{
		int n;
		n = copys % 10;
		if (n % 2 == 0)
			k++;
		copys /= 10;
	}

	cout << "The sum of the all numbers is " << sum << endl;
	cout << "the sum of even numbers " << k << endl;
	return 0;

}