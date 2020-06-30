// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

// #include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception


//
// Base_Array
//
template <typename T>
Base_Array <T>::Base_Array (void): data_(NULL), cur_size_(10)
{
    this->data_ = new T [this->cur_size_];
}

//
// Base_Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length): data_(NULL), cur_size_(10)
{
    if (length > 0) {
        this->cur_size_ = length; 
    }

    this->data_ = new T [this->cur_size_];
}

//
// Base_Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill): data_(NULL), cur_size_(10)
{
    this->cur_size_ = length; 

    this->data_ = new T [cur_size_];

    if(this->cur_size_ > 0) {
        this->fill(fill);
    }
}

//
// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array): data_(NULL), cur_size_(10)
{
    if(array.size() > 0) {
        this->cur_size_ = array.size(); 
        this->data_ = new T [this->size()];

        if(&array != NULL) {
            for (int i = 0; i<array.size(); i++) {
                this->data_[i] = array[i];
            }
        }
    }
}

//
// ~Base_Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    if(this->data_ != NULL) {
        delete [] this->data_;
    }
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    if(this != &rhs && this->size() == rhs.size()) {
        for(int i = 0; i<rhs.size(); i++) {
            this->data_[i] = rhs[i];
        }
    }
    else if(this->size() != rhs.size()) {
        throw std::exception();
    }
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    if(index >= this->cur_size_) {  // greater than or equal because indexing at 0
        throw std::out_of_range("out of range"); 
    }

    return this->data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    if(index >= this->cur_size_) {  // greater than or equal because indexing at 0
        throw std::out_of_range("out of range"); 
    }
    return this->data_[index];
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    if(index >= this->cur_size_) {
        throw std::out_of_range("out of range"); 
    }
    return this->data_[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    if(index > this->cur_size_) {
        throw std::out_of_range("out of range"); 
    }
    else {
        this->data_[index] = value; 
    }
}

//
// find (char)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    try {
        return this->find(value, 0);
    }
    catch(...) {
        return -1; 
    }
}

//
// find (char, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    if(start < this->cur_size_) {
        for(int i = start; i < this->cur_size_; i++) {
            if(this->data_[i] == val) {
                return i; 
            }
        }
    }
    else {
        throw std::out_of_range("out of range"); 
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    if(this != &rhs) {
        // if the sizes are different, the arrays are not equivalent
        if((this->cur_size_ != rhs.size ())) {
            return false;
        }
        else {
            for(int i = 0; i < this->cur_size_; i++) {
                if (this->data_[i] != rhs[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    return !(this == &rhs);
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    for(int i = 0; i < this->cur_size_; i++) {
        this->data_[i] = value; 
    }
}
