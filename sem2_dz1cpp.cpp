#include <iostream> 


using namespace std;


void enterArr(int* arr, int n);
void printArr(int* arr, int n);
void specialSortArr(int* arr, int n, int a, int b);
void newArr(int* arr1, int* arr2, int n);
void delRepeating(int* arr, int&n);
void delEl(int* arr, int El, int n);
int reverseNumber(int t);


int main()
{
	int n;
	cout << " Size of array= ";
	cin >> n;
	int* arr1 = new int[n];
	int* arr2 = new int[n];
	enterArr(arr1, n);
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


void enterArr(int* arr, int n)
{
	cout << "Array "<< endl;
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