#ifndef COMMON_H
#define COMMON_H

#define INPUT_FROM_FILE
#define LOCAL_CODE

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

float test();

extern void test2();

extern void testArray();

extern void testVector();

extern void testStack();

extern bool matchBracket(string str);


extern void shudu();
extern void runSnow();
extern void runCalc24();
extern void snowJunyi();

class CreateFullPermutation {
private:
    vector<int> mNumArray = vector<int>();
    vector<int> mLast = vector<int>();
public:
    void init(const vector<int>& numArray);
    void getFirst(vector<int>& nextNumArray);
    bool getNext(vector<int>& nextNumArray);

    static void testOne(const vector<int>& oneData);
    static void test();
};

class CalcExp {
private:
    static float calc2Nums(char c, float n1, float n2);

public:
    static float calcExp(string s);
};

class ChangeInfixToSuffix {
private:
    int getOperatorInt(char c);

public:
    string changeInfixToSuffix(string infix) ;
};


class Tools {
public:
    static bool isOperand(char c);

    static void forcePrint(int* a, int r, int c);
    static void print(int* a, int r, int c);

    static void print(const vector<vector<int> > &ret);

    static void print(const vector<int> &v);

    static void readIntArray(vector<vector<int> > &ret);
    static void readIntArray(vector<vector<int> >& ret, int r, int c, bool needReopenStdin = true);

    static void readIntArray2(vector<vector<int> > &ret);
};

#endif