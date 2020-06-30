// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth

// Commands:
// mwc.pl -type make
// make
// valgrind --log-file=Valgrind.txt ./tree

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#include "Eval_Visitor.h"
#include "Expr_Node.h"
#include "Expr_Tree_Builder.h"

bool parseExpression(std::string expr, Expr_Tree_Builder * tree);
bool isOperand(std::string e); 

int main(int argc, char * argv []) {

    std::string expr;
    expr = "";
    printf("Enter infix expression (or type 'QUIT' to end the program): ");
    getline(std::cin, expr);
     while(expr != "QUIT") {
        // tree that will contain the binary expression
        Expr_Tree_Builder * tree = new Expr_Tree_Builder(); 
        bool parseSuccessful; 
        // make the tree!
        parseSuccessful = parseExpression(expr, tree);
        if(!parseSuccessful) {  // if something went wrong parsing the expression
            std::cout<<"Invalid Expression"<<std::endl; 
        }
        else {  // expression parsed successfully 
            // traverse tree to get answer
            int answer;
            Eval_Visitor visitor;   // visitor that will do the evaluation of the tree
            Expr_Node * tree_root = tree->get_expression();     // root of the tree

            answer = tree_root->accept(visitor);    // have the tree accept the visitor to get the answer
            std::cout<<"Answer: "<<answer<<std::endl;
        }

        delete tree; // memory clean up

        expr = "";
        printf("Enter infix expression (or type 'QUIT' to end the program): ");
        getline(std::cin, expr);
    }

    return 0;
}

bool parseExpression(std::string expr, Expr_Tree_Builder * tree)
{
    std::stringstream ss(expr);  // for string manipulation
    std::string e(""); 

    try {
        while(ss >> e){     // go through each token in the expression
                if(isOperand(e)) {  // if it is a number
                    tree->build_number(std::stoi(e)); 
                }
                else if(e == "+") {
                    tree->build_add(); 
                }
                else if(e == "-") {
                    tree->build_subtract(); 
                }
                else if(e == "*") {
                    tree->build_multiply();
                }
                else if(e == "/") {
                    tree->build_divide();
                }
                else if(e=="%") {
                    tree->build_modulus(); 
                }
                else {  // invalid character
                    return false; 
                }
        }
    } catch (std::exception ex) {   // somethign went wrong building the tree
        return false; 
    }
    try{
        tree->finishTreeBuild(); // get the rest of the stuff from the operator stack into the tree
    } catch (std::exception ex) {
        return false; 
    }
    // tree build successful
    return true; 
}

bool isOperand(std::string e) {     // tests if a token is a number
    if(e.find("-") == 0 && e.length() > 1) {  // if e contains - and has a length of 1 -> then it is a minus sign not a negative sign 
        e = e.substr(1, e.length());  // set e equal to itself without the negative sign
    }

    for(int i = 0; i < e.length(); i++) {
        if(!isdigit(e[i])) {    // if anything in e is not a digit, it is not an operand
            return false; 
        }
    }

    return true;
}