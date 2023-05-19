#include "String.hpp"

String& String::operator+= (const String &s) {
    // check if enough capacity
    size_t newSize = this->size_+s.size_;

    // use > operator to account for null terminating character
    if(this->capacity_ > newSize) {
        // if enough capacity then just strncat
        this->mystrncat(*this, s, this->capacity_);
    } else {
        // else reallocate memory
        String temp = *this;

        delete[] this->str_;
        this->capacity_ = newSize+1;
        this->str_ = new char[this->capacity_]; 
        memset(this->str_, 0, this->capacity_);
        memcpy(this->str_, temp.str_, temp.size_);
        this->mystrncat(*this, s, this->capacity_);
    }

    this->size_ = newSize;

    // return existing object for chaining
    return *this;
}

String& String::operator+= (const char *s) {
    // c string version
    size_t newSize = this->size_ + strlen(s);

    if(this->capacity_ > newSize) {
        this->mystrncat(*this, s, this->capacity_);
        // std::strncat(this->str_, s, this->capacity_);
    } else {
        String temp = *this;
        // this->mystrncpy(temp, *this, this->size_+1);
        // std::strncpy(temp, this->str_, this->size_+1);

        delete[] this->str_;
        this->capacity_ = newSize+1;
        this->str_ = new char[this->capacity_]; 
        memset(this->str_, 0, this->capacity_);
        memcpy(this->str_, temp.str_, temp.size_);
        this->mystrncat(*this, s, this->capacity_);
        // std::strncpy(this->str_, temp, this->capacity_);
        // std::strncat(this->str_, s, this->capacity_);
    }

    this->size_ = newSize;

    // return existing object for chaining
    return *this;
}

void String::clear() {
    for(size_t i = 0; i < this->capacity_; ++i) {
        this->str_[i] = 0;
    }

    this->size_ = 0;
}

String& String::operator= (String s) {
    this->swap(s);
    return *this;
}

String& String::operator= (const char *s) {
    size_t newSize = std::strlen(s);

    // check if enough capacity
    if(this->capacity_ > newSize) {
        // just strncpy
        memset(this->str_, 0, this->capacity_);
        memcpy(this->str_, s, newSize);
        // std::strncpy(this->str_, s, this->capacity_);
    } else {
        // else reallocate memory
        delete[] this->str_;
        this->capacity_ = newSize+1;
        this->str_ = new char[this->capacity_]; 
        memset(this->str_, 0, this->capacity_);
        memcpy(this->str_, s, newSize);
        // std::strncpy(this->str_, s, this->capacity_);
    }

    this->size_ = newSize;

    // return existing object for chaining
    return *this;
}

void String::swap(String& s) {
    if(this == &s) {
        return;
    }
    char *const tmpStr = this->str_;
    const size_t tmpSize = this->size_;
    const size_t tmpCapacity = this->capacity_;

    this->str_ = s.str_;
    this->size_ = s.size_;
    this->capacity_ = s.capacity_;

    s.str_ = tmpStr;
    s.size_ = tmpSize;
    s.capacity_ = tmpCapacity;
}

int String::compare(const String& s) const {
    if (this->size_ == s.size_) {
        return memcmp(this->str_, s.str_, s.size_);
    } else {
        return this->size_ < s.size_ ? -1 : 1;
    }
}
int String::compare(const char *s) const {
    String temp(s);
    return this->compare(temp);
}

String &String::mystrncat(String &dest, const String &src, size_t num) {
    // assume capacity is enough
    memset(dest.str_+dest.size_, 0, num-dest.size_);
    memcpy(dest.str_+dest.size_, src.str_, src.size_);

    return dest;
}

String &String::mystrncat(String &dest, const char *src, size_t num) {
    std::strncat(dest.str_, src, dest.capacity_);
    return dest;
}

std::ostream& operator<< (std::ostream& os, const String& s) {
    for(size_t i = 0; i < s.size(); ++i) {
        os << s[i];
    }
    return os;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.clear();

    // verify no errors are set, flush tied streams, strip leading whitespace.
    std::istream::sentry sentry(in);
    if (!sentry) {
        return in;
    }

    int next;
    while ((next = in.get()) != in.eof() && !std::isspace(next)) {
        char tempStr[2] = {static_cast<char>(next), 0};
        s += tempStr;
    } 

    return in;
}

// operator <
bool operator< (const String &lhs, const String &rhs) {
    return (lhs.compare(rhs) < 0);
}

bool operator< (const String &lhs, const char *rhs) {
    return (lhs.compare(rhs) < 0);
}

bool operator< (const char *lhs, const String &rhs) {
    return (String(lhs).compare(rhs) < 0);
}

// operator >
bool operator> (const String &lhs, const String &rhs) {
    return (lhs.compare(rhs) > 0);
}

bool operator> (const String &lhs, const char *rhs) {
    return (lhs.compare(rhs) > 0);
}

bool operator> (const char *lhs, const String &rhs) {
    return (String(lhs).compare(rhs) > 0);
}

// operator <=
bool operator<= (const String &lhs, const String &rhs) {
    return (lhs.compare(rhs) <= 0);
}

bool operator<= (const String &lhs, const char *rhs) {
    return (lhs.compare(rhs) <= 0);
}

bool operator<= (const char *lhs, const String &rhs) {
    return (String(lhs).compare(rhs) <= 0);
}

// operator >=
bool operator>= (const String &lhs, const String &rhs) {
    return (lhs.compare(rhs) >= 0);
}

bool operator>= (const String &lhs, const char *rhs) {
    return (lhs.compare(rhs) >= 0);
}

bool operator>= (const char *lhs, const String &rhs) {
    return (String(lhs).compare(rhs) >= 0);
}

// operator ==
bool operator== (const String &lhs, const String &rhs) {
    return (lhs.compare(rhs) == 0);
}

bool operator== (const String &lhs, const char *rhs) {
    return (lhs.compare(rhs) == 0);
}

bool operator== (const char *lhs, const String &rhs) {
    return (String(lhs).compare(rhs) == 0);
}

// operator !=
bool operator!= (const String &lhs, const String &rhs) {
    return (lhs.compare(rhs) != 0);
}

bool operator!= (const String &lhs, const char *rhs) {
    return (lhs.compare(rhs) != 0);
}

bool operator!= (const char *lhs, const String &rhs) {
    return (String(lhs).compare(rhs) != 0);
}

// binary operator +
const String operator+ (const String &lhs, const String &rhs) {
    String temp = lhs;
    temp += rhs;
    return temp;
}

const String operator+ (const String &lhs, const char *rhs) {
    String temp = lhs;
    temp += rhs;
    return temp;
}

const String operator+ (const char *lhs, const String &rhs) {
    String temp = lhs;
    temp += rhs;
    return temp;
}