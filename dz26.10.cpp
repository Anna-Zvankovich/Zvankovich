#include<iostream>
#include<math.h>

using namespace std;

long long ToDelete(long long, short);
void ToDeleteAgain(long long&, short);
long long ToDelete2(long long &, short, short);

int main()
{
	while (true)
	{
		long long number;
		cout << "enter number" << endl;
		cin >> number;
		short digit,k;
		cout << "enter digit" << endl;
		cin >> digit;
		cout << "enter k" << endl;
		cin >> k;
		//long long answer = ToDelete(number, digit);
		//cout << number << " -> " << answer << endl;
		//long long copy = number;
		///ToDeleteAgain(number, digit);
		//cout << copy << " -> " << number << endl;
		ToDelete2(number, digit, k);
		cout << number << "->" << endl;

	}
}

long long ToDelete(long long number, short digit)
{
	long long power = -1, answer = 0;
	short remainder;
	while (number)
	{
		remainder = number % 10;
		if (remainder != digit)
		{
			power++;
			answer = answer + remainder * pow(10, power);
		}
		number = number / 10;
	}
	return answer;
}

void ToDeleteAgain(long long& number, short digit)
{
	long long power = -1, answer = 0;
	short remainder;
	while (number)
	{
		remainder = number % 10;
		if (remainder != digit)
		{
			power++;
			answer = answer + remainder * pow(10, power);
		}
		number = number / 10;
	}
	number = answer;
	return;
}

long long ToDelete2(long long & number, short digit, short k)
{ 

	long long power = -1, answer = 0;
	short remainder;
	
	while (number)
	{
		remainder = number % 10;
		if (remainder == digit)
		{
			power++;
			answer = answer + k * pow(10, power);
		}
		
		else if (remainder != digit)
		{
			power++;
			answer = answer + remainder * pow(10, power);
		}
		number = number / 10;
	}
	cout << answer;
	
	return answer;
}


