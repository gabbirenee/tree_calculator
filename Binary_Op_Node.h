// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _BINARYOPNODE_H_
#define _BINARYOPNODE_H_

#include "Expr_Node.h"
#include "Visitor.h"
#include "Stack.h"

/**
 * @class Binary_Op_Node
 *
 *  Nodes for Binary Operators
 */

class Binary_Op_Node : public Expr_Node
{
    public:
        Binary_Op_Node(void);
        virtual ~Binary_Op_Node();
        virtual int accept(Visitor & v) = 0; 
        void setLeftChild(Expr_Node * child);
        void setRightChild(Expr_Node * child);
        Expr_Node * getLeftChild(void);
        Expr_Node * getRightChild(void);
        virtual int getPrecedence() = 0; 

    protected:
        Expr_Node * left_child_;
        Expr_Node * right_child_; 
};

#endif   // !defined _BINARYOPNODE_H_