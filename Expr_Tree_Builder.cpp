// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder()
{

}

Expr_Tree_Builder::~Expr_Tree_Builder()
{
    while(!this->tree_.is_empty()){
        if(this->tree_.top() != NULL) {
            delete this->tree_.top();
            this->tree_.pop();
        }
    }
    while(!this->opStack_.is_empty()) {
        if(this->opStack_.top() != NULL) {
            delete this->opStack_.top();
            this->opStack_.pop();
        }
    }
}

void Expr_Tree_Builder::handleOperator(int precedence)
{
    if(!this->opStack_.is_empty()) {
        Expr_Node * top = this->opStack_.top();
        while(!this->opStack_.is_empty() && precedence < top->getPrecedence()) {
            this->popConnectPush(); 
            if(!opStack_.is_empty())
                top = this->opStack_.top();
        }
    }
}

void Expr_Tree_Builder::popConnectPush()
{
    Binary_Op_Node * N = this->opStack_.top(); 
    this->opStack_.pop(); 

    Expr_Node * rightChild = this->tree_.top(); 
    this->tree_.pop();

    Expr_Node * leftChild = this->tree_.top(); 
    this->tree_.pop();

    N->setLeftChild(leftChild); 
    N->setRightChild(rightChild);

    this->tree_.push(N); 
}

void Expr_Tree_Builder::finishTreeBuild() 
{
    while(!this->opStack_.is_empty()){
        this->popConnectPush(); 
    }
}

void Expr_Tree_Builder::build_number(int n)
{
    Expr_Node * temp = new Num_Node(n); 
    this->tree_.push(temp);
}

void Expr_Tree_Builder::build_add()
{
    Binary_Op_Node * temp = new Add_Node; 
    handleOperator(temp->getPrecedence());
    this->opStack_.push(temp); 
}

void Expr_Tree_Builder::build_divide()
{
    Binary_Op_Node * temp = new Divide_Node; 
    handleOperator(temp->getPrecedence());
    this->opStack_.push(temp); 
}

void Expr_Tree_Builder::build_modulus()
{
    Binary_Op_Node * temp = new Modulus_Node;
    handleOperator(temp->getPrecedence());
    this->opStack_.push(temp); 
}

void Expr_Tree_Builder::build_multiply()
{
    Binary_Op_Node * temp = new Multiply_Node;
    handleOperator(temp->getPrecedence());
    this->opStack_.push(temp); 
}

void Expr_Tree_Builder::build_subtract()
{
    Binary_Op_Node * temp = new Subtract_Node;
    handleOperator(temp->getPrecedence());
    this->opStack_.push(temp); 
}

Expr_Node * Expr_Tree_Builder::get_expression()
{
    return this->tree_.top(); 
}