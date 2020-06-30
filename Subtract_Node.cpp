// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Subtract_Node.h"
#include "Visitor.h"

#define SUBTRACT_PRECEDENCE 1

Subtract_Node::Subtract_Node()
{

}

Subtract_Node::~Subtract_Node()
{

}

int Subtract_Node::accept(Visitor & v)
{
    return v.visit_subtract_node(*this); 
}

int Subtract_Node::getPrecedence() 
{
    return SUBTRACT_PRECEDENCE;
}