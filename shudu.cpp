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

#define rc2Grid(r, c) (r / 3 * 3 + c / 3)

class ShuDu {
    int ret [9][9] = {0}; // store returned result
    int mGrid [9][9] = {0}; // numbers of one grid
    int mRow [9][9] = {0}; // number of one row
    int mCol [9][9] = {0}; // number of one col
public:
    bool dfsNextNumber(const vector<vector<int>>& a, int n, int r, int c) {
        ret[r][c] = n; // try the number
        mRow[r][n - 1] = 1;
        mCol[c][n - 1] = 1;
        mGrid[rc2Grid(r, c)][n - 1] = 1;

        int rNext = r;
        int cNext = c + 1;
        if (cNext >= 9) { // next line
            rNext = r + 1;
            cNext = 0;
        }
        if (rNext >= 9) {
            // last number; can not try next
            return true;
        }
        return dfs(a, rNext, cNext);
    }

    bool dfs(const vector<vector<int>>& a, int r, int c) {
//        if (r == 2 and c == 0) {
//            cout << endl;
//        }

        if (a[r][c] != 0) {
            // must be this number; no need to check return value
            return dfsNextNumber(a, a[r][c], r, c);
        }
        for (int n = 1; n <= 9; n++) {
            if ((mGrid[rc2Grid(r, c)][n - 1] != 0) or
                (mRow[r][n - 1] != 0) or
                (mCol[c][n - 1] != 0)) {
                continue; // try next number
            }

            if (dfsNextNumber(a, n, r, c)) {
                return true; // good number
            }

            // reset the flag; try next number
            ret[r][c] = 0;
            mRow[r][n - 1] = 0;
            mCol[c][n - 1] = 0;
            mGrid[rc2Grid(r, c)][n - 1] = 0;
        }
        // if return here, can not find number;
//        cout << "[" << r << "][" << c << "]: " << rc2Grid(r, c) << endl;
//        Tools::print((int*)ret, 9, 9);
        return false;
    }

    void run(const vector<vector<int>>& a) {
//        for (int r = 0; r < a.size(); r++) {
//            for (int c = 0; c < a[r].size(); c++) {
//                cout << "[" << r << "][" << c << "]: " << rc2Grid(r, c) << endl;
//            }
//        }
        // init flags
        for (int r = 0; r < a.size(); r++) {
//            cout << a.size() << "  " << a[r].size() << endl;
            for (int c = 0; c < a[r].size();c++) {
                int num = a[r][c];
                if (num == 0) continue;
                mRow[r][num - 1] = 1;
                mCol[c][num - 1] = 1;
                mGrid[rc2Grid(r, c)][num - 1] = 1;
            }
        }

        for (int r = 0; r < a.size(); r++) {
            for (int c = 0; c < a[r].size(); c++) {
                dfs(a, r, c);
            }
        }

        Tools::forcePrint((int*)ret, 9, 9);
    }
};

// http://ymsy.openjudge.cn/sshs/05
void shudu() {
//	cout << "shudu" << endl;
    vector<vector<int>> a;
    Tools::readIntArray(a, 9, 9);
//    Tools::print(a);
    ShuDu().run(a);
}
