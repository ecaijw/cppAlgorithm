#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "common.h"

using namespace std;

int ChangeInfixToSuffix::getOperatorInt(char c) {
    if (c == '(') return 4;
    if (c == '*') return 3;
    if (c == '/') return 3;
    if (c == '+') return 2;
    if (c == '-') return 2;
    if (c == ')') return 1;
    //	assert(false);
    return 0;
}

string ChangeInfixToSuffix::changeInfixToSuffix(string infix) {
    stack<char> st;
    string exp;


    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (Tools::isOperand(c)) {
            exp.push_back(c);
            continue;
        }
        // operator: stack should not be empty
        if (st.empty()) {
            st.push(c);
            continue;
        }

        char top = st.top();
        if (c == ')') {
            // pop symbols: until '('
            while (!st.empty()) {
                top = st.top();
                st.pop();
                if (top == '(') {
                    break;
                }
                exp.push_back(top);
            }
        } else if (top == '(') {
            st.push(c);
        } else if (getOperatorInt(c) <= getOperatorInt(top)) {
            // pop symbols: until not <
            while (!st.empty()) {
                top = st.top();
                if (top == '(') {
                    break;
                }
                if (!(getOperatorInt(c) <= getOperatorInt(top))) {
                    break;
                }
                st.pop();
                exp.push_back(top);
            }
            st.push(c);
        } else {
            st.push(c);
        }
//            cout << exp << endl;
    }
    // end: pop all symbols
    while (!st.empty()) {
        char top = st.top();
        st.pop();
        exp.push_back(top);
    }
    return exp;
}
