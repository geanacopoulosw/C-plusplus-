#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num1WTG;
	int num2WTG;
	int answerWTG;
	
	cout << "Please enter a number for num1WTG: \n";
	cin >> num1WTG;
	cout << "Please enter a number for num2WTG: \n";
	cin >> num2WTG;
	
	answerWTG = num1WTG / num2WTG;
	cout << "The answer is: " << answerWTG;
	answerWTG = num1WTG % num2WTG;
	cout << "\nThe remainder is: " << answerWTG;
	
	return 0;
}