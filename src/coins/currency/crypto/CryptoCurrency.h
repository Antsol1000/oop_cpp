//
// Created by antsol on 02.11.2021.
//

#ifndef C___PROJECT_CRYPTOCURRENCY_H
#define C___PROJECT_CRYPTOCURRENCY_H


#include "../Currency.h"

class CryptoCurrency : public Currency {
    float conversionFactor;
protected:
    CryptoCurrency(std::string name, float conversionFactor, float amount = .0);
public:
    float getConversionFactor();
    // return new coin with same params and given amount
    virtual CryptoCurrency* getCoin(float amount) = 0;
};


#endif //C___PROJECT_CRYPTOCURRENCY_H
