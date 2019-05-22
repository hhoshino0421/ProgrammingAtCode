#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

    string s, t;

    cin >> s;
    cin >> t;

    std::vector<char> s_data;
    std::vector<char> t_data;

    int s_len = s.length();
    int t_len = t.length();

    const char * c_s_char = s.c_str();
    const char * c_t_char = t.c_str();


    for (int i = 0; i < s_len; i++) {
        s_data.push_back(c_s_char[i]);
    }

    for (int i = 0; i <t_len; i++) {
        t_data.push_back(c_t_char[i]);
    }

    sort(s_data.begin(), s_data.end());
    sort(t_data.begin(), t_data.end());

    for (int i = 0; i < s_len; i++) {

        if (s_data[i] != t_data[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;

}
