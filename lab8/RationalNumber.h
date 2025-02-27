//
// Created by User on 26.12.2024.
//

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <string>
#include <numeric>
#include <fstream>
#include <iostream>

template <class T>
class RationalNumber {
private:
  T numerator_;
  T denominator_;

  void normalize();
public:
  RationalNumber(T numerator = 0, T denominator = 1);
  RationalNumber(const RationalNumber<T>& y) = default;
  ~RationalNumber() = default;

  std::string toString() const;

  RationalNumber Sum(const RationalNumber& another) const;
  RationalNumber Subtraction(const RationalNumber& another) const;
  RationalNumber Division(const RationalNumber& another) const;
  RationalNumber Multiplication(const RationalNumber& another) const;

  RationalNumber& operator + ();

  RationalNumber& operator - ();

  RationalNumber operator + (const RationalNumber &another)const;
  RationalNumber operator - (const RationalNumber &another)const;
  RationalNumber operator * (const RationalNumber &another)const;
  RationalNumber operator / (const RationalNumber &another)const;

  RationalNumber& operator += (const RationalNumber &another);
  RationalNumber& operator -= (const RationalNumber &another);
  RationalNumber& operator *= (const RationalNumber &another);
  RationalNumber& operator /= (const RationalNumber &another);

  bool operator == (const RationalNumber &another)const;
  bool operator != (const RationalNumber &another)const;
  bool operator < (const RationalNumber &another)const;
  bool operator > (const RationalNumber &another)const;
  bool operator <= (const RationalNumber &another)const;
  bool operator >= (const RationalNumber &another)const;

  RationalNumber& operator = (const RationalNumber &another);
  RationalNumber& operator ++ ();
  RationalNumber operator ++ (int);
  RationalNumber& operator -- ();
  RationalNumber operator -- (int);

  template<class T1>
  friend std::ifstream& operator >> (std::ifstream& fin, RationalNumber<T1>& number);

  template<class T1>
  friend std::ofstream& operator << (std::ofstream& fout, const RationalNumber<T1>& number);
};

template<class T>
RationalNumber<T>::RationalNumber(T numerator, T denominator) : numerator_(numerator), denominator_(denominator) {
  if (denominator_ == 0) {
    throw std::invalid_argument("incorrect number");
  }
  normalize();
}

template<class T>
void RationalNumber<T>::normalize() {
  if (denominator_ == 0) {
    throw std::invalid_argument("incorrect number");
  }
  T gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;

  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
}

template<class T>
std::string RationalNumber<T>::toString() const{
  std::string res;
  res += std::to_string(numerator_) + "/" + std::to_string(denominator_);
  return res;
}

template<class T>
RationalNumber<T> RationalNumber<T>::Sum(const RationalNumber &another) const {
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.denominator_ + another.numerator_ * denominator_;
  result.denominator_ = denominator_ * another.denominator_;

  result.normalize();
  return result;
}

template<class T>
RationalNumber<T> RationalNumber<T>::Subtraction(const RationalNumber &another) const {
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.denominator_ - another.numerator_ * denominator_;
  result.denominator_ = denominator_ * another.denominator_;

  result.normalize();
  return result;
}

template<class T>
RationalNumber<T> RationalNumber<T>::Multiplication(const RationalNumber &another) const {
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.numerator_;
  result.denominator_ = denominator_ * another.denominator_;

  result.normalize();
  return result;
}

template<class T>
RationalNumber<T> RationalNumber<T>::Division(const RationalNumber &another) const {
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.denominator_;
  result.denominator_ = denominator_ * another.numerator_;

  result.normalize();
  return result;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator + () {
  normalize();
  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator - () {
  normalize();

  numerator_ = -numerator_;
  return *this;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator+(const RationalNumber &another) const {
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.denominator_ + another.numerator_ * denominator_;
  result.denominator_ = denominator_ * another.denominator_;

  result.normalize();

  return result;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator - (const RationalNumber &another) const{
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.denominator_ - another.numerator_ * denominator_;
  result.denominator_ = denominator_ * another.denominator_;

  result.normalize();

  return result;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator * (const RationalNumber &another) const {
  RationalNumber result;

  result.numerator_ = numerator_ * another.numerator_;
  result.denominator_ = denominator_ * another.denominator_;

  result.normalize();

  return result;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator / (const RationalNumber &another) const {
  RationalNumber<T> result;

  result.numerator_ = numerator_ * another.denominator_;
  result.denominator_ = denominator_ * another.numerator_;

  result.normalize();

  return result;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator+=(const RationalNumber &another) {
  numerator_ = numerator_ * another.denominator_ + another.numerator_ * denominator_;
  denominator_ = denominator_ * another.denominator_;

  normalize();

  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator -=(const RationalNumber &another) {
  numerator_ = numerator_ * another.denominator_ - another.numerator_ * denominator_;
  denominator_ = denominator_ * another.denominator_;

  normalize();

  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator*=(const RationalNumber &another) {
  numerator_ *= another.denominator_;
  denominator_ *= another.denominator_;

  normalize();

  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator/=(const RationalNumber &another) {
  numerator_ *= another.denominator_;
  denominator_ *= another.numerator_;

  normalize();

  return *this;
}

template<class T>
bool RationalNumber<T>::operator==(const RationalNumber &another) const {
  if (numerator_ == another.numerator_ && denominator_ == another.denominator_) {
    return true;
  }
  return false;
}

template<class T>
bool RationalNumber<T>::operator!=(const RationalNumber &another) const {
  if (*this == another) {
    return false;
  }
  return true;
}

template<class T>
bool RationalNumber<T>::operator>(const RationalNumber &another) const {
  if (numerator_ * another.denominator_ > another.numerator_ * denominator_) {
    return true;
  }
  return false;
}

template<class T>
bool RationalNumber<T>::operator<(const RationalNumber &another) const {
  if (*this > another || *this == another) {
    return false;
  }
  return true;
}

template<class T>
bool RationalNumber<T>::operator>=(const RationalNumber &another) const {
  if (*this < another) {
    return false;
  }
  return true;
}

template<class T>
bool RationalNumber<T>::operator<=(const RationalNumber &another) const {
  if (*this > another) {
    return false;
  }
  return true;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator = (const RationalNumber &another) {
  numerator_ = another.numerator_;
  denominator_ = another.denominator_;

  normalize();

  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator ++ () {
  numerator_ += denominator_;

  normalize();

  return *this;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator ++(int) {
  RationalNumber<T> temp = *this;
  ++(*this);

  normalize();

  return temp;
}

template<class T>
RationalNumber<T> &RationalNumber<T>::operator--() {
  numerator_ -= denominator_;

  normalize();

  return *this;
}


template<class T>
RationalNumber<T> RationalNumber<T>::operator--(int) {
  RationalNumber<T> temp = *this;
  --(*this);

  normalize();

  return temp;
}

template<class T>
std::istream& operator >> (std::istream& fin, RationalNumber<T>& number) {
  number.normalize();

  T numerator;
  T denominator;

  fin >> numerator;
  fin >> denominator;

  number = RationalNumber<T>(numerator, denominator);

  return fin;
}

template<class T1>
std::ostream& operator << (std::ostream& fout, const RationalNumber<T1>& number) {
  fout << number.toString();

  return fout;
}

#endif //RATIONALNUMBER_H
