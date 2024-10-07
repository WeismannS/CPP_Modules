#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->_value = 0;
}

Fixed Fixed::operator=(Fixed &operand)
{
    std::cout << "Assignment called\n";
    this->setRawBits(operand.getRawBits());
}

Fixed::Fixed(const Fixed &fixed)
{
    this->setRawBits(fixed.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->_value = raw;
}