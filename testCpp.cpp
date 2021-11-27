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
#include "common.h"

using namespace std;

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
