// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return this->size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	// Ryan: Couldn't we just check to see if the Stack is_empty()?
	// Ryan: Is this method ideal for inlining as it is dynamic?
    // FIXED: top now just returns the size -1 which is what I should have done in the first place
    // also idk if this is still too dynamic to be here or not
	if(this->is_empty())
        throw Stack::empty_exception();
    else
        return this->arr_[this->size()-1];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if(this->size() == 0)
        return true; 
    else
        return false;
    
}
