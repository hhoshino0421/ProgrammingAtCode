#include <iostream>
#include <vector>

using namespace std;

struct rectpoint {
    int top;
    int bottom;
    int left;
    int right;
};

int main() {

    int x, y;
    string linein;
    vector<string> invec;

    cin >> y >> x;


    for (int i = 0; i < y; i++) {
        cin >> linein;
        invec.push_back(linein);
    }


    int **xy_sum;
    xy_sum = (int **) malloc(sizeof(int *) * y);

    for (int i = 0; i < y; i++) {
        xy_sum[i] = (int *) malloc(sizeof(int) * x);
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            xy_sum[i][j] = 0;
        }
    }


    for (int i = 0; i < invec.size(); i++) {

        char *tempc = (char *) invec[i].c_str();

        //デバッグ用-----------
        //printf("%s\n",tempc);
        //--------------------

        for (int j = 0; j < x; j++) {
            if (tempc[j] == '*') {
                xy_sum[i][j] = 1;
            }
        }

    }

    //デバッグ用--------------------------------
//
//    for (int i = 0; i < y; i++) {
//        for (int j = 0; j < x; j++) {
//            cout <<  xy_sum[i][j]  << " ";
//        }
//
//        cout << endl;
//    }

    //----------------------------------------

    int top, bottom, left, right;

    top = -1;
    bottom = right = 0;
    left = x;

    //判定処理
    //矩形候補座標検出
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {

            if (xy_sum[i][j] == 1) {

                bottom = i;

                if (top < 0) {
                    top = i;
                }

                if (x <= left) {
                    left = j;
                }

                if (j > right) {
                    right = j;
                }

            }

        }


    }

    //デバッグ用
    //cout << "top:" <<top << " bottom:" << bottom << " left:" << left << " right:" << right << endl;

    //矩形候補が長方形を形成するかどうかを判定する処理
    int flg = 1;

    if (top < 0) {
        //*がない
        flg = 0;

    } else {
        //*を検知した場合

        for (int i = top; i < bottom + 1; i++) {

            if (flg == 0) {
                break;
            }

            for (int j = left; j < right + 1; j++) {

                if (xy_sum[i][j] == 0) {
                    //長方形が成立しない箇所を検出
                    flg = 0;
                    break;
                }

            }
        }

    }


    //結果出力処理
    if (flg == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }


    //後始末
    free(xy_sum);

    return 0;
}