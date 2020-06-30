// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _DIVIDENODE_H_
#define _DIVIDENODE_H_

#include "Binary_Op_Node.h"
#include "Visitor.h"

/**
 * @class Divide_Node
 *
 *  Node for divide operator
 */

class Divide_Node : public Binary_Op_Node
{
    public:
        Divide_Node();
        ~Divide_Node();
        int accept(Visitor & v); 
        int getPrecedence(void); 
};

#endif   // !defined _DIVIDENODE_H_