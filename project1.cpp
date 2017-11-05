#include <iostream>
using namespace std;

//  Mini-Project project1.cpp
//  Created by Jang Wu on 2017/9/18.
//  Purpose: Calculate the final balance

const double UNDER_BALANCE = 1000.00;
// if customer balance is lower than $1000
const double OVER_BALANCE = 15000.00;
// if customer balance is higher than $15000
const double MINIUM_INTEREST_RATE = 0.0015;
// interest rate when the balance is lower than $1000
const double MAXIMUM_INTEREST_RATE = 0.004;
// interest rate when the balance is higher than $15000
const double STANDARD_INTEREST_RATE = 0.00225;
// interest rate when the balance is between $1000 to $15000
const char YES = 'y';
// char represnts print each month by month

bool accrueInterest(
                    double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
                    );


bool accrueOneMonthsInterest(
                             double &balanceAmt,
                             const bool doPrintInfo
                             );
 

int main(){
    bool printEachMonth;
    // change monthByMonth char to bool printEachMonth
    double initialBalance;
    // store memory of custom initial balance
    char monthByMonth;
    // store memory of custom wanting to print each month or not
    int months;
    // store memory of custom saving months
    cout << "Enter the initial balance of the account: ";
    cin >> initialBalance;
    cout << "Enter the number of months to accrue interest: ";
    cin >> months;
    cout << "Show month-by-month results - 'y' for yes, any other for no: ";
    cin >> monthByMonth;
    if (monthByMonth == YES)
    {
        printEachMonth = true;
    }
    else
    {
        printEachMonth = false;
    }
    // when custom types y, bool is true. Others are false
    if (!accrueInterest(initialBalance, months, printEachMonth))
    {
        cout << "Sorry, an error was detected.  Unable to provide results!"
             << endl;
    }
    // if the balance or the months are negative, print Error
    return 0;
}

bool accrueInterest(
                    double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
                    )
{
    double initialBalance = 0;
    initialBalance = balanceAmt;
    // save the initial balance and will calculate the interest later
    if (numMonths <= 0)
    {
        cout << "ERROR in accrueInterest: numMonths must be > 0, " <<
                "but the value " << numMonths << " was provided!" << endl;
        return false;
    }
    // consider the situation when cin month is lower than 0
    for (int i = 0; i < numMonths; i ++)
    {
        if (!accrueOneMonthsInterest(balanceAmt, doPrintEachMonth))
        {
            return false;
        }
    }
    // calculate each month interest rate of custom
    cout << "Interest accrued for " << numMonths << " months!" << endl << endl;
    cout << "Initial balance: " << initialBalance << endl;
    cout << "Total interest accrued: " << balanceAmt - initialBalance << endl;
    cout << "Final balance: " << balanceAmt << endl;
    return true;
}

bool accrueOneMonthsInterest(
                             double &balanceAmt,
                             const bool doPrintInfo
                             )

{
    double initialBalance = 0;
    double initialRate = 0;
    if (balanceAmt < 0)
    {
        cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0,"
             << " but the value " << balanceAmt << " was provided!" << endl;
        return false;
    }
    // consider the situation when cin balance is lower than 0
    initialBalance = balanceAmt;
    // save the initial balance and will calculate the interest later
    if (balanceAmt < UNDER_BALANCE)
    {
        balanceAmt = balanceAmt + balanceAmt * MINIUM_INTEREST_RATE;
        initialRate = MINIUM_INTEREST_RATE;
    }
    // if custom balance is lower to $1000, the custom get minimum rate
    else if (balanceAmt >= OVER_BALANCE)
    {
        balanceAmt = balanceAmt + balanceAmt * MAXIMUM_INTEREST_RATE;
        initialRate = MAXIMUM_INTEREST_RATE;
    }
    // if custom balance is lower to $1000, the custom get maxmium rate
    else
    {
        balanceAmt = balanceAmt + balanceAmt * STANDARD_INTEREST_RATE;
        initialRate = STANDARD_INTEREST_RATE;
    }
    // if custom balance is lower to $1000, the custom get standard rate
    if (doPrintInfo)
    {
        cout << "Accruing interest for 1 month:" << endl;
        cout << "  Initial balance: " << initialBalance << endl;
        cout << "  Initial rate: " << initialRate << endl;
        cout << "  Interest accrued: " << balanceAmt - initialBalance << endl;
        cout << "  New balance: " << balanceAmt << endl;
    }
    // if custom don't want to see each month detail, skip the print
    return true;
}

