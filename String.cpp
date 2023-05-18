#include "String.hpp"

String& String::operator+= (const String &s) {
    // check if enough capacity
    size_t newSize = this->size_+s.size_;

    // use > operator to account for null terminating character
    if(this->capacity_ > newSize) {
        // if enough capacity then just strncat
        std::strncat(this->str_, s.str_, this->capacity_);
    } else {
        // else reallocate memory
        char *temp = new char[this->size_+1];
        std::strncpy(temp, this->str_, this->size_+1);

        delete[] this->str_;
        this->capacity_ = newSize+1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, temp, this->capacity_);
        std::strncat(this->str_, s.str_, this->capacity_);
        delete[] temp;
    }

    this->size_ = newSize;

    // return existing object for chaining
    return *this;
}

String& String::operator+= (const char *s) {
    // c string version
    size_t newSize = this->size_ + strlen(s);

    if(this->capacity_ > newSize) {
        std::strncat(this->str_, s, this->capacity_);
    } else {
        char *temp = new char[this->size_+1];
        std::strncpy(temp, this->str_, this->size_+1);

        delete[] this->str_;
        this->capacity_ = newSize+1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, temp, this->capacity_);
        std::strncat(this->str_, s, this->capacity_);
        delete[] temp;
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

String& String::operator= (const String &s) {
    // check if enough capacity
    if(this->capacity_ > s.size_) {
        // just strncpy
        std::strncpy(this->str_, s.str_, this->capacity_);
    } else {
        // else reallocate memory
        delete[] this->str_;
        this->capacity_ = s.size_+1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, s.str_, this->capacity_);
    }

    this->size_ = s.size_;

    // return existing object for chaining
    return *this;
}

String& String::operator= (const char *s) {
    size_t newSize = std::strlen(s);

    // check if enough capacity
    if(this->capacity_ > newSize) {
        // just strncpy
        std::strncpy(this->str_, s, this->capacity_);
    } else {
        // else reallocate memory
        delete[] this->str_;
        this->capacity_ = newSize+1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, s, this->capacity_);
    }

    this->size_ = newSize;

    // return existing object for chaining
    return *this;
}

void String::swap(String& s) {
    String temp = *this;
    *this = s;
    s = temp;
}

std::ostream& operator<< (std::ostream& os, const String& s) {
    os << s.c_str();
    return os;
}

// operator <
bool operator< (const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) < 0);
}

bool operator< (const String &lhs, const char *rhs) {
    return (std::strcmp(lhs.c_str(), rhs) < 0);
}

bool operator< (const char *lhs, const String &rhs) {
    return (std::strcmp(lhs, rhs.c_str()) < 0);
}

// operator >
bool operator> (const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

bool operator> (const String &lhs, const char *rhs) {
    return (std::strcmp(lhs.c_str(), rhs) > 0);
}

bool operator> (const char *lhs, const String &rhs) {
    return (std::strcmp(lhs, rhs.c_str()) > 0);
}

// operator <=
bool operator<= (const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

bool operator<= (const String &lhs, const char *rhs) {
    return (std::strcmp(lhs.c_str(), rhs) <= 0);
}

bool operator<= (const char *lhs, const String &rhs) {
    return (std::strcmp(lhs, rhs.c_str()) <= 0);
}

// operator >=
bool operator>= (const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

bool operator>= (const String &lhs, const char *rhs) {
    return (std::strcmp(lhs.c_str(), rhs) >= 0);
}

bool operator>= (const char *lhs, const String &rhs) {
    return (std::strcmp(lhs, rhs.c_str()) >= 0);
}

// operator ==
bool operator== (const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator== (const String &lhs, const char *rhs) {
    return (std::strcmp(lhs.c_str(), rhs) == 0);
}

bool operator== (const char *lhs, const String &rhs) {
    return (std::strcmp(lhs, rhs.c_str()) == 0);
}

// operator !=
bool operator!= (const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) != 0);
}

bool operator!= (const String &lhs, const char *rhs) {
    return (std::strcmp(lhs.c_str(), rhs) != 0);
}

bool operator!= (const char *lhs, const String &rhs) {
    return (std::strcmp(lhs, rhs.c_str()) != 0);
}

// binary operator +
String operator+ (const String &lhs, const String &rhs) {
    String temp = lhs;
    temp += rhs;
    return temp;
}

String operator+ (const String &lhs, const char *rhs) {
    String temp = lhs;
    temp += rhs;
    return temp;
}

String operator+ (const char *lhs, const String &rhs) {
    String temp = lhs;
    temp += rhs;
    return temp;
}