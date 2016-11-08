#include <iostream>


using namespace std;


void F2(bool les, bool gr, bool eq);
void F1(int a[], int n, bool& les, bool& gr, bool& eq);
void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
int InitDimentia();

const int N = 100;

int main()
{
	int a[N] = { 0 };
	int n = InitDimentia();
	while (true)
	{
		cout << "Enter n > 0 and n <= " << N << ": ";
		cin >> n;
		if (n > 0 && n <= N)
			break;
	}
	EnterArray( a,  n);
	DisplayArray(a,  n);
	system("cls");
	bool les = false, gr = false, eq = false;
	F1(a, n, les, gr, eq);
	F2(les, gr, eq);
	system("pause");
	return 0;


}



void F1(int a[], int n, bool& les, bool& gr, bool& eq)
{
	for (int i = 0; i < (n - 1); i++)
	{
		if (a[i] < a[i + 1]) les = true;
		else if (a[i] > a[i + 1]) gr = true;
	}
}

void F2(bool les, bool gr, bool eq)
{
	if (les && gr)
		cout << " Random ";
	if (les &&! gr && eq)
		cout << " not strictly increasing ";
	if (!les && gr && eq)
		cout << " not strictly decreasing ";
	if (les &&! gr &&! eq)
		cout << " strictly increasing ";
	if (!les && gr && !eq)
		cout << " strictly decreasing ";
	if (!les && gr && eq)
		cout << " monotonic ";


}

void EnterArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "] = ";
		cin >> a[i];
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

int InitDimentia()
{
	int n;
	while (true)
	{
		cin >> n;
		if (n > 0 || n <= N)
			return N;
		cout << " input Error! Tray again" << endl;

	}
}