//
// Created by antsol on 06.11.2021.
//

#include "StableCoin.h"

StableCoin::StableCoin(std::string name, float conversionFactor, std::string fiatCurrency, float amount)
        : CryptoCurrency(std::move(name), conversionFactor, amount), fiatCurrency(std::move(fiatCurrency)) {}

std::string StableCoin::toString() {
    return Currency::toString() + ", pegged by " + fiatCurrency;
}

CryptoCurrency *StableCoin::getCoin(float amount) {
    return new StableCoin(this->getName(), this->getConversionFactor(),
                          this->fiatCurrency, amount);
}