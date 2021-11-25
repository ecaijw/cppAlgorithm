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

using namespace std;
#define arrLen(arr) ( sizeof(arr) / sizeof(arr[0]) )



float test() {
    int i;
    int j;
    int j2 = 1;

    cout << i << "\n";
    cout << &i << "\n";
    cout << sizeof(i) << "\n";

    cout << j << "\n";
    cout << j2 << "\n";

    /////////////////
//	float f = nanf("1");
//	
//	cout << f << "\n";	
//	cout << &f << "\n";	
//	cout << sizeof(f) << "\n";	
	return 0.0f;
}

void test2() {
    int i = 1;
    int j = 2;

    cout << i << "\n";
    cout << &i << "\n";
    cout << sizeof(i) << "\n";

    cout << endl;

    cout << j << "\n";
    cout << &j << "\n";
    cout << sizeof(j) << "\n";

    cout << endl;

    *(&i) = 111;  // &i 是地址的值，不是i的值
    cout << i << "\n";
    cout << j << "\n";

    cout << endl;
    *((&j) + 1) = 222;
    cout << &j << "\n";
    cout << ((&j) + 1) << "\n";

    cout << i << "\n";
    cout << j << "\n";
}

void testArray() {

    int arr [10] = {0, 1, 2};


    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }

    cout << arr << endl;
    cout << &arr << endl;
    cout << &(arr[0]) << endl;

    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << &(arr[i]) << endl;
    }

    // out of range
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i + 10] << endl;
    }
    // how to get count of an array
    cout << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;



    int arr2 [10] = {3, 4, 5};
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << &(arr2[i]) << endl;
    }

    cout << "arrPointer" << endl;
    int* arrPointer = arr;  // p[i]  是  *(p + i)
    for (int i = 0; i < 10; i++) {
        cout << arrPointer[i] << endl;
    }

    cout << endl;
    arrPointer = arr2;
    for (int i = 0; i < 10; i++) {
        cout << arrPointer[i] << endl;
    }

    cout << endl;
    cout << sizeof(arrPointer) << endl;
    cout << sizeof(arrPointer[0]) << endl;

}

void testVector() {
    vector<int> v;

    cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
    v.push_back(0);
    cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
    v.push_back(1);
    cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
    v.push_back(2);
    cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
    v.push_back(3);
    cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
    v.push_back(4);
    cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

//	cout << v[0] <<" " << v[1] << endl;
    for (int i = 0; i < 20; i++) {
        cout << v[i] << endl;
    }
}

void testStack() {
    stack<int> s;

    cout << "size: " << s.size()  << endl;
    s.push(0);
    cout << "size: " << s.size()  << "  top:" << s.top() << endl;
    s.push(1);
    cout << "size: " << s.size()  << "  top:" << s.top() << endl;

}

bool matchBracket(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        }
        else if (str[i] == ')') {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.size() == 0;
}
class Tools {
public:
    static bool isOperand(char c) {
        return (('0' <= c) && (c <= '9')) || (('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z'));
    }

    static void print(const vector<vector<int>>& ret) {
        for (int i = 0; i < ret.size(); i++) {
            vector<int> row = ret.at(i);
            for (int j = 0; j < row.size(); j++) {
                cout << row.at(j) << " ";
            }
            cout << endl;
        }
    }

    static void print(const vector<int>& v) {
        for (int j = 0; j < v.size(); j++) {
            cout << v.at(j) << " ";
        }
        cout << endl;
    }

    static void readIntArray(vector<vector<int>>& ret) {
        const char* FILE_NAME = ".\\data\\in.txt";
        const char* FILE_NAME2 = "..\\data\\in.txt";

        const char* fileName = FILE_NAME;
        std::ifstream inFile(FILE_NAME);
        if (!inFile.is_open()) {
            inFile = ifstream(FILE_NAME2);
            if (inFile.is_open()) {
                fileName = FILE_NAME2;
            } else {
                assert(false);
                return;
            }
            inFile.close();
        }
        inFile.close();

        freopen(fileName, "r", stdin);
        int r, c;
        cin >> r >> c;
        cin.get(); // skip the <Enter>
        for (int i = 0; i < r; i++) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            string token;

            vector<int> intRow;
            while (getline(iss, token, ' ')) {
                intRow.push_back(atoi(token.c_str()));
            }
            ret.push_back(intRow);
        }
        fclose(stdin);
    }
};

