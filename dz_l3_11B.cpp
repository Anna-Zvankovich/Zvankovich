#include <iostream>

using namespace std;

int main()
{
	double x, y;
	cin >> x >> y;
	if ((y >= -0, 5) && (y <= x) && (x <= 1))
		cout << "point falls";
	else
		if ((x >= 1) && (((x - 1)*(x-1)+ y*y) <= 1))
			cout << "point falls";
		else
			cout << "false";
	system("pause");
	return 0;
}