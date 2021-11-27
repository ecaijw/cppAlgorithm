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

    bool calc24_1(const vector<int>& cards) {
        vector< vector<int> > pos;
        int cardPos [] = {0, 1, 2, 3};
        do {
            vector<int> onePos;
            onePos.assign(cardPos, cardPos + 4);
            pos.push_back(onePos);
        } while (next_permutation(cardPos, cardPos + cards.size()));

        // exp: (3*(4)*(5)*6)
        //      0/12/345/67/8
        //      2442324222412
        //      Êý×Ö4*3*2  *  ÔËËã·û4*4*4  *  À¨ºÅ2*2*2*2*2*2
        const vector<char> OPERATOR({'+', '-', '*', '/'});
        CreateFullPermutation creator;
        creator.init({2, 4, 2, 2, 4, 2, 2, 4, 2});
        vector<int> numArray;
        creator.getFirst(numArray);
        while (creator.getNext(numArray)) {
//            Tools::print(numArray);
            for (int iPos = 0; iPos < pos.size(); iPos++) {
                vector<int>& onePos = pos.at(iPos);
                string exp;
                if (numArray[0] == 1) {
                    exp.push_back('(');
                }
                exp.push_back((char)(cards[onePos[0]] + '0'));
                exp.push_back(OPERATOR[numArray[1]]);
                if (numArray[2] == 1) {
                    exp.push_back('(');
                }
                exp.push_back((char)(cards[onePos[1]] + '0'));
                if (numArray[3] == 1) {
                    exp.push_back(')');
                }
                exp.push_back(OPERATOR[numArray[4]]);
                if (numArray[5] == 1) {
                    exp.push_back('(');
                }
                exp.push_back((char)(cards[onePos[2]] + '0'));
                if (numArray[6] == 1) {
                    exp.push_back(')');
                }
                exp.push_back(OPERATOR[numArray[7]]);
                exp.push_back((char)(cards[onePos[3]] + '0'));
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
            }

        }
        return false;
    }

    bool calc24(const vector<int>& cards) {
        vector< vector<int> > pos;
        int cardPos [] = {0, 1, 2, 3};
        do {
            vector<int> onePos;
            onePos.assign(cardPos, cardPos + 4);
            pos.push_back(onePos);
        } while (next_permutation(cardPos, cardPos + cards.size()));

        // exp: (3*(4)*(5)*6)
        //      0/12/345/67/8
        //      2442324222412
        //      Êý×Ö4*3*2  *  ÔËËã·û4*4*4  *  À¨ºÅ2*2*2*2*2*2
        const vector<char> OPERATOR({'+', '-', '*', '/'});
        for (int i0 = 0; i0 < 2;i0++)
            for (int i1 = 0; i1 < 4;i1++)
                for (int i2 = 0; i2 < 2;i2++)
                    for (int i3 = 0; i3 < 2;i3++)
                        for (int i4 = 0; i4 < 4;i4++)
                            for (int i5 = 0; i5 < 2;i5++)
                                for (int i6 = 0; i6 < 2;i6++)
                                    for (int i7 = 0; i7 < 4;i7++)
                                        for (int i8 = 0; i8 < 2;i8++) {

//            Tools::print(numArray);
                                            for (int iPos = 0; iPos < pos.size(); iPos++) {
                                                vector<int>& onePos = pos.at(iPos);
                                                string exp;
                                                if (i0 == 1) {
                                                    exp.push_back('(');
                                                }
                                                exp.push_back((char)(cards[onePos[0]] + '0'));
                                                exp.push_back(OPERATOR[i1]);
                                                if (i2 == 1) {
                                                    exp.push_back('(');
                                                }
                                                exp.push_back((char)(cards[onePos[1]] + '0'));
                                                if (i3 == 1) {
                                                    exp.push_back(')');
                                                }
                                                exp.push_back(OPERATOR[i4]);
                                                if (i5 == 1) {
                                                    exp.push_back('(');
                                                }
                                                exp.push_back((char)(cards[onePos[2]] + '0'));
                                                if (i6 == 1) {
                                                    exp.push_back(')');
                                                }
                                                exp.push_back(OPERATOR[i7]);
                                                exp.push_back((char)(cards[onePos[3]] + '0'));
                                                if (i8 == 1) {
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
                                            }

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

void runCalc24() {
    Calc24::test();
}