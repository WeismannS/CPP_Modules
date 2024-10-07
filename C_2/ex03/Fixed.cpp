#include "Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called\n";
    this->_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    this->setRawBits(fixed.getRawBits());
}
Fixed::Fixed(const float fl)
{
    this->setRawBits(roundf(fl * (1 << this->_fractionalBits)));
}
Fixed::Fixed(const int num)
{
    this->setRawBits((num * (1 << this->_fractionalBits)));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called\n";
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called\n";
    this->_value = raw;
}
float Fixed::toFloat(void) const
{
    return roundf(this->getRawBits()) / (1 << this->_fractionalBits);
}
int Fixed::toInt(void) const
{
    return (this->getRawBits()) / (1 << this->_fractionalBits);
}

Fixed Fixed::operator=(Fixed operand)
{
    //std::cout << "Assignment called\n";
    this->setRawBits(operand.getRawBits());
    return *this;
}

Fixed Fixed::operator+(Fixed operand)
{
    return Fixed(this->toFloat() + operand.toFloat());
}

Fixed Fixed::operator-(Fixed operand)
{
    return Fixed(this->toFloat() - operand.toFloat());
}

Fixed Fixed::operator*(Fixed operand)
{
    return Fixed(this->toFloat() * operand.toFloat());
}

Fixed Fixed::operator/(Fixed operand)
{
    return Fixed(this->toFloat() / operand.toFloat());
}

bool Fixed::operator>(Fixed operand)
{
    return this->toFloat() > operand.toFloat();
}

bool Fixed::operator<(Fixed operand)
{
    return this->toFloat() < operand.toFloat();
}

bool Fixed::operator>=(Fixed operand)
{
    return this->toFloat() >= operand.toFloat();
}

bool Fixed::operator<=(Fixed operand)
{
    return this->toFloat() <= operand.toFloat();
}

bool Fixed::operator==(Fixed operand)
{
    return this->toFloat() == operand.toFloat();
}

bool Fixed::operator!=(Fixed operand)
{
    return this->toFloat() != operand.toFloat();
}

Fixed Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_value++;
    return temp;
}

Fixed Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return  (Fixed &) a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (Fixed &) a > b ? a : b;
}
