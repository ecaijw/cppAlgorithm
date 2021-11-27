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

float CalcExp::calc2Nums(char c, float n1, float n2) {
    if (c == '*') return n1 * n2;
    if (c == '/') return n1 / n2;
    if (c == '+') return n1 + n2;
    if (c == '-') return n1 - n2;
    assert(false);
    return 0;
}

float CalcExp::calcExp(string s) {
    if (s.empty()) {
        return 0;
    }

    stack<float> st;

    for (int i = 0; i < s.length() ; i++) {
        char c = s[i];
        if (Tools::isOperand(c)) {
            st.push((float)(c - '0'));
        } else {
            // calc the result, and then push to the stack
            float num1 = st.top();
            st.pop();
            float num2 = st.top();
            st.pop();
            st.push(CalcExp::calc2Nums(c, num2, num1));
        }
    }
    assert(st.size() == 1);
    return st.top();
}
