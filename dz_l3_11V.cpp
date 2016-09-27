#include <iostream>

using namespace std;

int main()
{
	double x, y;
	cin >> x >> y;
	if ((y >= 0) && (x >= 0) && ((x*x + y*y) <= 1))
		cout << "point falls";
	else
		if ((x >= -1) && (x <= 0) && (y >= -1) && (y <= 0))
			cout << "point falls";
		else
			cout << "false";
	system("pause");
	return 0;
}