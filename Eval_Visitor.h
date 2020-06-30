// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _EVALVISITOR_H_
#define _EVALVISITOR_H_

/**
 * @class Expr_Node
 *
 *  Expression Node
 */

#include "Visitor.h"
#include "Expr_Node.h"
#include "Num_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Modulus_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include <exception>

// class Num_Node;
// class Add_Node;
// class Divide_Node;
// class Modulus_Node;
// class Multiply_Node;
// class Subtract_Node; 

class Eval_Visitor : public Visitor
{
    public:
        int visit_num_node(Num_Node & numNode);
        int visit_add_node(Add_Node & addNode);
        int visit_divide_node(Divide_Node & divideNode);
        int visit_modulus_node(Modulus_Node & modulusNode);
        int visit_multiply_node(Multiply_Node & multiplyNode);
        int visit_subtract_node(Subtract_Node & subtractNode);
};

#endif   // !defined _EVALVISITOR_H_