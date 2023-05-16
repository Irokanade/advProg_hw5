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
        strncpy(this->str_, s.str_, s.size_);
    }

    // 3. constructor with one parameter with type const char *
    String(const char *s) {
        this->size_ = strlen(s);
        // extra space for null terminating character
        this->capacity_ = this->size_ + 1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, s, this->size_);
    }
    // 4. destructor
    ~String() {
        delete[] this->str_;
    }

    // using Proxy class to implement [] set and get function
    class Proxy {
    public:
        friend class String;
        // conversion operator
        operator char() const {
            return m_s.get(m_index);
        }

        Proxy& operator= (char value) {
            m_s.set(m_index, value);
            return *this;
        }

    private:
        // using initializer list constructor
        Proxy(String &s, size_t index): m_s(s), m_index(index) {}
        String &m_s;
        size_t m_index; 
    };

    // 5. size()
    size_t size() const {
        return this->size_;
    }
    
    // 6. c_str()
    const char *c_str() const {
        const char *temp = this->str_;
        return temp;
    }

    // 7. operator []
    // read write
    Proxy operator[] (size_t index) {
        return Proxy(*this, index);
    }
    // read only
    const char operator[] (size_t index) const {
        return this->str_[index];
    }

    // 8. operator +=
    String& operator+= (String const &s);
    String& operator+= (const char *s);

    // 9. clear()
    void clear();

    // 10. operator =
    String &operator= (String const &s);
    String &operator= (const char *s);

    // 11. swap()

private:
    char *str_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    const char get(size_t index) const {return this->str_[index];}
    void set(size_t index, char value) {this->str_[index] = value;}
};
// A. relational operators (<, >, <=, >=, ==, !=)
// B. operator <<, 
std::ostream& operator<<(std::ostream&, const String&);

#endif /* String_hpp */