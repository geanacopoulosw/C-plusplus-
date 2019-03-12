/*This program is so that a user can calculate a loan for someone before they take the money
  They enter the loan amount, the interest rate, and the total amount of months for the program 
  to calculate the amount of interest and monthly payment the person will spend. */


#include <iostream> // for input and output
#include <math.h> // for math calculations
#include <iomanip> // to be able to manipulate the outputs decimal place

using namespace std;

int main()
{
	//variables for the code
	const double Max_Months = 12; // sets the total amount of months to 12
	const double Max_Interest = 100; // sets the total amount on Interst to 100
	double amountWTG; 
	int interestRateWTG; 
	int monthsWTG;
	double convertInterestRateWTG;
	double convertMonthsWTG;
	double intOfLoanWTG;
	double totalIntOwedWTG;
	double amountLeftToCustomerWTG;
	double monthlyPaymentWTG;


	// section where the user inputs the variables for their loan
	cout << "Please enter the amount of money you wish to receive: ";
	cin >>  amountWTG ; // is the amount for the loan
	cout << "Please enter the interest rate: ";
	cin >> interestRateWTG; // what interst rate they will recieve
	cout << "Please enter the amount of months you will need for the loan: ";
	cin >> monthsWTG; // how long they want the months to be

	// calculation of interest and months to decimal
	convertInterestRateWTG = interestRateWTG / Max_Interest; // this is for the calculation of percent to decimal for interest
	convertMonthsWTG = monthsWTG / Max_Months; // this is for the calculation of months to years 

	// calculation of the loan info
	intOfLoanWTG = amountWTG * convertInterestRateWTG; // calculates the interest on the loan
	totalIntOwedWTG = intOfLoanWTG * convertMonthsWTG; // calculates the total intrest to be paid 
	amountLeftToCustomerWTG = amountWTG - totalIntOwedWTG; //calculates what will be left if the client was to pay the interest upfront
	monthlyPaymentWTG = amountWTG / monthsWTG; // calculates the monthly payment
	 
	// displays the loan info  
	std::cout << std::fixed << std::setprecision(2) << "\nThe value of the loan is: $" << amountWTG; // displays loan amount
	cout << "\nThe interest on the loan is: " << interestRateWTG << "%"; // displays the interest rate
	cout << "\nThe total amount of months your loan will be is: " << monthsWTG << endl; // displays the months of the loan

	std::cout << std::fixed << std::setprecision(2) << "\nThe interest amount to be paid on the loan will be: $" << totalIntOwedWTG; // displays the interets on the loan
	std::cout << std::fixed << std::setprecision(2) << "\nThe total amount that you will have after the interest will be: $" << amountLeftToCustomerWTG; // displays the amount after interest is paid
	std::cout << std::fixed << std::setprecision(2) << "\nThe monthly payments on the loan will be: $" << monthlyPaymentWTG; // displays monthly payment

	return 0;
	//end of program
}
