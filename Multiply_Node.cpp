// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Multiply_Node.h"
#include "Visitor.h"

#define MULTIPLY_PRECEDENCE 2

Multiply_Node::Multiply_Node()
{

}

Multiply_Node::~Multiply_Node()
{
    
}

int Multiply_Node::accept(Visitor & v)
{
    return v.visit_multiply_node(*this); 
}

int Multiply_Node::getPrecedence() 
{
    return MULTIPLY_PRECEDENCE;
}