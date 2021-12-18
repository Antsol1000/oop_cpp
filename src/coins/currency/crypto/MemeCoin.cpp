//
// Created by antsol on 06.11.2021.
//

#include "MemeCoin.h"

MemeCoin::MemeCoin(std::string name, float conversionFactor, std::string meme, float amount)
        : CryptoCurrency(std::move(name), conversionFactor, amount), meme(std::move(meme)) {}

std::string MemeCoin::toString() {
    return Currency::toString() + ", meme: " + meme;
}

CryptoCurrency *MemeCoin::getCoin(float amount) {
    return new MemeCoin(this->getName(), this->getConversionFactor(),
                        this->meme, amount);
}