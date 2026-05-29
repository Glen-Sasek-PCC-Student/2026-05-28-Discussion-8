// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// Your grandparents are retiring, and they would like you and your programming partner to write them a program to keep track of their monthly budget and expenses. Your program must include functions to ask them for all of their monthly income sources (social security, pensions, retirement savings) and another function to ask them for their monthly expenses (food, housing, car, medical, entertainment). Feel free to change the income and expense categories, but you must have at least three for income and three for expenses. Each function should be passed a variable for income or expense by reference, prompt for the income/expenses, validate (do not accept values less than $0), and update the income/expenses variable.
// After calculating the total income and total expenses, send those variables to another function to print the results. Print a message and the amount they are over or under, or if their income and expenses are equal.
// Optional: Prompt for their savings amount. If their expenses are over their monthly budget, tell them how many months their savings will last before they run out!


//  must include:
//  monthly income (at least three)
//      social security, 
//      pensions, 
//      retirement savings
//
//  monthly expenses (at least three)
//        food, 
//        housing, 
//        car, 
//        medical, 
//        entertainment
//
// Each function should be passed a variable for income or expense by reference, prompt for the income/expenses, 
// validate (do not accept values less than $0), and update the income/expenses variable.
// 
// After calculating the total income and total expenses, send those variables to another function to print the results. 
// Print a message and the amount they are over or under, or 
// if their income and expenses are equal.
// Prompt for their savings amount. 
// If their expenses are over their monthly budget, 
// tell them how many months their savings will last before they run out!


// ------------- CODE -------------
#include <iostream>
#include <cmath>

using namespace std;


const string LABEL_MONTHLY_STATEMENT_HEADER = "Monthly Statement";
const string LABEL_MONTHLY_CREDIT = "CREDIT: ";
const string LABEL_MONTHLY_DEBIT = "DEBIT:";
const string MESSAGE_MONTHLY_EQUAL = "Congratulations, a perfectly balanced budget month!";
const string LABEL_MONTHLY_DEBIT_SUMMARY = "This month you are over-budget by: ";
const string LABEL_MONTHLY_CREDIT_SUMMARY = "This month you are under budget, saving: ";

const string ERROR_OUT_OF_RANGE = "ERROR;( Out of range.";

const string PROMPT_SOCIAL_SECURITY = "Enter Social Security: ";
const string PROMPT_PENSION = "Enter Pension: ";
const string PROMPT_SALES = "Enter Sales: ";
const double MIN_INCOME = 0.0;
const double MAX_INCOME = 1000000;

const string PROMPT_FOOD = "Enter Food Cost: ";
const string PROMPT_HOUSING = "Enter Housing Cost: ";
const string PROMPT_CAR = "Enter Car Payment plus Expenses: ";
const string PROMPT_MEDICAL = "Enter Medical Bills: ";
const string PROMPT_ENTERTAINMENT = "Enter Entertainment: ";
const double MIN_EXPENSE = 0.0;
const double MAX_EXPENSE = 1000000;

// Function prototypes (if any)


// After calculating the total income and total expenses, send those variables to another function to print the results. 
// Print a message and the amount they are over or under, or 
// if their income and expenses are equal.
void printMonthlyStatement(double credit_USD, double debit_USD);

void getIncome(double& income_USD);
void getExpenses(double& expenses_USD);

double readDoubleInInclusiveRange(string prompt, double min, double max);
void readDouble(string prompt, double &n);


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
  double debit_USD = 0.0;
  double credit_USD = 0.0;

  getIncome(credit_USD);
  getExpenses(debit_USD);
  printMonthlyStatement(credit_USD, debit_USD);

  return 0;
}

// Function implementations (if any)
// After calculating the total income and total expenses, send those variables to another function to print the results. 
// Print a message and the amount they are over or under, or 
// if their income and expenses are equal.
void printMonthlyStatement(double credit_USD, double debit_USD) {
  cout << endl;
  cout << LABEL_MONTHLY_STATEMENT_HEADER << endl;
  cout << LABEL_MONTHLY_CREDIT << credit_USD << endl;
  cout << LABEL_MONTHLY_DEBIT << debit_USD << endl;

  double abs_balance_USD = fabs(credit_USD - debit_USD);

  if(credit_USD == debit_USD) {
    cout << MESSAGE_MONTHLY_EQUAL << endl;
  } else if(credit_USD < debit_USD) {
    cout << LABEL_MONTHLY_DEBIT_SUMMARY << abs_balance_USD << endl;
  } else {
    cout << LABEL_MONTHLY_CREDIT_SUMMARY << abs_balance_USD << endl;
  }
}


//  monthly income (at least three)
//      social security, 
//      pensions, 
//      retirement savings
//
void getIncome(double& income_USD){
  income_USD = 0.0;
  income_USD += readDoubleInInclusiveRange(PROMPT_SOCIAL_SECURITY, MIN_INCOME, MAX_INCOME);
  income_USD += readDoubleInInclusiveRange(PROMPT_PENSION, MIN_INCOME, MAX_INCOME);
  income_USD += readDoubleInInclusiveRange(PROMPT_SALES, MIN_INCOME, MAX_INCOME);
}

//  monthly expenses (at least three)
//        food, 
//        housing, 
//        car, 
//        medical, 
//        entertainment
void getExpenses(double& expenses_USD) {
  expenses_USD = 0.0;
  expenses_USD += readDoubleInInclusiveRange(PROMPT_CAR, MIN_EXPENSE, MAX_EXPENSE);
  expenses_USD += readDoubleInInclusiveRange(PROMPT_ENTERTAINMENT, MIN_EXPENSE, MAX_EXPENSE);
  expenses_USD += readDoubleInInclusiveRange(PROMPT_FOOD, MIN_EXPENSE, MAX_EXPENSE);
  expenses_USD += readDoubleInInclusiveRange(PROMPT_HOUSING, MIN_EXPENSE, MAX_EXPENSE);
  expenses_USD += readDoubleInInclusiveRange(PROMPT_MEDICAL, MIN_EXPENSE, MAX_EXPENSE);
}





// Read all the scores from the user. 
// Any time you read a score you must call this function. 
// The function must do data validation
//     It is a numeric value. 
//     It is within the range of 0 to 4 inclusive.
void readDouble(string prompt, double &n) {
  bool next = true;
  while(next) {
    cout << prompt;
    cin >> n;
    if(cin) {
      next = false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << ERROR_OUT_OF_RANGE << endl;
    }
  }
}

// Reprompt until valid
double readDoubleInInclusiveRange(string prompt, double min, double max) { 
  double n = 0;
  bool next = true;
  while(next) {
    readDouble(prompt, n);
    if(min <= n && n <= max) {
      next = false;
    } else {
      cout << ERROR_OUT_OF_RANGE << " [" << min << ", " << max << "]" << endl;
    }
  }
  return n;
}


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
Define the input variables including name data type. 

B. OUTPUT
Define the output variables including data types. 

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


SAMPLE RUNS
Copy from assignment document.

*/
