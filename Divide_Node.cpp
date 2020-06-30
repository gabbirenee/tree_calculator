// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Divide_Node.h"
#include "Visitor.h"
// #include "Stack.h"

#define DIVIDE_PRECEDENCE 2

Divide_Node::Divide_Node()
{

}

Divide_Node::~Divide_Node()
{

}

int Divide_Node::accept(Visitor & v)
{
    return v.visit_divide_node(*this); 
}

int Divide_Node::getPrecedence() 
{
    return DIVIDE_PRECEDENCE;
}