#include <iostream>

using namespace std;

int main() {

    int a,b,c;

    int temp[4];

    cin >> a >> b >> c;

    temp[0] = a + b + c;
    temp[1] = a * b * c;
    temp[2] = a * b + c;
    temp[3] = a + b * c;

    int max=temp[0];
    for (int i = 0; i < 4; i++) {
        if (max < temp[i]) {
            max = temp[i];
        }
    }

    cout << max << endl;

    return 0;
}