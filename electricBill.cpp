/*
C++ Counting Change
CIS054 C/C++ Programming
Inputs: kWh
Outputs: total
*/

#include <iostream>
#include <iomanip>                      //allows 2 digits past the decimal
using namespace std;

const double TIER_1_ALLOWANCE = 350;
const double TIER_2_ALLOWANCE = 1450;
const double TIER_1_RATE = 0.23;
const double TIER_2_RATE = 0.29;
const double TIER_3_RATE = 0.45;
const double COMMISSION_TAX = 0.20;

int main()
{

    double kWh;        //total kWh used
    double totalBill;
    double tier1Usage; //amount used in tier1
    double tier2Usage; //amount used in tier2
    double tier3Usage; // amount used in tier3
    double tier1Cost;
    double tier2Cost;
    double tier3Cost;

                                        //user inputs
    cout << "Enter the number of kWh";
    cin >> kWh;

    if (cin.fail()) //error detected
{
    cout <<"Illegal non-numeric input\n";
    return 1;
    }

    if (kWh< TIER_1_ALLOWANCE){
        tier1Usage = kWh; //everything is in tier 1
        tier2Usage = 0;
        tier3Usage =0;
    }
    else if(kWh< TIER_2_ALLOWANCE){
        tier1Usage = TIER_1_ALLOWANCE;
        tier2Usage = kWh - TIER_1_ALLOWANCE; //remaining in tier 2
        tier3Usage = 0;
    }

    else{
        tier1Usage = TIER_1_ALLOWANCE;
        tier2Usage = TIER_2_ALLOWANCE-TIER_1_ALLOWANCE;
        tier3Usage = kWh - TIER_2_ALLOWANCE;
    }


tier1Cost = tier1Usage *TIER_1_RATE;
tier2Cost = tier2Usage *TIER_2_RATE;
tier3Cost = tier3Usage *TIER_3_RATE;

totalBill = tier1Cost + tier2Cost + tier3Cost + COMMISSION_TAX;

   cout << "tier 1 usage" << tier1Cost <<endl;
   cout << "tier 2 usage" << tier2Cost <<endl;
   cout << "tier 3 usage" << tier3Cost <<endl;
   cout << "Energy Commission Tax" << setprecision (3) << fixed << COMMISSION_TAX <<endl;
   cout << "Total Electric Charges" << totalBill <<endl;

    return 0;

}
