//
// Created by antsol on 02.11.2021.
//

#include "Currency.h"

Currency::Currency(std::string name, float amount) : name(std::move(name)), amount(amount) {}

std::string Currency::toString() {
    return std::to_string(amount) + " " + name;
}

std::string Currency::getName() {
    return name;
}

float Currency::getAmount() {
    return amount;
}
