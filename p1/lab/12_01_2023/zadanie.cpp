#include <iostream>

using namespace std;

double ToFloat(char* number)
{
	int i = 0;

	float n = 0;
	float result = 0;
	float m = 0.1;

	if (number[0] == '-') {
		i = 1;
	}

	while (number[i] != '\0') {
		n = (number[i] - '0');
		result = result * 10 + n;

		i++;

		if (number[i] == '.') {
			i++;

			break;
		}
	}

	while (number[i] != '\0') {
		n = (number[i] - '0') * m;
		result = result + n;

		m /= 10;

		i++;
	}

	if (number[0] == '-') {
		result *= -1;
	}

	return result;
}

int main(int argc, char* argv[]) {
	if (argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4] == NULL) {
		float result = 0;
		
		if (argv[1][0] == '-') {
			if (argv[1][1] == 0 || argv[1][1] != 0 && argv[1][1] < 48 || argv[1][1] > 57) {
				cout << "error";

				return argc;
			}	
		}
		else {
			if (argv[1][0] < 48 || argv[1][0] > 57) {
				cout << "error";

				return argc;
			}
		}
		
		if (argv[3][0] == '-') {
			if (argv[3][1] == 0 || argv[3][1] != 0 && argv[3][1] < 48 || argv[3][1] > 57) {
				cout << "error";

				return argc;
			}	
		}
		else {
			if (argv[3][0] < 48 || argv[3][0] > 57) {
				cout << "error";

				return argc;
			}
		}
		
		float operandOne = ToFloat(argv[1]);
		float operandTwo = ToFloat(argv[3]);

		if (*argv[2] == '+') {
			result = operandOne + operandTwo;
		}
		else if (*argv[2] == '-') {
			result = operandOne - operandTwo;
		}
		else if (*argv[2] == '*') {
			result = operandOne * operandTwo;
		}
		else if (*argv[2] == '/') {
			if (operandTwo == 0) {
				cout << "error";

				return argc;
			}

			result = operandOne / operandTwo;
		}
		else {
			cout << "error";

			return argc;
		}
		
		cout << result;

		return argc;
	}

	cout << "error";

	return argc;
}
