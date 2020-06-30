// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _NUMNODE_H_
#define _NUMNODE_H_

#include "Expr_Node.h"
#include "Visitor.h"

/**
 * @class NumNode
 *
 *  Node for numbers
 */

class Num_Node : public Expr_Node
{
    public:
        Num_Node (int n); 
        ~Num_Node() {}; 
        int accept(Visitor & v);
        int value(void); 
        int getPrecedence(void);

    private:
        int n_;
};

#endif   // !defined _NUMNODE_H_