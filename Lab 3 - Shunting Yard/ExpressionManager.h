//
//  ExpressionManager.h
//  Lab 3
//
//  Created by Seong-Eun Cho on 5/20/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef ExpressionManager_h
#define ExpressionManager_h
#include "ExpressionManagerInterface.h"
#include <stack>

using namespace std;

class ExpressionManager : public ExpressionManagerInterface {
public:
    ExpressionManager(){};
    bool isBalanced(string expression);
    string postfixToInfix(string expression);
    string infixToPostfix(string expression);
    string postfixEvaluate(string expression);
    
    bool isLeftParen(string t);
    bool isRightParen(string t);
    bool isPair(string left, string right);
    bool isOperator(string t);
    bool isNumber(string t);
    int precedence(string t);
    bool numBalanced(string expression);
    
    
};

#endif /* ExpressionManager_h */
