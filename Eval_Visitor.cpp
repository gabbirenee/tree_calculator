// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#include "Eval_Visitor.h"

int Eval_Visitor::visit_num_node(Num_Node & numNode)
{
    return numNode.value();     // get the value of the number node
}

int Eval_Visitor::visit_add_node(Add_Node & addNode)
{
    int left = addNode.getLeftChild()->accept(*this); 
    int right = addNode.getRightChild()->accept(*this);
    return left + right; 
}

int Eval_Visitor::visit_divide_node(Divide_Node & divideNode)
{
    int left = divideNode.getLeftChild()->accept(*this); 
    int right = divideNode.getRightChild()->accept(*this);
    if(left == 0) { // handle divide by 0
        throw std::exception(); 
    }
    return left / right; 
}

int Eval_Visitor::visit_modulus_node(Modulus_Node & modulusNode) 
{
    int left = modulusNode.getLeftChild()->accept(*this); 
    int right = modulusNode.getRightChild()->accept(*this);
    if(left == 0) { // handle divide by 0
        throw std::exception(); 
    }
    return left % right; 
}

int Eval_Visitor::visit_multiply_node(Multiply_Node & multiplyNode)
{
    int left = multiplyNode.getLeftChild()->accept(*this); 
    int right = multiplyNode.getRightChild()->accept(*this);
    return left * right; 
}

int Eval_Visitor::visit_subtract_node(Subtract_Node & subtractNode)
{
    int left = subtractNode.getLeftChild()->accept(*this); 
    int right = subtractNode.getRightChild()->accept(*this);
    return left - right; 
}