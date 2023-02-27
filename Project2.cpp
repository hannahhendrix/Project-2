//Hannah Hendrix 
//1-26-2023

#include <iostream> 
#include <iomanip>
using namespace std;

float initialInvestment;
float monthlyDeposit;
float annualInterest;
float years;
float months;
float totalAmount;
float interestAmount;
float totalInterest;

void displayMenu() {
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years " << endl;
	system("PAUSE"); //waits for input


}

void displayBalanceWithout() {
	cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
	cout << "=============================================================" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "-------------------------------------------------------------" << endl;
}

void displayBalanceWith() {
	cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
	cout << "=============================================================" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "-------------------------------------------------------------" << endl;
}
int main() {
	displayMenu();
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment; //takes userinput for initial deposit
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit; //takes user input for monthly deposit
	cout << "Annual Interest: %";
	cin >> annualInterest; //takes userinput for interest rate
	cout << "Number of years ";
	cin >> years;
	months = years * 12;
	system("PAUSE"); //waits for input

	totalAmount = initialInvestment;

	displayBalanceWithout();

	for (int i = 0; i < years; ++i) {
		interestAmount = (annualInterest / 100) * totalAmount; //formula for yearly interest
		totalAmount += interestAmount; //year end total
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << interestAmount << endl;
	}


	displayBalanceWith();

	for (int i = 0; i < years; ++i) {
		totalInterest = 0;
		for (int j = 0; j < 12; ++j) {
			interestAmount = ((annualInterest / 100) / 12) * (totalAmount + monthlyDeposit); //monthly interest formula
			totalInterest += interestAmount;
			totalAmount += monthlyDeposit + interestAmount;
		}
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << totalInterest << endl;
	}
}