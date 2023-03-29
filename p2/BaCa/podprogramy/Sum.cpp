//Mateusz Rozdzinski

#include <string>
#include <cstdarg>

using namespace std;

void VaArgsToArraySum(va_list ap, string numbers[], int quantity, int i) {
    if (i != quantity) {
        numbers[i] = va_arg(ap, char*);

        VaArgsToArraySum(ap, numbers, quantity, ++i);
    }
}

string EraseZeroSum(string number) {
    if (number[0] != '0' || number.length() == 1) {
        return number;
    }
    else {
        number = number.erase(0, 1);

        return EraseZeroSum(number);
    }
}

string CarryIn(string minuend, int i) {
    if (minuend[i] != '0') {
        minuend[i] -= 1;

        return minuend;
    }
    else {
        minuend[i] = '9';
        return CarryIn(minuend, --i);
    }
}

string Subtraction(string minuend, string subtrahend, string sum, int i, int j) {
    if (i == -1) {
        if (j >= 0) {
            sum = subtrahend[j] + sum;

            return Subtraction(minuend, subtrahend, sum, i, --j);
        }
        return sum;
    }
    else {
        if (j >= 0) {
            if ((minuend[i] - subtrahend[j]) < 0) {
                if (i != 0) {
                    minuend = CarryIn(minuend, i - 1);

                    sum = (char)(((minuend[i] + 10) - subtrahend[j]) + 48) + sum;
                }
                else {
                    sum = (char)(subtrahend[j] - minuend[i] + 48) + sum;
                }

                return Subtraction(minuend, subtrahend, sum, --i, --j);
            }
            else {
                if (i == 0 && (minuend[i] - subtrahend[j] + 48) != '0') {
                    sum = (char)(minuend[i] - subtrahend[j] + 48) + sum;
                }
                else if (i != 0) {
                    sum = (char)(minuend[i] - subtrahend[j] + 48) + sum;
                }

                return Subtraction(minuend, subtrahend, sum, --i, --j);
            }
        }
        else {
            if (i == 0 && minuend[i] != '0') {
                sum = minuend[i] + sum;
            }
            else if (i != 0) {
                sum = minuend[i] + sum;
            }

            return Subtraction(minuend, subtrahend, sum, --i, j);
        }
    }
}

string FullAdder(string number, string result, int carry, int i, int j) {
    if (i == -1) {
        if (carry != 0) {
            if (j >= 0) {
                if (carry + (result[j] - 48) > 9) {
                    int temp = carry + (result[j] - 48);
                    int carryOut = temp / 10;

                    result[j] = (temp % 10) + 48;

                    return FullAdder(number, result, carryOut, i, --j);
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

            return FullAdder(number, result, carry, --i, --j);
        }

        if (i >= 0) {
            int temp = (number[i] - 48) + carry;

            result = (char)((temp % 10) + 48) + result;

            carry = temp / 10;

            return FullAdder(number, result, carry, --i, j);
        }
    }
}

string NextNumberSum(int quantity, const string* numbers, string result, int i) {
    if (i == quantity) {
        return result;
    }
    else {
        int carry = 0;
        string number = numbers[i];

        if (number[0] == '+') {
            number.erase(0, 1);
        }

        if (number[0] == '-') {
            number.erase(0, 1);
            number = EraseZeroSum(number);

            if (number != "0") {
                number = '-' + number;
            }
        }
        else {
            number = EraseZeroSum(number);
        }

        if (result[0] != '-' && number[0] != '-') {
            result = FullAdder(number, result, carry, number.length() - 1, result.length() - 1);
        }
        else if (result[0] == '-' && number[0] == '-') {
            string tempSum = result.erase(0, 1);
            string tempNumber = number.erase(0, 1);
            result = '-' + FullAdder(tempNumber, tempSum, carry, tempNumber.length() - 1, tempSum.length() - 1);
        }
        else if (result[0] != '-' && number[0] == '-') {
            string tempNumber = number.erase(0, 1);
            string subtraction = "";

            if (result.length() > tempNumber.length()) {
                result = Subtraction(result, tempNumber, subtraction, result.length() - 1, tempNumber.length() - 1);
            }
            else if (tempNumber.length() > result.length()) {
                result = '-' + Subtraction(tempNumber, result, subtraction, tempNumber.length() - 1, result.length() - 1);
            }
            else {
                if (result > tempNumber) {
                    result = Subtraction(result, tempNumber, subtraction, result.length() - 1, tempNumber.length() - 1);
                }
                else if (tempNumber > result) {
                    result = '-' + Subtraction(tempNumber, result, subtraction, tempNumber.length() - 1, result.length() - 1);
                }
                else {
                    result = "0";
                }
            }
        }
        else if (result[0] == '-' && number[0] != '-') {
            string tempSum = result.erase(0, 1);
            string subtraction = "";

            if (number.length() > tempSum.length()) {
                result = Subtraction(number, tempSum, subtraction, number.length() - 1, tempSum.length() - 1);
            }
            else if (tempSum.length() > number.length()) {
                result = '-' + Subtraction(tempSum, number, subtraction, tempSum.length() - 1, number.length() - 1);
            }
            else {
                if (number > tempSum) {
                    result = Subtraction(number, tempSum, subtraction, number.length() - 1, tempSum.length() - 1);
                }
                else if (tempSum > number) {
                    result = '-' + Subtraction(tempSum, number, subtraction, tempSum.length() - 1, number.length() - 1);
                }
                else {
                    result = "0";
                }
            }
        }

        if (result[0] == '+') {
            result.erase(0, 1);
        }

        if (result[0] == '-') {
            result.erase(0, 1);
            result = EraseZeroSum(result);

            if (result != "0") {
                result = '-' + result;
            }
        }
        else {
            result = EraseZeroSum(result);
        }

        return NextNumberSum(quantity, numbers, result, ++i);
    }
}

string Sum(int quantity, const string* numbers) {
    string result = "0";

    return NextNumberSum(quantity, numbers, result, 0);
}

string Sum(int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArraySum(ap, numbers, quantity, 0);

    va_end(ap);

    string result = "0";

    return NextNumberSum(quantity, numbers, result, 0);
}

void Sum(string* result, int quantity, const string* numbers) {
    *result = "0";

    *result = NextNumberSum(quantity, numbers, *result, 0);
}

void Sum(string* result, int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArraySum(ap, numbers, quantity, 0);

    va_end(ap);

    *result = "0";

    *result = NextNumberSum(quantity, numbers, *result, 0);
}

void Sum(string& result, int quantity, const string* numbers) {
    result = "0";

    result = NextNumberSum(quantity, numbers, result, 0);
}

void Sum(string& result, int quantity, ...) {
    va_list ap;
    va_start(ap, quantity);

    string numbers[quantity];

    VaArgsToArraySum(ap, numbers, quantity, 0);

    va_end(ap);

    result = "0";

    result = NextNumberSum(quantity, numbers, result, 0);
}