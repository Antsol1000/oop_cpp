//
// Created by antsol on 06.11.2021.
//

#ifndef C___PROJECT_MEMECOIN_H
#define C___PROJECT_MEMECOIN_H


#include "CryptoCurrency.h"

class MemeCoin : public CryptoCurrency {
    std::string meme;
public:
    MemeCoin(std::string name, float conversionFactor, std::string meme, float amount = 0);
    std::string toString() override;
    CryptoCurrency *getCoin(float amount) override;
};


#endif //C___PROJECT_MEMECOIN_H
