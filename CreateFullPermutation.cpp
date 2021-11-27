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

void CreateFullPermutation::init(const vector<int>& numArray) {
    mNumArray = numArray;
}
void CreateFullPermutation::getFirst(vector<int>& nextNumArray) {
    mLast.resize(mNumArray.size(), 0);
    nextNumArray.assign(mLast.begin(), mLast.end());
}

bool CreateFullPermutation::getNext(vector<int>& nextNumArray) {
    // from the low digit, add 1 each time.
    int i = mLast.size() - 1;
    for (; i >= 0; i--) {
        mLast[i] += 1;
        if (mLast[i] == mNumArray[i]) {
            // ½øÎ»
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

void CreateFullPermutation::testOne(const vector<int>& oneData) {
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
void CreateFullPermutation::test() {
    testOne({1, 1, 1});
    testOne({3, 3, 3});
    testOne({3, 2, 1});
    testOne({2, 4, 3, 2});
}