class CalcExp {
private:
    static float calc2Nums(char c, float n1, float n2) {
        if (c == '*') return n1 * n2;
        if (c == '/') return n1 / n2;
        if (c == '+') return n1 + n2;
        if (c == '-') return n1 - n2;
        assert(false);
        return 0;
    }

public:
    static float calcExp(string s) {
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
};

class ChangeInfixToSuffix {
private:
    int getOperatorInt(char c) {
        if (c == '(') return 4;
        if (c == '*') return 3;
        if (c == '/') return 3;
        if (c == '+') return 2;
        if (c == '-') return 2;
        if (c == ')') return 1;
        //	assert(false);
        return 0;
    }

    //bool isBiggerOperand(char l, char r) {
    //	// 4   3 3   2 2  1
    //	// ( > * / > +- > )
    //	if 	(l == r) return false;
    //	if (l == '>') {
    //		return true;
    //	}
    //	if ((l == '*') || (l == '/')) {
    //		return (r == )
    //	}
    //}

public:
    string changeInfixToSuffix(string infix) {
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


};

class CreateFullPermutation {
private:
    vector<int> mNumArray = vector<int>();
    vector<int> mLast = vector<int>();
public:
    void init(const vector<int>& numArray) {
        mNumArray = numArray;
    }
    void getFirst(vector<int>& nextNumArray) {
        mLast.resize(mNumArray.size(), 0);
        nextNumArray.assign(mLast.begin(), mLast.end());
    }

    bool getNext(vector<int>& nextNumArray) {
        // from the low digit, add 1 each time.
        int i = mLast.size() - 1;
        for (; i >= 0; i--) {
            mLast[i] += 1;
            if (mLast[i] == mNumArray[i]) {
                // 进位
                mLast[i] = 0;
            } else {
                // find the next
                nextNumArray.assign(mLast.begin(), mLast.end());
                return true;
            }
        }
        if (i < 0) {
            // return value should not be used
            return false; // no more to return
        }
        assert(false); // should not reach here
        return false;
    }

    static void testOne(const vector<int>& oneData) {
        cout << "testOne" << endl;
        Tools::print(oneData);

        CreateFullPermutation creator;
        creator.init(oneData);
        vector<int> numArray;
        creator.getFirst(numArray);
        Tools::print(numArray);
        while (creator.getNext(numArray)) {
            Tools::print(numArray);
        }
    }
    static void test() {
        testOne({1, 1, 1});
        testOne({3, 3, 3});
        testOne({3, 2, 1});
        testOne({2, 4, 3, 2});
    }
};

//    https://leetcode-cn.com/problems/24-game/
class Calc24 {
public:
    void calcStringExp(string s) {
        ChangeInfixToSuffix changeInfixToSuffix;
        string suffix = changeInfixToSuffix.changeInfixToSuffix(s);
//            cout << "suffix: " << suffix << endl;

        float ret = CalcExp::calcExp(suffix);
        cout << "calc exp: " << ret << endl;
    }

