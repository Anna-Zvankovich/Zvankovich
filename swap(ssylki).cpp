#include <iostream>


using namespace std;

void swap(int &a, int &b)

{

	int t = a;
	a = b;
	b = t;

}

int main()

{
	int x,y;
	cin >> x >> y;
	cout << x << " " << y << endl;
	swap(x, y);
	cout << x << " " << y << endl;
	system("pause");
	return 0;
}

