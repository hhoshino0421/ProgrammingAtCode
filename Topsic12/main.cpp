#include <iostream>

using namespace std;

int main() {
    int x, y, z, ans;

    cin >> x;

    y = x / 3;
    z = x % 3;
    ans = y + z;

    cout << ans << endl;


    return 0;
}