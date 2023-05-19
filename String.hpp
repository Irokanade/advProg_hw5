#ifndef String_hpp
#define String_hpp

#include <cstring>
#include <iostream>

class String {
public:
    // 1. default constructor
    String();

    // 2. copy constructor
    String(const String &s);

    // 3. constructor with one parameter with type const char *
    String(const char *s);

    // 4. destructor
    ~String();

    // 5. size()
    size_t size() const;

    // 6. c_str()
    const char *c_str() const;

    // 7. operator []
    const char& operator[] (const size_t index) const;
    char& operator[] (const size_t index);

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
    String &mystrcat(String &dest, const String &src);
    String &mystrcat(String &dest, const char *src);

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