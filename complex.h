#pragma once

#include <ostream>
class complex
{
public:
    complex(int re = 0, int im = 0)
        : real_(re), imag_(im) { }
    int get_real() const { return real_; }
    int get_imag() const { return imag_; }

    complex& operator+=(const complex &rhs)
    {
        this->real_ += rhs.real_;
        this->imag_ += rhs.imag_;
        return *this;
    }

private:
    int real_;
    int imag_;
};

std::ostream& operator<<(std::ostream & os, const complex &rhs)
{
    return os << "(" << rhs.get_real() << ", " 
        << rhs.get_imag() << ")";
}

complex operator+(complex lhs, const complex &rhs)
{
    return lhs += rhs;
}

bool operator==(const complex &lhs, const complex &rhs)
{
    return (lhs.get_real() == rhs.get_real()
        && lhs.get_imag() == rhs.get_imag());
}

bool operator!=(const complex &lhs, const complex &rhs)
{
    return !(lhs == rhs);
}