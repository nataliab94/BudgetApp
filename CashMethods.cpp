#include "CashMethods.h"

bool CashMethods::validateAmount(string amount)
{
    if (amount.empty())
        return false;

    bool decimalPointFound = false;
    int decimalPlaces = 0;


    for (size_t i = 0; i < amount.length(); ++i)
    {
        if (amount[i] == '.')
        {
            if (decimalPointFound)
            {
                return false;
            }
            decimalPointFound = true;
        }
        else if (!isdigit(amount[i]))
        {
            return false;
        }
        else if (decimalPointFound)
        {
            decimalPlaces++;
        }
    }

    if (decimalPlaces > 2)
    {
        return false;
    }

    if (amount[0] == '-')
    {
        return false;
    }

    return true;

}
