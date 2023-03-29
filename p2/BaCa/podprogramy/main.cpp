#include <iostream>
#include <string>
#include <cstdarg>
#include "functions.h"

using namespace std;

int main() {
//    const string numbers[8] = {"14", "-300000", "32134", "-9999", "100000000", "3231", "-56565", "-100032"};
//    string sum = Sum(8, numbers);
//
//    cout << sum << endl;
//
//    sum = Sum(8, "14", "-300000", "32134", "-9999", "100000000", "3231", "-56565", "-100032");
//
//    cout << sum << endl;

//    const string numbers[2] = {"123", "123"};
//
//    cout << Mult(2, numbers) << endl;

//    string result[0];
//
//    Sum(result, 8, numbers);
//
//    cout << result[0] << endl;
//
//    Sum(result, 8, "14", "-300000", "32134", "-9999", "100000000", "3231", "-56565", "-100032");
//
//    cout << result[0] << endl;
//
//    string result2;
//
//    Sum(result2, 8, numbers);
//
//    cout << result2 << endl;
//
//    Sum(result2, 8, "14", "-300000", "32134", "-9999", "100000000", "3231", "-56565", "-100032");
//
//    cout << result2 << endl;
//
//    Sum(result2, 2, "-00000", "+0000001");
//
//    cout << result2 << endl;

    //cout << ("" == Mult(2, "5", "")) << '\n';

//    int num2 = 0;
//    string term1;
//    string term2;
//    string* result;
//    cin >> num2;
//
//    for (int i = 0; i < num2; i++) {
//        cin >> term1;
//        cin >> term2;
//        Sum(result, 2, term1.c_str(), term2.c_str());
//        cout << *result << '\n';
//    }

//    string result;
//
//    cout << Operation(2, "5", "", "-1") << endl;

//    string arr[2] = {"2", ""};
//
//    cout << (arr[1] == "")  << endl;

//    string* result;
//    string res = "0";
//    result = &res;
//
//    const string arr[3] = {"5", "2", "-23"};
//    const string arr2[3] = {"50", "2", "+0000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"};
//
//    cout << Operation(Sum, 3, arr) << endl;
//
//    cout << Operation(Sum, 3, "5", "2", "-23") << endl;
//
//    Operation(result, Sum, 3, arr2);
//
//    cout << *result << endl;
//
//    Operation(result, Sum, 3, "5", "2", "-23");
//
//    cout << *result << endl;
//
//    Operation(res, Sum, 3, arr2);
//
//    cout << res << endl;
//
//    Operation(res, Sum, 3, "5", "3", "-23");
//
//    cout << res << endl;
//
//    cout << Operation(Mult, 3, arr) << endl;
//
//    cout << Operation(Mult, 3, "5", "2", "-23") << endl;
//
//    Operation(result, Mult, 3, arr);
//
//    cout << *result << endl;
//
//    Operation(result, Mult, 3, "5", "2", "-23");
//
//    cout << *result << endl;
//
//    Operation(res, Mult, 3, arr);
//
//    cout << res << endl;
//
//    Operation(res, Mult, 3, "5", "3", "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
//
//    cout << res << endl;

    string* result;
    string res = "0";
    result = &res;

    const string arr[2] = {"-99990000999", "+0000000000001"};
    Sum(result, 2, arr);

    cout << *result;

    return 0;
}