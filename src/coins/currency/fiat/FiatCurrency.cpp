//
// Created by antsol on 02.11.2021.
//

#include <stdexcept>
#include "FiatCurrency.h"


FiatCurrency::FiatCurrency(std::string name, std::string countryCode, float amount)
    : Currency(std::move(name), amount), countryCode(std::move(countryCode)) {}

std::string FiatCurrency::getCountryCode() {
    return countryCode;
}

std::string FiatCurrency::toString() {
    return Currency::toString() + " " + countryCode;
}

void FiatCurrency::operator+(CryptoCurrency* c) {
    this->amount += c->getAmount() * c->getConversionFactor();
}

void FiatCurrency::operator-(CryptoCurrency* c) {
    if (this->amount < c->getAmount() * c->getConversionFactor()) {
        throw std::invalid_argument("Not enough money!");
    }
    this->amount -= c->getAmount() * c->getConversionFactor();
}
