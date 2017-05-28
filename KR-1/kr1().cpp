#include <iostream>
#include <fstream>

using namespace std;

const int N = 256;

void ShowContentsFile(char*);

int main()
{
	char fileNameFirst[N], fileNameSecond[N];
	cout << "Please, enter the name of source files: " << endl;//1.txt and 2.txt and 3.txt
	cout << "1st file: ";
	cin.getline(fileNameFirst, N, '\n');
	cout << "2nd file: ";
	cin.getline(fileNameSecond, N, '\n');
	char fileNameNew[N];
	cout << "Please, enter the name of result file: " << endl;
	cin.getline(fileNameNew, N, '\n');

	cout << "Sourse files: " << endl;
	ShowContentsFile(fileNameFirst);
	ShowContentsFile(fileNameSecond);
	
	ifstream streamIn1(fileNameFirst);
	if (!streamIn1.is_open())
	{
		cout << "Cannot open file to read!" << endl;
	}

	ifstream streamIn2(fileNameSecond);
	if (!streamIn2.is_open())
	{
		cout << "Cannot open file to read!" << endl;
	}

	ofstream out(fileNameNew);
	if (!out.is_open())
	{
		cout << "Cannot open file to read!" << endl;
	}

	int count = 0, term1, term2;
	while (true)
	{
		streamIn1 >> term1;
		streamIn2 >> term2;
		while (!streamIn2.eof() && !streamIn1.eof())
		{
			if (term2 >= term1)
			{
				out << term1 << " ";
				streamIn1 >> term1;
			}
			else
			{
				out << term2 << " ";
				streamIn2 >> term2;
			}
		}
		if (streamIn1.eof())
		{
			while (!streamIn2.eof())
			{
				out << term2 << " ";
				streamIn2 >> term2;
			}
			break;
		}
		if (streamIn2.eof())
		{
			while (!streamIn1.eof())
			{
				out << term1 << " ";
				streamIn1 >> term1;
			}
			break;
		}
	}
	cout << "New array: " << endl;
	ShowContentsFile(fileNameNew);


}

void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	char string[N] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(string, N, '\n');
		cout << string << endl;
	}
}
