//
// Created by antsol on 02.11.2021.
//

#ifndef C___PROJECT_WALLET_H
#define C___PROJECT_WALLET_H

#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

template <typename C, typename F>
class Wallet {

    friend class Trader;

    std::vector<C*> coins;
    F* money;
    std::string owner;

public:

    Wallet(std::string owner, F* money) : owner(std::move(owner)), money(money) {}

    ~Wallet() {
        for (auto c: coins) {
            delete c;
        }
        delete money;
    }

    bool isEmpty() {
        return coins.empty();
    }

    std::string toString() {
        std::string result = "This is " + owner + "'s wallet. Money: "
                             + money->toString() + "\nCoins:\n";
        for (auto c : coins) {
            result += c->toString() + "\n";
        }
        return result;
    }

    // add coin to wallet
    void operator+(C* coin) {
        *money - coin;
        coins.push_back(coin);
    }

    // remove coin from wallet
    void operator-(C* coin) {
        *money + coin;
        delete coin;
        coins.erase(std::find(coins.begin(), coins.end(), coin));
    }
};


#endif //C___PROJECT_WALLET_H
