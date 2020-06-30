// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


#include "Binary_Op_Node.h"


Binary_Op_Node::Binary_Op_Node(void): left_child_(NULL), right_child_(NULL)
{

}
Binary_Op_Node::~Binary_Op_Node()
{
    // delete the node, left child, and right child
    if(this->getLeftChild() != NULL) {
        delete this->left_child_;
    }
    if(this->getRightChild() != NULL) {
        delete this->right_child_;
    }
}

void Binary_Op_Node::setLeftChild(Expr_Node * child)
{
    this->left_child_ = child; 
}
void Binary_Op_Node::setRightChild(Expr_Node * child)
{
    this->right_child_ = child; 
}
Expr_Node * Binary_Op_Node::getLeftChild(void)
{
    return this->left_child_;
}
Expr_Node * Binary_Op_Node::getRightChild(void)
{
    return this->right_child_; 
}