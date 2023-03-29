//Mateusz Rozdzinski

#include <string>
#include <cstdarg>

using namespace std;

void VaArgsToArrayMult(va_list ap, string numbers[], int quantity, int i) {
    if (i != quantity) {
        numbers[i] = va_arg(ap, char*);

        VaArgsToArrayMult(ap, numbers, quantity, ++i);
    }
}

string AddZero(string number, int i) {
    if (i == 0) {
        return number;
    }
    else {
        number = number + '0';

        return AddZero(number, --i);
    }
}

string EraseZeroMult(string number) {
    if (number[0] != '0' || number.length() == 1) {
        return number;
    }
    else {
        number = number.erase(0, 1);

        return EraseZeroMult(number);
    }
}

string AddMult(string number, string result, int carry, int i, int j) {
    if (i == -1) {
        if (carry != 0) {
            if (j >= 0) {
                if (carry + (result[j] - 48) > 9) {
                    int temp = carry + (result[j] - 48);
                    int carryOut = temp / 10;

                    result[j] = (temp % 10) + 48;

                    return AddMult(number, result, carryOut, i, --j);
                }
                else {
                    result[j] += carry;

                    carry = 0;
                }
            }
            else {
                result = (char)(carry + 48) + result;
                carry = 0;
            }
        }

        return result;
    }
    else {
        if (i >= 0 && j >= 0) {
            int temp = (number[i] - 48) + (result[j] - 48) + carry;

            result[j] = (temp % 10) + 48;

            carry = temp / 10;

            return AddMult(number, result, carry, --i, --j);
        }

        if (i >= 0) {
            int temp = (number[i] - 48) + carry;

            result = (char)((temp % 10) + 48) + result;

            carry = temp / 10;

            return AddMult(number, result, carry, --i, j);
        }
    }
}

string Multiplication(string numberOne, string numberTwo, string result, string productTemp, int carry, int i, int j) {
    if (i == -1) {
        if (j == -1) {
            return result;
        }

        if (carry > 0) {
            productTemp = (char)(carry + 48) + productTemp;
            carry = 0;
        }

        productTemp = AddZero(productTemp, numberTwo.length() - 1 - j);

        result = AddMult(result, productTemp, carry, result.length() - 1, productTemp.length() - 1);

        productTemp = "";

        return Multiplication(numberOne, numberTwo, result, productTemp, carry, numberOne.length() - 1, --j);
    }
    else {
        int temp = (numberOne[i] - 48) * (numberTwo[j] - 48) + carry;

        productTemp = (char)((temp % 10) + 48) + productTemp;

        carry = temp / 10;

        return Multiplication(numberOne, numberTwo, result, productTemp, carry, --i, j);
    }
}

string NextNumberMult(int quantity, const string* numbers, string result, int i) {
    if (i == quantity) {
        return result;
    }
    else {
        int carry = 0;
        string productResult = "0";
        string productSum = "";
        string number = numbers[i];

        if (number[0] == '+') {
            number.erase(0, 1);
        }

        if (result[0] != '-' && number[0] != '-') {
            result = Multiplication(result, number, productResult, productSum, carry, result.length() - 1, number.length() - 1);
        }
        else if (result[0] == '-' && number[0] == '-') {
            result.erase(0, 1);
            number.erase(0, 1);
            result = Multiplication(result, number, productResult, productSum, carry, result.length() - 1, number.length() - 1);
        }
        else if (result[0] != '-' && number[0] == '-') {
            string tempNumber = number.erase(0, 1);
            result = Multiplication(result, tempNumber, productResult, productSum, carry, result.length() - 1, tempNumber.length() - 1);

            result = '-' + result;
        }
        else if (result[0] == '-' && number[0] != '-') {
            string tempProduct = result.erase(0, 1);
            result = Multiplication(tempProduct, number, productResult, productSum, carry, tempProduct.length() - 1, number.length() - 1);

            result = '-' + result;
        }

        if (result[0] == '-') {
            result.erase(0, 1);
            result = EraseZeroMult(result);

            if (result != "0") {
                result = '-' + result;
            }
        }
        else {
            result = EraseZeroMult(result);
        }

        if (result[0] == '-') {
            result.erase(0, 1);
            result = EraseZeroMult(result);

            if (result != "0") {
                result = '-' + result;
            }
        }
        else {
            result = EraseZeroMult(result);
        }

        return NextNumberMult(quantity, numbers, result, ++i);
    }
}

string Mult(int quantity, const string* numbers) {
    string result = "1";

    return NextNumberMult(quantity, numbers, result, 0);
}

string Mult(int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArrayMult(ap, numbers, quantity, 0);

    va_end(ap);

    string result = "1";

    return NextNumberMult(quantity, numbers, result, 0);
}

void Mult(string* result, int quantity, const string* numbers) {
    *result = "1";

    *result = NextNumberMult(quantity, numbers, *result, 0);
}

void Mult(string* result, int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArrayMult(ap, numbers, quantity, 0);

    va_end(ap);

    *result = "1";

    *result = NextNumberMult(quantity, numbers, *result, 0);
}

void Mult(string& result, int quantity, const string* numbers) {
    result = "1";

    result = NextNumberMult(quantity, numbers, result, 0);
}

void Mult(string& result, int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArrayMult(ap, numbers, quantity, 0);

    va_end(ap);

    result = "1";

    result = NextNumberMult(quantity, numbers, result, 0);
}