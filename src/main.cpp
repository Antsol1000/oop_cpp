#include <iostream>

#include "wallet/Wallet.h"
#include "coins/coins.h"

const std::string OWNER = "Antoni Solarski";

const std::string FIAT_MONEY_NAME = "Dollar";
const std::string COUNTRY_CODE = "USA";
const float INITIAL_AMOUNT = 100.0;
const float MAX_AMOUNT_FOR_GENERATING = 10.0;

const float P_SELL = .6;
const float P_BUY = .3;

const int INITIAL_COINS_NUMBER = 3;

int main() {
    CryptoCurrency* COINS[4] = {
            new BlockchainCoin("Bitcoin", 13.13),
            new BlockchainCoin("Litecoin", 2.59),
            new StableCoin("Tether", 1.12, "Dollar"),
            new MemeCoin("Dogecoin", 9.18, "doge")
    };
    std::vector<CryptoCurrency*> possible_coins(std::begin(COINS), std::end(COINS));

    Trader trader(P_SELL, P_BUY, possible_coins);
    auto w = new Wallet<CryptoCurrency, FiatCurrency>(
            OWNER,
            new FiatCurrency(FIAT_MONEY_NAME,COUNTRY_CODE, INITIAL_AMOUNT));
    trader.generateCoins(w, INITIAL_COINS_NUMBER, MAX_AMOUNT_FOR_GENERATING);

    std::cout << w->toString();
    std::cout << std::endl;
    while (!w->isEmpty()) {
        trader.trade(w);
        std::cout << std::endl;
        std::cout << w->toString();
        std::cout << std::endl;
    }

    for (auto c : possible_coins) {
        delete c;
    }
    delete w;
    return 0;
}
