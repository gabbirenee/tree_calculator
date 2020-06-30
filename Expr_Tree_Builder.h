// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _EXPRTREEBUILDER_H_
#define _EXPRTREEBUILDER_H_

/**
 * @class Expr_Tree_Builder
 *
 *  abstract builder class
 */

#include "Expr_Builder.h"
#include "Stack.h"
#include <sstream>
#include <exception>

class Expr_Tree_Builder : public Expr_Builder
{
    public:
        Expr_Tree_Builder(void);
        ~Expr_Tree_Builder();

        void handleOperator(int precedence); 
        void popConnectPush(); 
        void finishTreeBuild();

        void build_number(int n);
        void build_add(void);
        void build_divide(void);
        void build_modulus(void);
        void build_multiply(void);
        void build_subtract(void); 

        Expr_Node * get_expression(void); 

    private:
        Stack<Expr_Node *> tree_; 
        // std::stack<Expr_Node *> tree_;
        Stack<Binary_Op_Node *> opStack_; 
};

#endif   // !defined _EXPRTREEBUILDER_H_