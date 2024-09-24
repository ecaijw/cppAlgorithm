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

int main(int argc, char** argv) {

    // shudu();

    // return 0;


    runCalc24();

    runSnow();

    CreateFullPermutation::test();

    float f = test();
    testVector();

    testStack();

	cout << matchBracket("((((( abc ))))())") << endl;
	string str;
	cin >> str;
	cout << matchBracket(str) << endl;

//    snowJunyi();
    return 0;
}

