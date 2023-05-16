#ifndef String_hpp
#define String_hpp

#include <cstring>

class String {
public:
    // 1. default constructor
    String() {
        //do smtg
    }

    // 2. copy constructor
    String(const String &s) {
        this->size_ = s.size_;
    }

    // 3. constructor with one parameter with type const char *
    String(char *s) {
        this->size_ = strlen(s);
        // extra space for null terminating character
        this->capacity_ = this->size_ + 1;
        this->str_ = new char[this->capacity_]; 
        std::strncpy(this->str_, s, this->size_);
    }
    // 4. destructor
    // 5. size()
    size_t size() {
        return this->size_;
    }
    // 6. c_str()
    const char *c_str() {
        return this->str_;
    }

    // 7. operator []
    const char operator[] (size_t index) {
        return this->str_[index];
    }
    // 8. operator +=
    String& operator+= (String const &s) {
        // update size and capacity
        this->size_ += s.size_;
        this->capacity_ += s.size_;


        // temp c string of original String
        char temp[(this->size_)+1];
        strncpy(temp, this->str_, this->size_);

        // delete old string
        delete[] this->str_;
        // allocate new space for new string
        this->str_ = new char[this->capacity_]; 
        // copy original string
        std::strncpy(this->str_, s.str_, this->size_);
        // copy new string to our object
        std::strncpy(this->str_, s.str_, this->size_);

        // delete temp


        // return existing object for chaining
        return *this;
    }

    // 9. clear()
    // 10. operator =
    String &operator= (String const &s) {
        this->size_ = s.size_;
        this->capacity_ = s.capacity_;
        // delete old string
        delete[] this->str_;
        // allocate new space for new string
        this->str_ = new char[this->capacity_]; 
        // copy new string to our object
        std::strncpy(this->str_, s.str_, this->size_);

        // return existing object for chaining
        return *this;
    }

    // 11. swap()
    

private:
    char *str_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};
// A. relational operators (<, >, <=, >=, ==, !=)
// B. operator <<, 

#endif /* String_hpp */