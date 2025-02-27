//
// Created by User on 26.12.2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>

#include "RationalNumber.h"

#include <iostream>

template<class T>
class Program {
public:
    Program(RationalNumber<T> val1, RationalNumber<T> val2);
    std::string ShowAdditionsOperations() const;
    std::string ShowSubtractionsOperations() const;
    std::string ShowMultiplicationsOperations() const;
    std::string ShowDivisionsOperations() const;
    std::string ShowCompOperations() const;
    std::string ShowAllOperations() const;
private:
    RationalNumber<T> num1, num2;
};

template<class T>
Program<T>::Program(RationalNumber<T> val1, RationalNumber<T> val2) : num1(val1), num2(val2) {};

template<class T>
std::string Program<T>::ShowAdditionsOperations() const {
    std::string result;
    RationalNumber<T> tmp(num1);

    tmp = tmp.Sum(num2);
    result = num1.toString() + ".Sum(" + num2.toString() + ") = " + tmp.toString() + "\n";

    tmp = num1 + num2;
    result += num1.toString() + " + " + num2.toString() + " = " + tmp.toString() + "\n";

    tmp = num1;
    tmp += num2;
    result += num1.toString() + " += " + num2.toString() + " is " + tmp.toString() + "\n";

    tmp = num1;
    +tmp;
    result += "+" + num1.toString() + " is " + tmp.toString() + "\n";

    tmp = num1;
    ++tmp;
    result += "++" + num1.toString() + " is " + tmp.toString() + "\n";

    return result;
}

template<class T>
std::string Program<T>::ShowSubtractionsOperations() const {
    std::string result;
    RationalNumber<T> tmp(num1);

    tmp = tmp.Subtraction(num2);
    result = num1.toString() + ".Subtraction(" + num2.toString() + ") = " + tmp.toString() + "\n";

    tmp = num1 - num2;
    result += num1.toString() + " - " + num2.toString() + " = " + tmp.toString() + "\n";

    tmp = num1;
    tmp -= num2;
    result += num1.toString() + " -= " + num2.toString() + " is " + tmp.toString() + "\n";

    tmp = num1;
    tmp = -tmp;
    result += "-" + num1.toString() + " is " + tmp.toString() + "\n";

    tmp = num1;
    --tmp;
    result += "--" + num1.toString() + " is " + tmp.toString() + "\n";

    return result;
}

template<class T>
std::string Program<T>::ShowMultiplicationsOperations() const {
    std::string result;
    RationalNumber<T> tmp(num1);

    tmp = tmp.Multiplication(num2);
    result = num1.toString() + ".Multiplication(" + num2.toString() + ") = " + tmp.toString() + "\n";

    tmp = num1 * num2;
    result += num1.toString() + " * " + num2.toString() + " = " + tmp.toString() + "\n";

    tmp = num1;
    tmp *= num2;
    result += num1.toString() + " *= " + num2.toString() + " is " + tmp.toString() + "\n";

    return result;
}

template<class T>
std::string Program<T>::ShowDivisionsOperations() const {
    std::string result;
    RationalNumber<T> tmp(num1);

    tmp = tmp.Division(num2);
    result = num1.toString() + ".Division(" + num2.toString() + ") = " + tmp.toString() + "\n";

    tmp = num1 / num2;
    result += num1.toString() + " / " + num2.toString() + " = " + tmp.toString() + "\n";

    tmp = num1;
    tmp /= num2;
    result += num1.toString() + " /= " + num2.toString() + " is " + tmp.toString() + "\n";

    return result;
}

template<class T>
std::string Program<T>::ShowCompOperations() const {
    return num1.toString() + " == " + num2.toString() + " is " + std::to_string(num1 == num2)
    + "\n" + num1.toString() + " != " + num2.toString() + " is " + std::to_string(num1 != num2)
    + "\n" + num1.toString() + " < " + num2.toString() + " is "+ std::to_string(num1 < num2)
    + "\n" + num1.toString() + " <= " + num2.toString() + " is "+ std::to_string(num1 <= num2)
    + "\n" + num1.toString() + " > " + num2.toString() + " is "+ std::to_string(num1 > num2)
    + "\n" + num1.toString() + " >= " + num2.toString() + " is "+ std::to_string(num1 >= num2) + "\n";
}

template<class T>
std::string Program<T>::ShowAllOperations() const {
    std::string result;

    result = ShowAdditionsOperations() + '\n'
    + ShowSubtractionsOperations() + '\n'
    + ShowMultiplicationsOperations() + '\n'
    + ShowDivisionsOperations() + '\n'
    + ShowCompOperations() + '\n';

    return result;
}

#endif //PROGRAM_H
