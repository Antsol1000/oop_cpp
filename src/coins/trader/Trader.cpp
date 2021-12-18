//
// Created by antsol on 06.11.2021.
//

#include "Trader.h"

// helper function to select random element from container
template<typename Iter, typename RandomGenerator>
Iter selectRandomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

Trader::Trader(float pSell, float pBuy, std::vector<CryptoCurrency*> coins) : pSell(pSell), pBuy(pBuy), coins(std::move(coins))  {
    unsigned int seed = std::time(nullptr);
    gen = std::default_random_engine(seed);
}

void Trader::generateCoins(Wallet<CryptoCurrency, FiatCurrency>* wallet, int n, float maxAmount) {
    std::uniform_real_distribution<> e(0, maxAmount);
    while (n-- > 0) {
        CryptoCurrency* c = *selectRandomly(coins.begin(), coins.end(), gen);
        float amount = e(gen);
        wallet->coins.push_back(c->getCoin(amount));
    }
}

void Trader::trade(Wallet<CryptoCurrency, FiatCurrency>* wallet) {
    std::cout << "Starting trading...\n";
    std::uniform_real_distribution<> e(0, 1);

    if (e(gen) <= pSell) {
        CryptoCurrency* c = *selectRandomly(wallet->coins.begin(), wallet->coins.end(), gen);
        std::cout << "Sold " << c->toString() << std::endl;
        *wallet - c;
    }

    if (e(gen) <= pBuy) {
        CryptoCurrency* c = *selectRandomly(coins.begin(), coins.end(), gen);
        // here we don't want to buy too much to avoid errors
        std::uniform_real_distribution<> g(0, wallet->money->getAmount() / c->getConversionFactor());
        CryptoCurrency* new_coin = c->getCoin(g(gen));
        std::cout << "Bought " << new_coin->toString() << std::endl;
        *wallet + new_coin;
    }

    std::cout << "Ending trading...\n";
}
