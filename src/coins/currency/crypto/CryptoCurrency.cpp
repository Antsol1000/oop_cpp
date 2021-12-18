//
// Created by antsol on 02.11.2021.
//

#include "CryptoCurrency.h"

float CryptoCurrency::getConversionFactor() {
    return conversionFactor;
}

CryptoCurrency::CryptoCurrency(std::string name, float conversionFactor, float amount)
    : Currency(std::move(name), amount), conversionFactor(conversionFactor) {}
