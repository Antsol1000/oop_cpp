//
// Created by antsol on 06.11.2021.
//

#ifndef C___PROJECT_TRADER_H
#define C___PROJECT_TRADER_H

#include<random>
#include<iostream>
#include "../currency/crypto/CryptoCurrency.h"
#include "../currency/fiat/FiatCurrency.h"
#include "../../wallet/Wallet.h"


class Trader {
    float pSell, pBuy;
    std::default_random_engine gen;
    std::vector<CryptoCurrency*> coins;
public:
    Trader(float pSell, float pBuy, std::vector<CryptoCurrency*> coins);
    // generate n random coins (from this->coins) with values from (0, maxAmount)
    void generateCoins(Wallet<CryptoCurrency, FiatCurrency>* wallet, int n, float maxAmount);
    // buy coin with given probability pBuy and sell with probability pSell
    void trade(Wallet<CryptoCurrency, FiatCurrency>* wallet);
};


#endif //C___PROJECT_TRADER_H
