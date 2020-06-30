// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

// #include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//Ryan: A better choice here would be to inherit from a base class and move all of the "common" methods
// to a base class and then allow our Array here to play more of a dynamic role vs. our Fixed Array.
// FIXED: inheritance :(

//
// Array
//
template <typename T>
Array<T>::Array(void) : Base_Array<T>(10), max_size_(10)
{
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length): Base_Array<T>(length), max_size_(0)
{
    if (length > 0) {
        this->max_size_ = length;
        this->cur_size_ = length; 
    }
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill): Base_Array<T>(length), max_size_(0)
{
    if (length > 0) {
        this->max_size_ = length;
        this->cur_size_ = length; 
    }

    this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array): Base_Array<T>(array), max_size_(0)
{
    if(array.size() > 0) {
        this->max_size_ = array.max_size();
    }
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if(this != &rhs) {
        if(rhs.max_size() != this->max_size_) {
            this->resize(rhs.max_size()); 
        }

        this->cur_size_ = rhs.size(); 

        for(int i = 0; i<rhs.size(); i++) {
            Base_Array<T>::data_ [i] = rhs[i];
        }
    }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    // if new_size < max_size_ -- truncate the array
    if(new_size < this->max_size_) {
        this->max_size_ = new_size; 
        this->cur_size_ = new_size; 
    }
    // if new_size > max_size_ -- make array bigger; don't set the new spaces to any value
    else if (new_size > this->max_size_) {
        T *temp = new T [new_size];

        for(int i = 0; i < this->max_size_; i++) {
            temp[i] = Base_Array<T>::data_ [i];
        }

        delete [] Base_Array<T>::data_ ; 

        // remake data_
        Base_Array<T>::data_  = new T[new_size];

        for(int i = 0; i < this->max_size_; i++) {
            Base_Array<T>::data_ [i] = temp[i];
        }

        this->cur_size_ = new_size;
        this->max_size_ = new_size; 

        delete [] temp; 
    }
    // if new_size = max_size_ -- update cur_size_
    else if (new_size = this->max_size_) {
        this->cur_size_ = new_size; 
    }
}
