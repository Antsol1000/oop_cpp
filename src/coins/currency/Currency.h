//
// Created by antsol on 02.11.2021.
//

#ifndef C___PROJECT_CURRENCY_H
#define C___PROJECT_CURRENCY_H


#include <string>
#include <utility>

class Currency {
    std::string name;
protected:
    float amount;
    // protected constructor to avoid creating object of this class
    Currency(std::string name, float amount = .0);
public:
    std::string getName();
    float getAmount();
    virtual std::string toString();
};


#endif //C___PROJECT_CURRENCY_H
