// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _MULTIPLYNODE_H_
#define _MULTIPLYNODE_H_


#include "Binary_Op_Node.h"
#include "Visitor.h"

/**
 * @class Multiply_Node.
 *
 *  Node for multiply operator
 */

class Multiply_Node : public Binary_Op_Node
{
    public:
        Multiply_Node();
        ~Multiply_Node();
        int accept(Visitor & v); 
        int getPrecedence(void); 
};

#endif   // !defined _MULTIPLYNODE_H_