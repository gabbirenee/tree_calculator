// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _EXPRNODE_H_
#define _EXPRNODE_H_

/**
 * @class Expr_Node
 *
 *  Expression Node
 */

#include "Visitor.h"

class Expr_Node
{
    public:
        Expr_Node(void) { };
        virtual ~Expr_Node() {}; 
        virtual int accept(Visitor & v) = 0;
        virtual int getPrecedence(void) = 0; 
};

#endif   // !defined _EXPRNODE_H_