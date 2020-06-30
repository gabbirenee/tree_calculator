// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _EXPRBUILDER_H_
#define _EXPRBUILDER_H_

/**
 * @class Expr_Builder
 *
 *  abstract builder class
 */

#include "Expr_Node.h"
#include "Num_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Modulus_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"

class Expr_Builder
{
    public:
        Expr_Builder(void){};
        virtual ~Expr_Builder(void) {};

        virtual void build_number(int n) = 0;
        virtual void build_add(void) = 0;
        virtual void build_divide(void) = 0;
        virtual void build_modulus(void) = 0;
        virtual void build_multiply(void) = 0;
        virtual void build_subtract(void) = 0; 
};

#endif   // !defined _EXPRBUILDER_H_