    bool calc24(const vector<int>& cards) {
        // exp: (3*(4)*(5)*6)
        //      0/12/345/67/8
        //      2442324222412
        //      数字4*3*2  *  运算符4*4*4  *  括号2*2*2*2*2*2
        const vector<char> OPERATOR({'+', '-', '*', '/'});
        CreateFullPermutation creator;
        creator.init({2, 4, 2, 2, 4, 2, 2, 4, 2});
        vector<int> numArray;
        creator.getFirst(numArray);
        while (creator.getNext(numArray)) {
//            Tools::print(numArray);
            int cardPos [] = {0, 1, 2, 3};
            do {
                string exp;
                if (numArray[0] == 1) {
                    exp.push_back('(');
                }
                exp.push_back((char)(cards[cardPos[0]] + '0'));
                exp.push_back(OPERATOR[numArray[1]]);
                if (numArray[2] == 1) {
                    exp.push_back('(');
                }
                exp.push_back((char)(cards[cardPos[1]] + '0'));
                if (numArray[3] == 1) {
                    exp.push_back(')');
                }
                exp.push_back(OPERATOR[numArray[4]]);
                if (numArray[5] == 1) {
                    exp.push_back('(');
                }
                exp.push_back((char)(cards[cardPos[2]] + '0'));
                if (numArray[6] == 1) {
                    exp.push_back(')');
                }
                exp.push_back(OPERATOR[numArray[7]]);
                exp.push_back((char)(cards[cardPos[3]] + '0'));
                if (numArray[8] == 1) {
                    exp.push_back(')');
                }

                // handle one expression
                if (!matchBracket(exp)) {
//                    cout << exp << endl;
                    continue;
                }
                ChangeInfixToSuffix changeInfixToSuffix;
                string suffix = changeInfixToSuffix.changeInfixToSuffix(exp);
                float ret = CalcExp::calcExp(suffix);
                if ((23.99 <= ret) and (ret <= 24.01)) {
                    cout << "exp: " << exp << "   suffix: " << suffix << "  ret: " << ret << endl;
                    return true;
                }
            } while (next_permutation(cardPos, cardPos + cards.size()));

        }
        return false;
    }
public:
    static void testOne(const vector<int>& cards) {
        Tools::print(cards);
        Calc24().calc24(cards);
    }

    static void test() {
        Calc24().calcStringExp("3+(4+5+6)");

        testOne({3, 4, 5, 6});
        testOne({3, 3, 3, 3});
        testOne({6, 7, 8, 9});
    }

    static void testStringExp() {
        Calc24 calc24;
        calc24.calcStringExp("3+2-1");             // 4
        calc24.calcStringExp("3-2+1");             // 2
        calc24.calcStringExp("(3+2)-1*0+(5)");     // 10

        calc24.calcStringExp("2+(5)");             // 7
        calc24.calcStringExp("(3+2)+(5))");        // 10
        calc24.calcStringExp("(3+2)-(5))");        // 0
        calc24.calcStringExp("(3+2)-1*0");         // 5
        calc24.calcStringExp("9+(8-7)*6+5/4+(3+2)-1*0+(5)");   // 26
        calc24.calcStringExp("9+(8-7)*6+5/4");     // 116
        calc24.calcStringExp("A+(B-C/D)*E");
        calc24.calcStringExp("1-(2+3)");           // -4
        calc24.calcStringExp("a+b*c");
        calc24.calcStringExp("a*b+c");
    }
};

//    http://ymsy.openjudge.cn/jyh/01/
/*
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
class snow_01 {
public:
    static void run(vector<vector<int>>& data) {
        cout << "snow_01" << endl;
        Tools::print(data);
    }
    static void test() {
        vector<vector<int>> input;
        Tools::readIntArray(input);

        snow_01().run(input);
    }
};

int main(int argc, char** argv) {
//    CreateFullPermutation::test();
//    snow_01::test();

//	float f = test();
//	testVector();

//    testStack();

//	cout << matchBracket("((((( abc ))))())") << endl;
//	string str;
//	cin >> str;
//	cout << matchBracket(str) << endl;

    Calc24::test();

    return 0;
}



//	int* p = reinterpret_cast<int*>(&f);
//	cout << "int* p = reinterpret_cast<int*>(&f)\n";
//	cout << *p << "\n";	
//	
//	cout << setiosflags(ios::hex) << setiosflags(ios::uppercase) ;
//    cout<<setiosflags(ios::left|ios::scientific);    //设置左对齐，以科学技术法显示 
//    cout.precision(3);   //设置保留三位小数
//	cout<<123.45678<<endl;
//	
//	cout << setiosflags(ios::hex) << p << "\n";	
//	cout << setiosflags(ios::hex) << setiosflags(ios::uppercase) ;
//	cout << *p << "\n";	
