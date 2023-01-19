#include "Tax.hpp"
#include "TaxConstants.hpp"
#include "TaxDataType.hpp"
#include <iostream>
#include <iomanip>
#include <vector>


void taxTake(std::vector<taxInfo> payers, taxInfo &taxPayers)
{
    for(int i = 0; i < TAXCONSTANTS::SIZE; i++)
    {
        float incomeInput, rateInput;
        std::cout<<"Enter the tax information for"<<TAXCONSTANTS::SIZE<<" tax payers:\n";
        std::cout<<"\nEnter this year's income for tax payer "<<i<<": ";
        std::cin>>incomeInput;
        std::cout<<"\nEnter the tax rate for tax payer "<<i<<": ";
        std::cin>>rateInput;
        taxPayers.income = incomeInput;
        taxPayers.rate = rateInput;
        taxPayers.taxes = incomeInput * rateInput;
        payers.push_back(taxPayers);
    }
}

void printTax(std::vector<taxInfo> payers, taxInfo &taxPayers)
{
    std::cout<<"Taxes due for this year: \n\n";
    for(int i = 0; i < payers.size(); i++)
    {
        std::cout<<"Tax Payer "<<i<<": $"<<payers[i].taxes<<"\n";
    }
}
