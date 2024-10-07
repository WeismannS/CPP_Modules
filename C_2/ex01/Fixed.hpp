
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
        Fixed operator=(Fixed fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};



#endif

