// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Modulus_Node.h"
#include "Visitor.h"

#define MODULUS_PRECEDENCE 2

Modulus_Node::Modulus_Node()
{

}

Modulus_Node::~Modulus_Node()
{

}

int Modulus_Node::accept(Visitor & v)
{
    return v.visit_modulus_node(*this); 
}

int Modulus_Node::getPrecedence() 
{
    return MODULUS_PRECEDENCE;
}