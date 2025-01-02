//
//  ExpressionManager.cpp
//  Lab 3
//
//  Created by Seong-Eun Cho on 5/20/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <stdio.h>
#include "ExpressionManager.h"
#include <sstream>


using namespace std;

bool ExpressionManager::isBalanced(string expression){
    stack<string> leftParen;
    stringstream ss(expression);
    string s;
    while (ss >> s){
        if (isLeftParen(s)){
            leftParen.push(s);
        }
        else if (isRightParen(s)){
            if (leftParen.empty()){
                return false;
            }
            else{
                if (!isPair(leftParen.top(), s)){
                    return false;
                }
                else leftParen.pop();
            }
        }
    }
    if (!leftParen.empty()){
        return false;
    }
    return true;
}

string ExpressionManager::postfixToInfix(string expression){
    stack<string> num;
    stringstream ss(expression);
    string s;
    while (ss >> s){
        if (!isNumber(s) && !isOperator(s)) return "invalid";
        if (isNumber(s)) num.push(s);
        if (isOperator(s)){
            if (num.size() < 2) return "invalid";
            else {
                string right;
                string left;
                right = num.top();
                num.pop();
                left = num.top();
                num.pop();
                string result = "( " + left + " " + s + " " + right + " )";
                num.push(result);
            }
        }
    }
    if (num.size() != 1){
        return "invalid";
    }
    
    return num.top();
}

string ExpressionManager::infixToPostfix(string expression){
    if (!isBalanced(expression)) return "invalid";
    if (!numBalanced(expression)) return "invalid";
    stack<string> op; op.push("hold");
    stack<string> all; all.push("hold");
    stringstream ss(expression);
    string s;
    string output;
    while (ss >> s){
        if (!isLeftParen(s) && !isRightParen(s) && !isNumber(s) && !isOperator(s)) return "invalid";
        if (output == ""){
            if (!(isNumber(s) || isLeftParen(s))) return "invalid";
        }
        if (isNumber(s)){
            if (isNumber(all.top()) || isRightParen(all.top())) return "invalid";
            else {
                all.push(s);
                if (output == "") output = s;
                else output += " " + s;
            }
        }
        if (isLeftParen(s)){
            if (isNumber(all.top()) || isRightParen(all.top())) return "invalid";
            else{
                all.push(s);
                op.push(s);
            }
        }
        if (isOperator(s)){
            if (isOperator(all.top()) || isLeftParen(all.top())) return "invalid";
            else{
                if (precedence(op.top()) < precedence(s)) {
                    all.push(s);
                    op.push(s);
                }
                else{
                    while (precedence(op.top()) >= precedence(s)){
                        output += " " + op.top();
                        op.pop();
                    }
                    all.push(s);
                    op.push(s);
                }
            }
        }
        if (isRightParen(s)){
            if (isLeftParen(all.top()) || isOperator(all.top())) return "invalid";
            else{
                while (!isLeftParen(op.top())){
                    output += " " + op.top();
                    op.pop();
                }
                all.push(s);
                op.pop();
            }
        }
    }
    while (op.size() > 1) {
        output += " " + op.top();
        op.pop();
    }
    if (op.size() != 1) return "invalid";
    
    return output;
}

string ExpressionManager::postfixEvaluate(string expression){
    stack<int> num;
    stringstream ss(expression);
    string s;
    while (ss >> s){
        if (!isNumber(s) && !isOperator(s)) return "invalid";
        if (isNumber(s)) {
            int i = atoi(s.c_str());
            num.push(i);
        }
        if (isOperator(s)){
            if (num.size() < 2) return "invalid";
            else {
                int right;
                int left;
                right = num.top();
                num.pop();
                left = num.top();
                num.pop();
                int result;
                if (s == "+") result = left + right;
                if (s == "-") result = left - right;
                if (s == "*") result = left * right;
                if (s == "/") result = left / right;
                if (s == "%") result = left % right;
                num.push(result);
            }
        }
    }
    if (num.size() != 1){
        return "invalid";
    }
    
    return to_string(num.top());
}

bool ExpressionManager::isLeftParen(string t){
    if (t == "(" || t == "[" || t == "{"){
        return true;
    }
    else return false;
}

bool ExpressionManager::isRightParen(string t){
    if (t == ")" || t == "]" || t == "}"){
        return true;
    }
    else return false;
}

bool ExpressionManager::isPair(string left, string right){
    bool pair = false;
    if (left == "(" && right == ")"){
        pair = true;
    }
    else if (left == "[" && right == "]"){
        pair = true;
    }
    else if (left == "{" && right == "}"){
        pair = true;
    }
    return pair;
}

bool ExpressionManager::isOperator(string t){
    if (t == "*" || t == "/" || t == "%" || t == "+" || t == "-"){
        return true;
    }
    else return false;
}

bool ExpressionManager::isNumber(string t){
    int i = 0; while (isdigit(t[i])){i++;}
    string number = t.substr(0, i);
    if (number == t) return true;
    else return false;
}

int ExpressionManager::precedence(string t){
    int precedence = 0;
    if (isLeftParen(t)) precedence = 0;
    if (isRightParen(t)) precedence = 3;
    if (isOperator(t)){
        if (t == "*" || t == "/" || t == "%") precedence = 2;
        if (t == "+" || t == "-") precedence = 1;
    }
    return precedence;
}

bool ExpressionManager::numBalanced(string expression){
    stack<string> num;
    stack<string> op;
    stringstream ss(expression);
    string s;
    while (ss >> s){
        if (isNumber(s)) num.push(s);
        if (isOperator(s)) op.push(s);
    }
    if (num.size() == op.size() + 1){
        return true;
    }
    return false;
}