//
// Created by antsol on 02.11.2021.
//

#ifndef C___PROJECT_FIATCURRENCY_H
#define C___PROJECT_FIATCURRENCY_H


#include "../Currency.h"
#include "../crypto/CryptoCurrency.h"

class FiatCurrency : public Currency {
    std::string countryCode;
public:
    FiatCurrency(std::string name, std::string countryCode, float amount = .0);
    std::string getCountryCode();
    std::string toString() override;
    // add value of c to this
    void operator +(CryptoCurrency* c);
    // subtract value of c from this
    void operator -(CryptoCurrency* c);
};


#endif //C___PROJECT_FIATCURRENCY_H
