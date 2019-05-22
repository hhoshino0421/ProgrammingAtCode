#include <iostream>
#include <string>

using namespace std;

int main() {

    string in_data;
    string mae_data;
    string ato_data;

    cin >> in_data;

    mae_data = in_data.substr(0,2);
    ato_data = in_data.substr(2,2);

    int mae = atoi(mae_data.c_str());
    int ato = atoi(ato_data.c_str());

    bool mae_mm, ato_mm;
    mae_mm  = false;
    ato_mm  = false;

    if (mae >= 1 && mae <= 12) {
        //前がMM可能
        mae_mm = true;
    }

    if (ato >= 1 && ato <= 12) {
        //後がMM可能
        ato_mm = true;
    }

    string message;
    message = "";

    if (mae_mm  && ato_mm ) {
        //なんとも言えない
        message ="AMBIGUOUS";

    } else {

        if (ato_mm) {
            //YYMM
            message = "YYMM";

        } else if (mae_mm) {
            //MMYY
            message = "MMYY";

        } else {
            //other
            message = "NA";
        }

    }


    cout << message << endl;


    return 0;

}