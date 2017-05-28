
#include <iostream> 
#include<fstream>


using namespace std;


void enterArr(int* arr, int n);
void printArr(int* arr, int n);
void specialSortArr(int* arr, int n, int a, int b);
void newArr(int* arr1, int* arr2, int n);
void delRepeating(int* arr, int&n);
void delEl(int* arr, int El, int n);
int reverseNumber(int t);
int* readFile(char* fileName);
void createFile(char* fileName, int n);
int ContentsFile(char*);
int* InitArray(char* fileName, int n);
void AddFile(char* fileName, int* arr, int n);


int main()
{

	char* fileName = "text.txt";
	int n;
	cout << "kol-vo elementov" << endl;
	cin >> n;
	createFile(fileName, n);
	//int* arr = InitArray(fileName, n);
	//createFile(fileName, n);
	int* arr1 = InitArray(fileName, n);
	int* arr2 = new int[n];

	//enterArr(arr1, n);

	delRepeating(arr1, n);
	cout << "Deleted repeating\n";
	printArr(arr1, n);
	int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	specialSortArr(arr1, n, a, b);
	cout << "Arr1 after sort = ";
	printArr(arr1, n);
	newArr(arr1, arr2, n);
	cout << "Arr2 = ";
	printArr(arr2, n);
	AddFile(fileName, arr1, n);
	AddFile(fileName, arr2, n);
	system("pause");


	return 0;
}

void specialSortArr(int* arr, int n, int a, int b)
{
	int r1, r2;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < n - 1; i++)
		{
			r1 = (arr[i] % a) - (arr[i] % b);
			r2 = (arr[i + 1] % a) - (arr[i + 1] % b);
			if (r1 > r2)
			{
				swap(arr[i], arr[i + 1]);
				flag = true;
			}
		}
	}
}
void AddFile(char* fileName, int* arr, int n)
{
	ofstream out(fileName, ios::app);
	if (!out.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		//system("pause");
		exit(1);
	}
	out << endl;
	for (int i = 0; i < n; i++)
	{
		out.width(5);
		out << arr[i];
	}
	out.close();
}
int ContentsFile(char* fileName)
{
	ifstream in(fileName);
	if (!in.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		//system("pause");
		exit(1);
	}
	int count = 0, term;
	while (!in.eof())
	{
		in >> term;
		cout << term;
		count++;
	}
	in.close();
	return count;
}
int* InitArray(char* fileName, int n)
{
	ifstream in(fileName);
	if (!in.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		//system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		//cin >> arr[i];
		in >> arr[i];
		cout << arr[i] << "  ";
	}
	in.close();
	return arr;
}

int* readFile(char* fileName) {
	ifstream streamIn(fileName);

	if (!streamIn.is_open()) {
		cout << "can not open file to write" << endl;
		exit(1);
	}

	int size = 0, *t;
	streamIn >> size;
	t = new int[size];
	for (int i = 0; i < size; i++)
		streamIn >> t[i];

	streamIn.close();
	return t;
}

void createFile(char* fileName, int n) {

	ofstream streamOut(fileName);	//ofstream - запись в файл, ifstream - чтение из файла

	if (!streamOut.is_open()) {
		cout << "can not open file to write" << endl;
		exit(1);
	}

	int temp = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			flag = false;
			streamOut << n << " ";
		}
		cout << "Input temp: ";
		cin >> temp;
		streamOut << " " << temp;
	}

	streamOut.close();
}


void enterArr(int* arr, int n)
{
	cout << "Array " << endl;
	for (int i = 0; i < n; i++)
		cin >> *(arr + i);
}
int reverseNumber(int t)
{
	int ans = 0;
	while (t > 0)
	{
		ans *= 10;
		ans += t % 10;
		t /= 10;
	}
	return ans;
}

void printArr(int* arr, int n)
{

	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

void delEl(int* arr, int El, int n)
{
	for (int i = El; i < n - 1; i++)
		*(arr + i) = *(arr + i + 1);
}

void delRepeating(int* arr, int&n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j]) { delEl(arr, j, n); j--; n--; }
}
void newArr(int* arr1, int* arr2, int n)
{

	for (int i = 0; i < n; i++)
		*(arr2 + i) = reverseNumber(*(arr1 + i));
}
