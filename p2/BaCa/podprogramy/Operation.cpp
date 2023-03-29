//Mateusz Rozdzinski

#include <string>
#include <cstdarg>

using namespace std;

void VaArgsToArray(va_list ap, string numbers[], int quantity, int i) {
    if (i != quantity) {
        numbers[i] = va_arg(ap, char*);

        VaArgsToArray(ap, numbers, quantity, ++i);
    }
}

string Operation(string (*SumOrMultOperation)(int, const string*), int quantity, const string* numbers) {
    return SumOrMultOperation(quantity, numbers);
}

string Operation(string (*SumOrMultOperation)(int, const string*), int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArray(ap, numbers, quantity, 0);

    va_end(ap);

    return SumOrMultOperation(quantity, numbers);
}

void Operation(string* result, string (*SumOrMultOperation)(int, const string*), int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArray(ap, numbers, quantity, 0);

    va_end(ap);

    *result = SumOrMultOperation(quantity, numbers);
}

void Operation(string* result, string (*SumOrMultOperation)(int, const string*), int quantity, const string* numbers) {
    *result = SumOrMultOperation(quantity, numbers);
}

void Operation(string& result, void (*SumOrMultOperation)(string*, int, const string*), int quantity, const string* numbers) {
    SumOrMultOperation(&result, quantity, numbers);
}

void Operation(string& result, void (*SumOrMultOperation)(string*, int, const string*), int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArray(ap, numbers, quantity, 0);

    va_end(ap);

    SumOrMultOperation(&result, quantity, numbers);
}