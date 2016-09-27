#include <iostream>

using namespace std;

int main()
{
	double x, y;
	cin >> x >> y;
	if ((y <= ( x + 1)) && (y >= (-x - 1))  && ((x*x + y*y) <= 1))
		cout << "point falls";
	
		else
			cout << "false";
	system("pause");
	return 0;
}