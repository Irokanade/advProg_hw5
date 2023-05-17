#ifndef String_hpp
#define String_hpp

#include <cstring>
#include <ostream>

class String {
public:
    // 1. default constructor
    String() {
        this->size_ = 0;
        this->capacity_ = 0;
        this->str_ = nullptr;
    }

    // 2. copy constructor
    String(const String &s) {
        this->size_ = s.size_;
        this->capacity_ = s.size_;
        this->str_ = new char[this->capacity_+1];
        strncpy(this->str_, s.str_, this->capacity_);
    }

    // 3. constructor with one parameter with type const char *
    String(const char *s) {
        this->size_ = strlen(s);
        // extra space for null terminating character
        this->capacity_ = this->size_ + 1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, s, this->capacity_);
    }
    // 4. destructor
    ~String() {
        delete[] this->str_;
    }

    // using Proxy class to implement [] set and get function
    class Proxy {
    public:
        friend class String;
        // getter
        // conversion operator
        operator char() const {
            return *m_char;
        }

        // setter
        Proxy& operator= (char value) {
            *m_char = value;
            return *this;
        }

    private:
        // using initializer list constructor
        Proxy(char& c): m_char(&c) {}
        char *m_char;
    };

    // 5. size()
    size_t size() const {
        return this->size_;
    }

    // 6. c_str()
    const char *c_str() const {
        return this->str_;
    }

    // 7. operator []
    // using proxy class to help
    Proxy operator[] (size_t index) {
        return Proxy(this->str_[index]);
    }

    // 8. operator +=
    String& operator+= (const String &s);
    String& operator+= (const char *s);

    // 9. clear()
    void clear();

    // 10. operator =
    String &operator= (const String &s);
    String &operator= (const char *s);

    // 11. swap()
    void swap(String& s);

private:
    char *str_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};
// A. relational operators (<, >, <=, >=, ==, !=)
bool operator< (const String &lhs, const String &rhs);
bool operator< (const String &lhs, const char *rhs);
bool operator< (const char *lhs, const String &rhs);

// B. operator <<, 
std::ostream& operator<<(std::ostream&, const String&);

// C. operators +
String operator+ (const String &lhs, const String &rhs);
String operator+ (const String &lhs, const char *rhs);
String operator+ (const char *lhs, const String &rhs);

#endif /* String_hpp */