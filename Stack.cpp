// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

// #include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void): arr_(0), size_(0)
{
    this->arr_ = Array<T>(10); 
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack): arr_(0), size_ (0)
{
    if(stack.is_empty() == false) {
        this->arr_ = Array<T>(stack.arr_);
        this->size_ = stack.size();
    }
    else {
        this->arr_ = Array<T>(10); 
    }
}


//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if(this->arr_.size() <= this->size()) {
        this->arr_.resize(this->size()+1); // resize the array to be bigger and allow things to be pushed onto the stack
    }
    this->size_++;
    this->arr_[this->size()-1] = element; 
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(!this->is_empty()) {
        this->size_--;
        // this->arr_[this->size()] = NULL; 
    }
    else {
        throw Stack::empty_exception();
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(rhs.is_empty()) {    // if the stack rhs is empty, make the current stack empty
        this->clear();
    }
    else {
        if(rhs.size() > this->size_) {
            this->arr_.resize(rhs.size());
        }
        this->size_ = rhs.size();
        this->arr_ = rhs.arr_; 
    }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    if(this->is_empty() == false) {
        // for(int i = 0; i < this->size(); i++) {
        //     this->arr_[i] = 0; 
        // }
        this->size_= 0; 
    }
}
