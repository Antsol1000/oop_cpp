//
// Created by antsol on 02.11.2021.
//

#include "BlockchainCoin.h"
#include <ctime>

BlockchainCoin::BlockchainCoin(std::string name, float conversionFactor, float amount)
    : CryptoCurrency(std::move(name), conversionFactor, amount) {
    this->timestamp = std::time(nullptr);
}

std::string BlockchainCoin::toString() {
    return Currency::toString() + ", timestamp: " + std::to_string(timestamp);
}

CryptoCurrency *BlockchainCoin::getCoin(float amount) {
    return new BlockchainCoin(this->getName(), this->getConversionFactor(), amount);
}
