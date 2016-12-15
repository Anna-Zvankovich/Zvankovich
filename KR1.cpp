#include <iostream> 

using namespace std;
const int N = 100;
bool Switch(char b[N], char a[N], char str[]);
int LengthString(char string[]);

int main()
{

	char a[] = { 15,22,26,9,13,29,24,28,28,27 };
	char b[N] = { "" };
	char str[N] = { "" };
	int n = 27;
	for (int i = 1; i < n; i++)
	{
		b[i] = 123 - i;
		b[27] = '!';
		b[28] = '+';
		b[29] = ' ';
	}
	Switch(b, a, str);
	cout << str << endl;
	system("pause");
	return 0;
}

bool Switch(char b[], char a[N], char str[])
{
	int N = LengthString(a);
	for (int i = 0; i < N; i++)
	{
		if (a[i] < 0 || a[i]>29)
		{
			cout << "Input Error" << endl;
			return false;
		}
		str[i] = b[a[i]];
	}
}

int LengthString(char string[])
{
	int i = 0;
	while (string[i])
		i++;
	return i;
}
