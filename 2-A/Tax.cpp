#include "Tax.hpp"
#include "TaxConstants.hpp"
#include "TaxDataType.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

//Preconditions: 
    //- struct defined in separate file for holding tax payer info,
    //- vector created to hold info on various structs of tax payer info,
    //- both struct object and vector passed through function call
//Postconditions:
    //- info collected on tax payers and stored in vector
    //- number of payers defined by const SIZE in TaxConstants.hpp
void taxTake(std::vector<taxInfo> &payers, taxInfo &taxPayers)
{
    std::cout<<"Enter the tax information for "<<TAXCONSTANTS::SIZE<<" tax payers:\n";
    bool validNum = false;

    //loop to take info for num of payers defined in "TaxConstants.hpp"
    for(int i = 0; i < TAXCONSTANTS::SIZE; i++)
    {
        //initialized inputs for use in isValid() function
        float incomeInput = 0, rateInput = 0;
        
        do
        {
            std::cout<<"\nEnter this year's income for tax payer "<<i+1<<": ";
            validNum = isValid(incomeInput);
        } while (!validNum); //loops until validNum = true
        
        do
        {
            std::cout<<"Enter the tax rate for tax payer "<<i+1<<": ";
            validNum = isValid(rateInput);
        } while (!validNum); //loops until validNum = true;
        
        //storing entered values into struct
        taxPayers.income = incomeInput;
        taxPayers.rate = rateInput;
        float calcTaxes = incomeInput * rateInput;
        taxPayers.taxes = calcTaxes;

        //pushing struct into vector at current index
        payers.push_back(taxPayers);
    }
}

//Preconditions:
    //- info taken in taxTake()
    //- both vector and struct object (same as in taxTake()) passed into function call
//Postconditions:
    //- info for each index of vector is displayed nicely
void printTax(std::vector<taxInfo> &payers, taxInfo &taxPayers)
{
    //display formatting
    std::cout<<std::fixed<<std::showpoint<<std::setprecision(2);

    //loop to print taxes value from each struct in the vector
    std::cout<<"Taxes due for this year: \n\n";
    for(int i = 0; i < payers.size(); i++)
    {
        std::cout<<"Tax Payer "<<i+1<<": $"<<payers[i].taxes<<"\n";
    }
}

//Preconditions:
    //- float num initialized before function call
    //- said float num passed through function call
//Postcontiions:
    //- bool returned true if num is valid input
    //- bool returned false if num is invalid input
bool isValid(float &num)
{
    bool valid = false;

    //validation loop to check if num is postive number
    std::cin>>num;
    if(!std::cin.fail() && std::cin && num >= 0)
    {
        valid = true;
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"\nInvalid Input\nPlease enter a positive number.";
    }
    return valid; //used for loop in taxTake() to ensure valid input
}
