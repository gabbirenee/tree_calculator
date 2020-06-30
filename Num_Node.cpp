// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Num_Node.h"
#include "Visitor.h"

#define NUM_PRECEDENCE -1
// constructor 
 Num_Node::Num_Node(int n): n_(n) 
 {
 
 }

 int Num_Node::accept(Visitor & v)
 {
     return v.visit_num_node(*this); 
 }

int Num_Node::value()
{
    return this->n_;
}

int Num_Node::getPrecedence()
{
    return NUM_PRECEDENCE;
}