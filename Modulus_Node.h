// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _MODULUSNODE_H_
#define _MODULUSNODE_H_


#include "Binary_Op_Node.h"
#include "Visitor.h"

/**
 * @class Modulus_Node
 *
 *  Node for modulus operator
 */

class Modulus_Node : public Binary_Op_Node
{
    public:
        Modulus_Node();
        ~Modulus_Node();
        int accept(Visitor & v); 
        int getPrecedence(void); 
};

#endif   // !defined _MODULUSNODE_H_