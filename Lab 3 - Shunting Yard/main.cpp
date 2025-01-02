//
//  main.cpp
//  Lab 3
//
//  Created by Seong-Eun Cho on 5/20/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include "ExpressionManagerInterface.h"
#include "ExpressionManager.h"

using namespace std;

int main() {
    string expression;
    cin >> expression;
    ExpressionManager d;
    if (d.isBalanced(expression)){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
}
