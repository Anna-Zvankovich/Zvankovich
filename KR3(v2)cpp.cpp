#include <iostream>

using namespace std;

void FindAndChangeWordsInString(char[], char[], char[]);
int FindPositionOfWordInString(char[], char[], int);
void ChangeString(char[], char[], char[], int);
void DisplayString(char str[]);
int LengthString(char[]);

int main()
{
	cout << "Enter String: ";
	char str[256];
	cin.getline(str, 256, '\n');
	cout << "Enter the word that you want change: ";
	char wc[256];
	cin.getline(wc, 256, '\n');
	cout << "Enter the word on that you want change: ";
	char wtc[256];
	cin.getline(wtc, 256, '\n');
	system("cls");
	DisplayString(str);
	FindAndChangeWordsInString(str, wc, wtc);
	DisplayString(str);
	system("pause");
	return 0;
}

void DisplayString(char str[])
{

	for (int i = 0; str[i] != '\0'; i++)
	{
		cout << str[i];
	}
	cout << endl;
}

int LengthString(char str[])
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void FindAndChangeWordsInString(char str[], char wc[], char wtc[])
{
	int len = LengthString(str);
	int lenW = LengthString(wtc);
	int pos = 0;
	for (int i = 0; i < len; i++)
	{
		pos = FindPositionOfWordInString(str, wc, i);
		if (pos == -1) break;
		else
		{
			ChangeString(str, wc, wtc, pos);

		}
		i += lenW + pos - 1;
	}
}

int FindPositionOfWordInString(char str[], char wc[], int k)
{
	int len = LengthString(str);
	int lenC = LengthString(wc);
	bool flag = true;
	for (int i = k; i < len; i++)
	{
		if (str[i] == wc[0] && (i + lenC) <= len)
		{
			int res = i;
			int z = 0;

			for (i; i < lenC + res; i++)
			{
				if (str[i] != wc[z])
				{
					flag = false;
					break;
				}
				z++;
			}
			if (flag == true)
			{
				return res;
			}

		}
	}
	return -1;
}

void ChangeString(char str[], char wc[], char wtc[], int n)
{
	int lenstr = LengthString(str);
	int lenwc = LengthString(wc);
	int lenwtc = LengthString(wtc);
	int k = 0;
	if (lenwc == lenwtc)
	{
		for (int i = n; i < n + lenwc; i++)
		{

			str[i] = wtc[k];
			k++;
		}
	}
	if (lenwc<lenwtc)
	{
		int z = lenwtc - lenwc;
		k = lenwtc - 1;
		str[lenstr + z] = '\0';
		for (int i = lenstr + z - 1; i > n; i--)
		{

			if (i < n + lenwtc)
			{
				str[i] = wtc[k];
				k--;
			}
			else
			{
				str[i] = str[i - z];
			}

		}
	}
	if (lenwc>lenwtc)
	{
		int z = lenwc - lenwtc;
		k = 0;
		for (int i = n; i < n + lenstr - z; i++)
		{

			if (i < n + lenwtc)
			{
				str[i] = wtc[k];
				k++;
			}
			else
			{
				str[i] = str[i + z];
			}

		}
		str[lenstr - z] = '\0';
	}
}
