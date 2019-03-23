//Filename: Project1.cpp
//Programmer:  Ramin Dehghan                                      CSCI 123, Spring 2019
//Project #1                                                      Instructor:  Timothy Mai
//Due Date:  03/09/2019                                           Date Submitted: 
//Program Description: A program to calculate referee payments based on set percentages. Assistant referees get paid 30% of total payment each,
//and center referee gets paid 40% of total. Project2, implements this by abstracting the smaller operations into a total of 8 functions.

#include <iostream>
using namespace std;

//Declaration of abstracted functions.
void getGameInformation(int&, double&); //
int getGameDuration(); //
double getPricePerMinute(); //
void refPaymentCalculation(); //
int calculateTotalPayment(int const&, double const&); //
void calculateRefPayments(int const&, int&, int&); //
void printResult(int const&, double const&, int const&, int const&, int const&); //
void mainLCV(); //


int main(void)
{
    refPaymentCalculation();
    return 0;
}


//Implementation of abstracted functions:
void getGameInformation(int& d, double& p)
{
    d = getGameDuration();
    p = getPricePerMinute();
}

int getGameDuration()
{
    cout << "Enter duration of game in minutes (between 40 and 90 in intervals of 10):\t";
    int duration;
    cin >> duration;
    if ( ! (duration%10==0 && duration>=40 && duration<=90) )
    {
        cout << "The information you entered is not correct, try again!" << endl;
        duration = getGameDuration();
    }
    return duration;
}

double getPricePerMinute()
{
    double price_per_minute;
    cout << "Enter price per minute (between $1.50 and $5.00):\t$";
    cin >> price_per_minute;
    if ( ! (price_per_minute >= 1.50 && price_per_minute <= 5.00) )
    {
        price_per_minute = getPricePerMinute();
    }
    return price_per_minute;
}

void refPaymentCalculation()
{
    int duration, tp, cp, rp;
    double ppp;
    getGameInformation(duration, ppp);
    calculateRefPayments(calculateTotalPayment(duration, ppp), cp, rp);
    printResult(duration, ppp, calculateTotalPayment(duration, ppp), cp, rp);
    mainLCV();
}

int calculateTotalPayment(int const& d, double const& p)
{
    return static_cast<int>(d*p);
}

void calculateRefPayments(int const& t, int& cP, int& arP)
{
    const double CPP = 0.4, ARPP = 0.3;
    int t_tens = (t/10)*10;
    int t_ones = t - t_tens;
    cP = t_tens * CPP;
    arP = t_tens * ARPP;
    int t_ones_copy = t_ones;
    while (t_ones_copy > 2)
    {
        cP++;
        arP++;
        t_ones_copy -= 3;
    }
    switch (t_ones_copy)
    {
        case 0:
            break;
        case 1:
            cP++;
            break;
        case 2:
            arP++;
            break;
        default:
            std::cout << "Error in distributing remainder!" << std::endl;
            break;
    }
}

void printResult(int const& d, double const& p, int const& t, int const& cP, int const& arP)
{
    std::cout << "Total duration: " << d << std::endl
              << "Total payment: $" << t << std::endl
              << "Price per minute : $" << p << std::endl
              << "Center referee payment: $" << cP << std::endl
              << "Assistant referee payment: $" << arP << std::endl;
}

void mainLCV()
{
    char lcv;
    std::cout << "Do you want to run again? y/n: ";
    std::cin >> lcv;
    std::cout << std::endl;
    if ( ! ((lcv == 'y') || (lcv == 'Y')) )
    {
        std::cout << "Bye Bye !" << std::endl;
        return;
    }
    refPaymentCalculation();
}