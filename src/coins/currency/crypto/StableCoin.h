//
// Created by antsol on 06.11.2021.
//

#ifndef C___PROJECT_STABLECOIN_H
#define C___PROJECT_STABLECOIN_H


#include "CryptoCurrency.h"

class StableCoin : public CryptoCurrency {
    std::string fiatCurrency;
public:
    StableCoin(std::string name, float conversionFactor, std::string fiatCurrency, float amount = .0);
    std::string toString() override;
    CryptoCurrency *getCoin(float amount) override;
};


#endif //C___PROJECT_STABLECOIN_H
