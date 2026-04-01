#include <iostream>
#include <concepts>

template<typename I> 
requires std::integral<I> 
class rational {
    I num_;
	I den_;
    I algoritmo_mcd(I a, I b) const {
        if (a < I{0}) a = -a;
        if (b < I{0}) b = -b;
        while (b > I{0}) {
            I temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void semplifica() {
        if (den_ == I{0}) {
            if (num_ > I{0}) num_ = I{1};
            else if (num_ < I{0}) num_ = -I{1};
            return;
        }
        if (num_ == I{0}) {
            den_ = I{1};
            return;
        }
        I MCD = algoritmo_mcd(num_, den_);
        num_ /= MCD;
        den_ /= MCD;
        if (den_ < I{0}) {
            num_ = -num_;
            den_ = -den_;
        }
    }
    bool is_nan() const { return den_ == I{0} && num_ == I{0}; }
    bool is_inf() const { return den_ == I{0} && num_ != I{0}; }

public:
    rational() 
        : num_(I{0}), den_(I{1}) 
    {}
    rational(I n, I d) 
        : num_(n), den_(d) 
    {
        semplifica();
    }
    I num() const { return num_; }
    I den() const { return den_; }
    rational& operator+=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0}; den_ = I{0};
        } else if (is_inf() && other.is_inf()) {
            if (num_ != other.num_) { num_ = I{0}; den_ = I{0}; }
        } else if (other.is_inf()) {
            num_ = other.num_; den_ = I{0};
        } else if (!is_inf()) {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ = den_ * other.den_;
            semplifica();
        }
        return *this;
    }

    rational& operator-=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0}; den_ = I{0};
        } else if (is_inf() && other.is_inf()) {
            if (num_ == other.num_) { num_ = I{0}; den_ = I{0}; }
        } else if (other.is_inf()) {
            num_ = -other.num_; den_ = I{0};
        } else if (!is_inf()) {
            num_ = num_ * other.den_ - other.num_ * den_;
            den_ = den_ * other.den_;
            semplifica();
        }
        return *this;
    }

    rational& operator*=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0}; den_ = I{0};
        } else if ((is_inf() && other.num_ == I{0}) || (num_ == I{0} && other.is_inf())) {
            num_ = I{0}; den_ = I{0};
        } else {
            num_ *= other.num_;
            den_ *= other.den_;
            semplifica();
        }
        return *this;
    }

    rational& operator/=(const rational& other) {
        if (is_nan() || other.is_nan() || (is_inf() && other.is_inf()) || (num_ == I{0} && other.num_ == I{0})) {
            num_ = I{0}; den_ = I{0};
        } else {
            I new_num = num_ * other.den_;
            I new_den = den_ * other.num_;
            num_ = new_num;
            den_ = new_den;
            semplifica();
        }
        return *this;
    }
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& v) {
    if (v.den() == I{0}) {
        if (v.num() == I{0}) os << "NaN"; 
        else if (v.num() > I{0}) os << "+Inf";
        else os << "-Inf";
    } else {
        os << v.num() << "/" << v.den();
    }
    return os;
}

