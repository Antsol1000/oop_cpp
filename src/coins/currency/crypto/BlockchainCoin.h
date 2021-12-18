//
// Created by antsol on 02.11.2021.
//

#ifndef C___PROJECT_BLOCKCHAINCOIN_H
#define C___PROJECT_BLOCKCHAINCOIN_H


#include "CryptoCurrency.h"

class BlockchainCoin : public CryptoCurrency {
    long timestamp;
public:
    BlockchainCoin(std::string name, float conversionFactor, float amount = .0);
    std::string toString() override;
    CryptoCurrency *getCoin(float amount) override;
};


#endif //C___PROJECT_BLOCKCHAINCOIN_H
