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
private:
    vector<vector<int>> mNodeMax;

public:
    void handleHelper(vector<vector<int>>& data, int r, int c, int rNext, int cNext) {
        handleOneNode(data, rNext, cNext);
        if (mNodeMax[r][c] < mNodeMax[rNext][cNext] + 1) {
            mNodeMax[r][c] = mNodeMax[rNext][cNext] + 1;
        }
    }
    void handleOneNode(vector<vector<int>>& data, int r, int c) {
        if (mNodeMax[r][c] > 0) {
            return;
        }

        mNodeMax[r][c] = 1; // init self path as 1

        // try sibling nodes
        int rNext = 0;
        int cNext = 0;
        rNext = r - 1; cNext = c; // up
        if ((rNext >= 0) and (data[r][c] > data[rNext][cNext])) {
            handleHelper(data, r, c, rNext, cNext);
        }

        rNext = r + 1; cNext = c; // down
        if ((rNext < data.size()) and (data[r][c] > data[rNext][cNext])) {
            handleHelper(data, r, c, rNext, cNext);
        }

        rNext = r; cNext = c + 1; // right
        if ((cNext < data[0].size()) and (data[r][c] > data[rNext][cNext])) {
            handleHelper(data, r, c, rNext, cNext);
        }

        rNext = r; cNext = c - 1; // left
        if ((cNext >= 0) and (data[r][c] > data[rNext][cNext])) {
            handleHelper(data, r, c, rNext, cNext);
        }
    }

    void run(vector<vector<int>>& data) {
//        cout << "snow_01" << endl;
        Tools::print(data);

        // init data
        vector<int> row;
        row.resize(data[0].size(), 0);
        for (int r = 0; r < data.size(); r++) {
            mNodeMax.push_back(row);
        }

        for (int r = 0; r < data.size(); r++) {
            vector<int> row = data.at(r);
            for (int c = 0; c < row.size();c++) {
                handleOneNode(data, r, c);
            }
        }

        // find the max path
        int maxPath = 0;
        for (int r = 0; r < data.size(); r++) {
            for (int c = 0; c < data[r].size();c++) {
                if(mNodeMax[r][c] > maxPath) {
                    maxPath = mNodeMax[r][c];
                }
            }
        }
        cout << maxPath << endl;
    }
    static void test() {
        vector<vector<int>> input;
        Tools::readIntArray(input);

        snow_01().run(input);
    }
};

void runSnow() {
    snow_01().test();
}