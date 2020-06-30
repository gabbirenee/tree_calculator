// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

#ifndef _VISITOR_H_
#define _VISITOR_H_

/**
 * @class Visitor 
 *
 *  Expression Node
 */

class Num_Node;
class Add_Node;
class Divide_Node;
class Modulus_Node;
class Multiply_Node;
class Subtract_Node; 

class Visitor
{
    public:
        virtual int visit_num_node(Num_Node & numNode) = 0;
        virtual int visit_add_node(Add_Node & addNode) = 0;
        virtual int visit_divide_node(Divide_Node & divideNode) = 0;
        virtual int visit_modulus_node(Modulus_Node & modulusNode) = 0;
        virtual int visit_multiply_node(Multiply_Node & multiplyNode) = 0;
        virtual int visit_subtract_node(Subtract_Node & subtractNode) = 0;
};

#endif   // !defined _VISITOR_H_