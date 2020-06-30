// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _ADDNODE_H_
#define _ADDNODE_H_

#include "Binary_Op_Node.h"
#include "Visitor.h"

/**
 * @class AddNode
 *
 *  Node for add operator
 */

class Add_Node : public Binary_Op_Node
{
    public:
        Add_Node();
        ~Add_Node();
        int accept(Visitor & v); 
        int getPrecedence(void); 
};

#endif   // !defined _ADDNODE_H_