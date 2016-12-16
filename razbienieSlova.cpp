#include <iostream>

using namespace std;

const int N = 256;
void Swap(char& a, char& b);
void Reverse(char a[], int n);
void DisplayWords(char arr[], int n);
void EnterArray(char a[], int n);
int LengthString(char str[]);

int main()
{
	char a[N] = { '/0' };
	int n;

	while (true)
	{
		cout << "Enter n > 0 and n <= " << N << ": ";
		cin >> n;
		if (n > 0 && n <= N)
			break;
	}

	cout << "Please, enter word\n";
	EnterArray(a, n);
	cout << "Reverse word is\n";
	Reverse(a, LengthString(a));
	DisplayWords(a, LengthString(a));
	system("pause");
	return 0;
}

int LengthString(char str[])
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void Swap(char& a, char& b)
{
	int t = a;
	a = b;
	b = t;
}

void Reverse(char a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		Swap(a[i], a[n - i - 1]);
}

void DisplayWords(char arr[], int n)
{

	for (int i = 0; i < n; i++)
	{

		cout << arr[i] << endl;
	}
}


void EnterArray(char a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}