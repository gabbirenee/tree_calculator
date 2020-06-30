// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _SUBTRACTNODE_H_
#define _SUBTRACTNODE_H_

#include "Binary_Op_Node.h"
#include "Visitor.h"

/**
 * @class Subtract_Node
 *
 *  Node for subtraction operator
 */

class Subtract_Node : public Binary_Op_Node
{
    public:
        Subtract_Node(void);
        ~Subtract_Node(); 
        int accept(Visitor & v); 
        int getPrecedence(void); 
};

#endif   // !defined _SUBTRACTNODE_H_