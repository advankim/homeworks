#include <string>

using namespace std;

string FormatujNapis(string text, string a, string b, string c) {
    string temp = "";
    string tempTwo = "";
    string command = "";

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < text.size()) {
        if (text[i] == '{') {
            j = i;
            command = "";

            while (text[j] != '}') {
                command = command + text[j];

                j++;
            }

            command = command + text[j];

            if (command[1] == 'p') {
                for (k = 0; k < command[3] - 48; k++) {
                    temp = temp + command[5];
                }

                i = i + 6;
            }
            else if (command[1] == 'u') {
                i = i + 4 + command[3] - 48;
            }
            else if (command[1] == 'U') {
                temp.resize(temp.size() - (command[3] - 48));

                i = i + 4;
            }
            else if (command[1] == 'w') {
                if (command[3] - 48 == 1) {
                    temp = temp + a;
                }
                else if (command[3] - 48 == 2) {
                    temp = temp + b;
                }
                else if (command[3] - 48 == 3) {
                    temp = temp + c;
                }

                i = i + 4;
            }
            else if (command[1] == 'W') {
                if (command[3] - 48 == 1) {
                    if (a.size() < command[5] - 48) {
                        for (k = 0; k < a.size(); k++) {
                            temp = temp + a[k];
                        }
                        for (k = 0; k < command[5] - 48 - a.size(); k++) {
                            temp = temp + " ";
                        }
                    }
                    else {
                        for (k = 0; k < command[5] - 48; k++) {
                            temp = temp + a[k];
                        }
                    }
                }
                else if (command[3] - 48 == 2) {
                    if (b.size() < command[5] - 48) {
                        for (k = 0; k < b.size(); k++) {
                            temp = temp + b[k];
                        }
                        for (k = 0; k < command[5] - 48 - b.size(); k++) {
                            temp = temp + " ";
                        }
                    }
                    else {
                        for (k = 0; k < command[5] - 48; k++) {
                            temp = temp + b[k];
                        }
                    }
                }
                else if (command[3] - 48 == 3) {
                    if (c.size() < command[5] - 48) {
                        for (k = 0; k < c.size(); k++) {
                            temp = temp + c[k];
                        }
                        for (k = 0; k < command[5] - 48 - c.size(); k++) {
                            temp = temp + " ";
                        }
                    }
                    else {
                        for (k = 0; k < command[5] - 48; k++) {
                            temp = temp + c[k];
                        }
                    }
                }

                i = i + 6;
            }
        }
        else {
            temp = temp + text[i];
        }

        i++;
    }

    return temp;
}

string UsunSlowo(string text, int number) {
    string temp = "";
    
    int position = 1;
	int add = 0;
    int i = 0;

    while (i < text.size()) {
        add = 0;

        while (text[i] != 32 && text[i] != '\0') {
            if (position != number) temp = temp + text[i];

            add = 1;
            i++;
        }

        if (text[i] != '\0') temp = temp + text[i];

        position = position + add;
        i++;
    }

    return temp;
}

string NajwiekszeSlowo(string text) {
    string temp = "";
    string tempTwo = "";
    
    int i = 0;

    while (i < text.size()) {
        tempTwo = "";

        while (text[i] != 32 && text[i] != '\0') {
            tempTwo = tempTwo + text[i];
            i++;
        }

        if (tempTwo > temp) temp = tempTwo;

        i++;
    }

    return temp;
}

string NormalizujNapis(string text) {
    string temp = "";

    int i = 0;

    bool sep = false;

    while (i < text.size()) {
        if (text[i] != 32 && text[i] != '\0') {
            if (text[i] == 44) {
                if (text[i + 1] == '\0') temp = temp + ",";
                else temp = temp + ", ";
            }
            else if (text[i] == 46) {
                if (text[i + 1] == '\0') temp = temp + ".";
                else temp = temp + ". ";
            }
            else if (text[i] >= 65 && text[i] <= 90 || text[i] >= 97 && text[i] <= 122) {
                if (text[i] != '\0' && sep == true) temp = temp + " ";
                temp = temp + text[i];
            }

            sep = false;
        }
        else if (sep == false) {
            if (temp != "") sep = true;
        }

        i++;
    }

    return temp;
}
