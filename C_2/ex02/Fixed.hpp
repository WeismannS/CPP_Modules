
#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>
class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const float fl);
        Fixed(const int num);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed operator=(Fixed fixed);
        Fixed operator+(Fixed fixed);
        Fixed operator-(Fixed fixed);
        Fixed operator*(Fixed fixed);
        Fixed operator/(Fixed fixed);
        bool operator>(Fixed fixed);
        bool operator<(Fixed fixed);
        bool operator>=(Fixed fixed);
        bool operator<=(Fixed fixed);
        bool operator==(Fixed fixed);
        bool operator!=(Fixed fixed);
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};



#endif