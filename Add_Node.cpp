// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Add_Node.h"
#include "Visitor.h"

#define ADD_PRECEDENCE 1 

Add_Node::Add_Node()
{

}

Add_Node::~Add_Node()
{

}

int Add_Node::accept(Visitor & v)
{
    return v.visit_add_node(*this); 
}

int Add_Node::getPrecedence() 
{
    return ADD_PRECEDENCE;
}