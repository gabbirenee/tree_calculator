// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

//Ryan: A better choice here would be to inherit from a base class and move all of the "common" methods
// to a base class and then allow our Array here to play more of a dynamic role vs. our Fixed Array.
// FIXED: added Base_Array class to inherit from

//
// max_size
//
template <typename T>
inline
size_t Array <T>::max_size (void) const
{
    return this->max_size_;
}
