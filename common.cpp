
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

void reopenStdin() {
#ifdef INPUT_FROM_FILE
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
#endif
}

void closeStdin() {
    #ifdef INPUT_FROM_FILE
    fclose(stdin);
    #endif
}

bool Tools::isOperand(char c) {
    return (('0' <= c) && (c <= '9')) || (('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z'));
}

void Tools::forcePrint(int* a, int r, int c) {
            int* b = (int*)a;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
//            cout << a[i][j] << " ";
            cout << b[i* r + j] << " ";
        }
        cout << endl;
    }
}

void Tools::print(int* a, int r, int c) {
#ifndef LOCAL_CODE
    return;
#endif
    Tools::forcePrint((int*)a, r, c);
}

void Tools::print(const vector<vector<int>>& ret) {
#ifndef LOCAL_CODE
    return;
#endif
    for (int i = 0; i < ret.size(); i++) {
        vector<int> row = ret.at(i);
        for (int j = 0; j < row.size(); j++) {
            cout << row.at(j) << " ";
        }
        cout << endl;
    }
}

void Tools::print(const vector<int>& v) {
#ifndef LOCAL_CODE
    return;
#endif
    for (int j = 0; j < v.size(); j++) {
        cout << v.at(j) << " ";
    }
    cout << endl;
}

void Tools::readIntArray(vector<vector<int>>& ret) {
    reopenStdin();

    int r, c;
    scanf("%d",&r);
    scanf("%d",&c);

    Tools::readIntArray(ret, r, c, false /* no need to reopen */);

    closeStdin();

}

void Tools::readIntArray(vector<vector<int>>& ret, int r, int c, bool needReopenStdin) {
    if (needReopenStdin) reopenStdin();

    int arr[r][c];
    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            scanf("%d", &(arr[i][j]));

        }
        vector<int> row;
        row.insert(row.end(), arr[i], arr[i] + c);
        ret.push_back(row);
    }

    if (needReopenStdin) closeStdin();
}

void Tools::readIntArray2(vector<vector<int>>& ret) {
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

