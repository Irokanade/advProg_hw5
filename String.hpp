#ifndef String_hpp
#define String_hpp

#include <cstring>
#include <iostream>

class String {
public:
    // 1. default constructor
    String(): size_(0), capacity_(0) {
        this->str_ = new char[1];
        this->str_[0] = '\0';
    }

    // 2. copy constructor
    String(const String &s): size_(s.size_), capacity_(s.size_+1) {
        this->str_ = new char[this->capacity_];
        memset(this->str_, 0, this->capacity_);
        memcpy(this->str_, s.str_, s.size_);
    }

    // 3. constructor with one parameter with type const char *
    String(const char *s): size_(std::strlen(s)), capacity_(std::strlen(s)+1) {
        // extra space for null terminating character
        this->str_ = new char[this->capacity_];
        std::strncpy(this->str_, s, this->capacity_);
    }

    // 4. destructor
    ~String() {
        delete[] this->str_;
    }

    // 5. size()
    size_t size() const {
        return this->size_;
    }

    // 6. c_str()
    const char *c_str() const {
        return this->str_;
    }

    // 7. operator []
    const char& operator[] (const size_t index) const {
        return this->str_[index];
    }
    char& operator[] (const size_t index) {
        return const_cast<char &>(static_cast<const String &>(*this)[index]);
    }

    // 8. operator +=
    String& operator+= (const String &s);
    String& operator+= (const char *s);

    // 9. clear()
    void clear();

    // 10. operator =
    String &operator= (String s);
    String &operator= (const char *s);

    // 11. swap()
    void swap(String& s);

    // compare() mf for overloading relation operations
    int compare(const String& s) const;
    int compare(const char *s) const;

private:
    char *str_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    // simulated c++ string class strncat
    String &mystrncat(String &dest, const String &src, size_t num);
    String &mystrncat(String &dest, const char *src, size_t num);

};
// A. relational operators (<, >, <=, >=, ==, !=)
// operator <
bool operator< (const String &lhs, const String &rhs);
bool operator< (const String &lhs, const char *rhs);
bool operator< (const char *lhs, const String &rhs);

// operator >
bool operator> (const String &lhs, const String &rhs);
bool operator> (const String &lhs, const char *rhs);
bool operator> (const char *lhs, const String &rhs);

// operator <=
bool operator<= (const String &lhs, const String &rhs);
bool operator<= (const String &lhs, const char *rhs);
bool operator<= (const char *lhs, const String &rhs);

// operator >=
bool operator>= (const String &lhs, const String &rhs);
bool operator>= (const String &lhs, const char *rhs);
bool operator>= (const char *lhs, const String &rhs);

// operator ==
bool operator== (const String &lhs, const String &rhs);
bool operator== (const String &lhs, const char *rhs);
bool operator== (const char *lhs, const String &rhs);

// operator !=
bool operator!= (const String &lhs, const String &rhs);
bool operator!= (const String &lhs, const char *rhs);
bool operator!= (const char *lhs, const String &rhs);

// B. operator <<, >>
std::ostream& operator<<(std::ostream&, const String&);
std::istream& operator>>(std::istream&, String&);

// C. operators +
const String operator+ (const String &lhs, const String &rhs);
const String operator+ (const String &lhs, const char *rhs);
const String operator+ (const char *lhs, const String &rhs);

#endif /* String_hpp */