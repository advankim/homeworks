struct Component {
    bool is;
    int unsignedCharacter;
    float floatNumber;
};

struct File {
    int number;
    string text;
    string character;

    Component componentOne;
    Component componentTwo;
    Component componentThree;
    Component componentFour;
};

bool OneOrLess(string path) {
    fstream inFile;

    string test;

    int i = 0;

    inFile.open(path.c_str(), fstream::in);

    while (!inFile.eof()) {
        inFile >> test;

        i++;

        if (i > 1) {
            inFile.close();

            return false;
        }
    }

    inFile.close();

    return true;
}

bool OneStructCount(string path) {
    fstream inFile;

    string test;

    int i = 0;

    inFile.open(path.c_str(), fstream::in);

    while (!inFile.eof()) {
        inFile >> test;

        i++;

        if (i > 3) {
            break;
        }
    }

    inFile.close();

    if (i == 3) {
        return true;
    }
    else {
        return false;
    }
}

bool OneStruct(string path) {
    fstream inFile;

    File data;

    int i = 0;

    inFile.open(path.c_str(), fstream::in);

    while (!inFile.eof()) {
        inFile >> data.number;

        getline(inFile, data.text);
        getline(inFile, data.text);
        getline(inFile, data.character);

        inFile >> data.componentOne.is;
        inFile >> data.componentOne.unsignedCharacter;
        inFile >> data.componentOne.floatNumber;
        inFile >> data.componentTwo.is;
        inFile >> data.componentTwo.unsignedCharacter;
        inFile >> data.componentTwo.floatNumber;
        inFile >> data.componentThree.is;
        inFile >> data.componentThree.unsignedCharacter;
        inFile >> data.componentThree.floatNumber;
        inFile >> data.componentFour.is;
        inFile >> data.componentFour.unsignedCharacter;
        inFile >> data.componentFour.floatNumber;

        i++;

        if (i > 1) return false;
    }

    inFile.close();

    return true;
}

void SortCount(string pathOne, string pathTwo, string pathThree) {
    if (!OneStruct(pathOne)) {
        fstream inFile;
        fstream outFile;
        fstream outFileTwo;
        fstream ctFile;

        File data;
        File dataTwo;

        int counter = -1;
        int counterTwo = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int e = 255;
        int f = 0;
        int p = 0;
        bool flag = 0;

        inFile.open(pathOne.c_str(), fstream::in);
        outFile.open(pathTwo.c_str(), fstream::out | fstream::trunc);

        while (!inFile.eof()) {
            inFile >> data.number;

            getline(inFile, data.text);
            getline(inFile, data.text);
            getline(inFile, data.character);

            inFile >> data.componentOne.is;
            inFile >> data.componentOne.unsignedCharacter;
            inFile >> data.componentOne.floatNumber;
            inFile >> data.componentTwo.is;
            inFile >> data.componentTwo.unsignedCharacter;
            inFile >> data.componentTwo.floatNumber;
            inFile >> data.componentThree.is;
            inFile >> data.componentThree.unsignedCharacter;
            inFile >> data.componentThree.floatNumber;
            inFile >> data.componentFour.is;
            inFile >> data.componentFour.unsignedCharacter;
            inFile >> data.componentFour.floatNumber;

            outFile << data.number << " " << 1 << endl;

            counter++;
        }

        inFile.close();
        outFile.close();

        ctFile.open(pathThree.c_str(), fstream::out | fstream::trunc);
        ctFile.close();

        outFile.open(pathTwo.c_str(), fstream::in);

        for (int i = 0; i < counter; i++) {
            flag = 0;

            outFile >> a;

            ctFile.open(pathThree.c_str(), fstream::in);

            while (!ctFile.eof()) {
                ctFile >> b;

                if (b == a) {
                    flag = 1;

                    break;
                }

                ctFile >> p;
            }

            if (i == 0) {
                flag = 0;
            }

            ctFile.close();

            c = 0;

            if (flag == 0) {
                outFileTwo.open(pathTwo.c_str(), fstream::in);

                for (int j = 0; j < counter; j++) {
                    outFileTwo >> d;

                    if (a == d) {
                        c++;
                    }

                    outFileTwo >> d;
                }

                outFileTwo.close();

                ctFile.open(pathThree.c_str(), fstream::out | fstream::app);

                ctFile << a << " " << c << endl;

                ctFile.close();

                counterTwo++;
            }

            outFile >> a;
        }

        outFile.close();

        outFile.open(pathTwo.c_str(), fstream::out);
        ctFile.open(pathThree.c_str(), fstream::in);

        for (int i = 0; i < counterTwo; i++) {
            ctFile >> a;
            ctFile >> b;

            outFile << a << " " << b << endl;
        }

        outFile.close();
        ctFile.close();

        if (!OneStructCount(pathTwo)) {
            int h = 0;
            int hTwo = 0;

            for (int i = 0; i < counterTwo; i++) {
                outFile.open(pathTwo.c_str(), fstream::in);
                ctFile.open(pathThree.c_str(), fstream::out | fstream::trunc);

                outFile >> c;
                outFile >> a;
                outFile >> d;
                outFile >> b;

                if (a < b || (a == b && c < d)) {
                    h = a;
                    hTwo = c;

                    a = b;
                    c = d;

                    b = h;
                    d = hTwo;
                }

                ctFile << c << " " << a << endl;

                for (int j = 0; j < counterTwo - 1; j++) {
                    outFile >> c;
                    outFile >> a;

                    if (a < b || (a == b && c < d)) {
                        h = a;
                        hTwo = c;

                        a = b;
                        c = d;

                        b = h;
                        d = hTwo;
                    }

                    if (j == counterTwo - 2) {
                        if (a < b || (a == b && c < d)) {
                            ctFile << c << " " << a << endl;
                        }
                        else {
                            ctFile << d << " " << b << endl;
                        }
                    }
                    else {
                        ctFile << c << " " << a << endl;
                    }


                }

                outFile.close();
                ctFile.close();

                outFile.open(pathTwo.c_str(), fstream::out);
                ctFile.open(pathThree.c_str(), fstream::in);

                for (int j = 0; j < counterTwo; j++) {
                    ctFile >> c;
                    ctFile >> a;
                    outFile << c << " " << a << endl;
                }

                ctFile.close();
                outFile.close();
            }
        }

        outFile.open(pathTwo.c_str(), fstream::out | fstream::trunc);
        ctFile.open(pathThree.c_str(), fstream::in);

        for (int i = 0; i < counterTwo; i++) {
            ctFile >> a;
            ctFile >> c;

            e = 256;

            for (int k = 0; k < c; k++) {
                inFile.open(pathOne.c_str(), fstream::in);

                d = -1;
                f = -1;

                for (int j = 0; j < counter; j++) {

                    inFile >> data.number;

                    getline(inFile, data.text);
                    getline(inFile, data.text);
                    getline(inFile, data.character);

                    inFile >> data.componentOne.is;
                    inFile >> data.componentOne.unsignedCharacter;
                    inFile >> data.componentOne.floatNumber;
                    inFile >> data.componentTwo.is;
                    inFile >> data.componentTwo.unsignedCharacter;
                    inFile >> data.componentTwo.floatNumber;
                    inFile >> data.componentThree.is;
                    inFile >> data.componentThree.unsignedCharacter;
                    inFile >> data.componentThree.floatNumber;
                    inFile >> data.componentFour.is;
                    inFile >> data.componentFour.unsignedCharacter;
                    inFile >> data.componentFour.floatNumber;

                    if (a == data.number) {
                        b = ((data.componentOne.unsignedCharacter + data.componentTwo.unsignedCharacter + data.componentThree.unsignedCharacter + data.componentFour.unsignedCharacter) % 256);

                        if (b > d && b < e) {
                            d = b;

                            dataTwo.number = data.number;
                            dataTwo.text = data.text;
                            dataTwo.character = data.character;
                            dataTwo.componentOne.is = data.componentOne.is;
                            dataTwo.componentOne.unsignedCharacter = data.componentOne.unsignedCharacter;
                            dataTwo.componentOne.floatNumber = data.componentOne.floatNumber;
                            dataTwo.componentTwo.is = data.componentTwo.is;
                            dataTwo.componentTwo.unsignedCharacter = data.componentTwo.unsignedCharacter;
                            dataTwo.componentTwo.floatNumber = data.componentTwo.floatNumber;
                            dataTwo.componentThree.is = data.componentThree.is;
                            dataTwo.componentThree.unsignedCharacter = data.componentThree.unsignedCharacter;
                            dataTwo.componentThree.floatNumber = data.componentThree.floatNumber;
                            dataTwo.componentFour.is = data.componentFour.is;
                            dataTwo.componentFour.unsignedCharacter = data.componentFour.unsignedCharacter;
                            dataTwo.componentFour.floatNumber = data.componentFour.floatNumber;
                        }
                    }

                }

                outFile << dataTwo.number << endl;
                outFile << dataTwo.text << endl;
                outFile << dataTwo.character << endl;
                outFile << dataTwo.componentOne.is << " " << dataTwo.componentOne.unsignedCharacter << " " << dataTwo.componentOne.floatNumber << endl;
                outFile << dataTwo.componentTwo.is << " " << dataTwo.componentTwo.unsignedCharacter << " " << dataTwo.componentTwo.floatNumber << endl;
                outFile << dataTwo.componentThree.is << " " << dataTwo.componentThree.unsignedCharacter << " " << dataTwo.componentThree.floatNumber << endl;
                outFile << dataTwo.componentFour.is << " " << dataTwo.componentFour.unsignedCharacter << " " << dataTwo.componentFour.floatNumber << endl;

                e = d;

                inFile.close();

                inFile.open(pathOne.c_str(), fstream::in);

                flag = 1;

                for (int j = 0; j < counter; j++) {

                    inFile >> data.number;

                    getline(inFile, data.text);
                    getline(inFile, data.text);
                    getline(inFile, data.character);

                    inFile >> data.componentOne.is;
                    inFile >> data.componentOne.unsignedCharacter;
                    inFile >> data.componentOne.floatNumber;
                    inFile >> data.componentTwo.is;
                    inFile >> data.componentTwo.unsignedCharacter;
                    inFile >> data.componentTwo.floatNumber;
                    inFile >> data.componentThree.is;
                    inFile >> data.componentThree.unsignedCharacter;
                    inFile >> data.componentThree.floatNumber;
                    inFile >> data.componentFour.is;
                    inFile >> data.componentFour.unsignedCharacter;
                    inFile >> data.componentFour.floatNumber;

                    if (a == data.number) {
                        b = ((data.componentOne.unsignedCharacter + data.componentTwo.unsignedCharacter + data.componentThree.unsignedCharacter + data.componentFour.unsignedCharacter) % 256);

                        if (b == e) {
                            if (flag == 1) {
                                flag = 0;
                            }
                            else {
                                outFile << data.number << endl;
                                outFile << data.text << endl;
                                outFile << data.character << endl;
                                outFile << data.componentOne.is << " " << data.componentOne.unsignedCharacter << " " << data.componentOne.floatNumber << endl;
                                outFile << data.componentTwo.is << " " << data.componentTwo.unsignedCharacter << " " << data.componentTwo.floatNumber << endl;
                                outFile << data.componentThree.is << " " << data.componentThree.unsignedCharacter << " " << data.componentThree.floatNumber << endl;
                                outFile << data.componentFour.is << " " << data.componentFour.unsignedCharacter << " " << data.componentFour.floatNumber << endl;

                                k++;
                            }
                        }
                    }
                }

                inFile.close();
            }
        }

        outFile.close();
        ctFile.close();

        inFile.open(pathOne.c_str(), fstream::out | fstream::trunc);
        outFile.open(pathTwo.c_str(), fstream::in);

        for (int i = 0; i < counter; i++) {
            outFile >> data.number;

            getline(outFile, data.text);
            getline(outFile, data.text);
            getline(outFile, data.character);

            outFile >> data.componentOne.is;
            outFile >> data.componentOne.unsignedCharacter;
            outFile >> data.componentOne.floatNumber;
            outFile >> data.componentTwo.is;
            outFile >> data.componentTwo.unsignedCharacter;
            outFile >> data.componentTwo.floatNumber;
            outFile >> data.componentThree.is;
            outFile >> data.componentThree.unsignedCharacter;
            outFile >> data.componentThree.floatNumber;
            outFile >> data.componentFour.is;
            outFile >> data.componentFour.unsignedCharacter;
            outFile >> data.componentFour.floatNumber;

            inFile << data.number << endl;
            inFile << data.text << endl;
            inFile << data.character << endl;
            inFile << data.componentOne.is << " " << data.componentOne.unsignedCharacter << " " << data.componentOne.floatNumber << endl;
            inFile << data.componentTwo.is << " " << data.componentTwo.unsignedCharacter << " " << data.componentTwo.floatNumber << endl;
            inFile << data.componentThree.is << " " << data.componentThree.unsignedCharacter << " " << data.componentThree.floatNumber << endl;
            inFile << data.componentFour.is << " " << data.componentFour.unsignedCharacter << " " << data.componentFour.floatNumber << endl;
        }
    }
}

void SymmetricDifference(string pathOne, string pathTwo, string pathThree) {
    if (!OneOrLess(pathTwo)) {
        fstream inFile;
        fstream outFile;
        fstream difFile;

        File dataOne;
        File dataTwo;

        int counterOne = -1;
        int counterTwo = 0;
        bool flag = 0;

        inFile.open(pathTwo.c_str(), fstream::in);
        outFile.open(pathOne.c_str(), fstream::in);

        while (!inFile.eof()) {
            inFile >> dataOne.number;

            getline(inFile, dataOne.text);
            getline(inFile, dataOne.text);

            inFile >> dataOne.character;
            inFile >> dataOne.componentOne.is;
            inFile >> dataOne.componentOne.unsignedCharacter;
            inFile >> dataOne.componentOne.floatNumber;
            inFile >> dataOne.componentTwo.is;
            inFile >> dataOne.componentTwo.unsignedCharacter;
            inFile >> dataOne.componentTwo.floatNumber;
            inFile >> dataOne.componentThree.is;
            inFile >> dataOne.componentThree.unsignedCharacter;
            inFile >> dataOne.componentThree.floatNumber;
            inFile >> dataOne.componentFour.is;
            inFile >> dataOne.componentFour.unsignedCharacter;
            inFile >> dataOne.componentFour.floatNumber;

            counterOne++;
        }


        inFile.close();
        outFile.close();

        inFile.open(pathTwo.c_str(), fstream::in);
        difFile.open(pathThree.c_str(), fstream::out);

        for (int i = 0; i < counterOne; i++) {
            inFile >> dataOne.number;

            getline(inFile, dataOne.text);
            getline(inFile, dataOne.text);

            inFile >> dataOne.character;
            inFile >> dataOne.componentOne.is;
            inFile >> dataOne.componentOne.unsignedCharacter;
            inFile >> dataOne.componentOne.floatNumber;
            inFile >> dataOne.componentTwo.is;
            inFile >> dataOne.componentTwo.unsignedCharacter;
            inFile >> dataOne.componentTwo.floatNumber;
            inFile >> dataOne.componentThree.is;
            inFile >> dataOne.componentThree.unsignedCharacter;
            inFile >> dataOne.componentThree.floatNumber;
            inFile >> dataOne.componentFour.is;
            inFile >> dataOne.componentFour.unsignedCharacter;
            inFile >> dataOne.componentFour.floatNumber;

            outFile.open(pathOne.c_str(), fstream::in);

            while (!outFile.eof()) {
                outFile >> dataTwo.number;

                getline(outFile, dataTwo.text);
                getline(outFile, dataTwo.text);

                outFile >> dataTwo.character;
                outFile >> dataTwo.componentOne.is;
                outFile >> dataTwo.componentOne.unsignedCharacter;
                outFile >> dataTwo.componentOne.floatNumber;
                outFile >> dataTwo.componentTwo.is;
                outFile >> dataTwo.componentTwo.unsignedCharacter;
                outFile >> dataTwo.componentTwo.floatNumber;
                outFile >> dataTwo.componentThree.is;
                outFile >> dataTwo.componentThree.unsignedCharacter;
                outFile >> dataTwo.componentThree.floatNumber;
                outFile >> dataTwo.componentFour.is;
                outFile >> dataTwo.componentFour.unsignedCharacter;
                outFile >> dataTwo.componentFour.floatNumber;

                if (dataOne.number == dataTwo.number && dataOne.text == dataTwo.text && dataOne.character == dataTwo.character && dataOne.componentOne.is == dataTwo.componentOne.is &&
                    dataOne.componentOne.unsignedCharacter == dataTwo.componentOne.unsignedCharacter && dataOne.componentOne.floatNumber == dataTwo.componentOne.floatNumber && dataOne.componentTwo.is == dataTwo.componentTwo.is &&
                    dataOne.componentTwo.unsignedCharacter == dataTwo.componentTwo.unsignedCharacter && dataOne.componentTwo.floatNumber == dataTwo.componentTwo.floatNumber && dataOne.componentThree.is == dataTwo.componentThree.is &&
                    dataOne.componentThree.unsignedCharacter == dataTwo.componentThree.unsignedCharacter && dataOne.componentThree.floatNumber == dataTwo.componentThree.floatNumber && dataOne.componentFour.is == dataTwo.componentFour.is &&
                    dataOne.componentFour.unsignedCharacter == dataTwo.componentFour.unsignedCharacter && dataOne.componentFour.floatNumber == dataTwo.componentFour.floatNumber) {
                    flag = 1;

                    break;
                }
                else {
                    flag = 0;
                }
            }

            outFile.close();

            outFile.open(pathOne.c_str(), fstream::out | fstream::app);

            if (flag == 0) {
                outFile << dataOne.number << endl;
                outFile << dataOne.text << endl;
                outFile << dataOne.character << endl;
                outFile << dataOne.componentOne.is << " " << dataOne.componentOne.unsignedCharacter << " " << dataOne.componentOne.floatNumber << endl;
                outFile << dataOne.componentTwo.is << " " << dataOne.componentTwo.unsignedCharacter << " " << dataOne.componentTwo.floatNumber << endl;
                outFile << dataOne.componentThree.is << " " << dataOne.componentThree.unsignedCharacter << " " << dataOne.componentThree.floatNumber << endl;
                outFile << dataOne.componentFour.is << " " << dataOne.componentFour.unsignedCharacter << " " << dataOne.componentFour.floatNumber << endl;
            }
            else {
                difFile << dataOne.number << endl;
                difFile << dataOne.text << endl;
                difFile << dataOne.character << endl;
                difFile << dataOne.componentOne.is << " " << dataOne.componentOne.unsignedCharacter << " " << dataOne.componentOne.floatNumber << endl;
                difFile << dataOne.componentTwo.is << " " << dataOne.componentTwo.unsignedCharacter << " " << dataOne.componentTwo.floatNumber << endl;
                difFile << dataOne.componentThree.is << " " << dataOne.componentThree.unsignedCharacter << " " << dataOne.componentThree.floatNumber << endl;
                difFile << dataOne.componentFour.is << " " << dataOne.componentFour.unsignedCharacter << " " << dataOne.componentFour.floatNumber << endl;

                counterTwo++;
            }

            outFile.close();
        }

        inFile.close();
        difFile.close();

        outFile.open(pathTwo.c_str(), fstream::out | fstream::trunc);
        difFile.open(pathThree.c_str(), fstream::in);

        for (int i = 0; i < counterTwo; i++) {
            difFile >> dataOne.number;

            getline(difFile, dataOne.text);
            getline(difFile, dataOne.text);

            difFile >> dataOne.character;
            difFile >> dataOne.componentOne.is;
            difFile >> dataOne.componentOne.unsignedCharacter;
            difFile >> dataOne.componentOne.floatNumber;
            difFile >> dataOne.componentTwo.is;
            difFile >> dataOne.componentTwo.unsignedCharacter;
            difFile >> dataOne.componentTwo.floatNumber;
            difFile >> dataOne.componentThree.is;
            difFile >> dataOne.componentThree.unsignedCharacter;
            difFile >> dataOne.componentThree.floatNumber;
            difFile >> dataOne.componentFour.is;
            difFile >> dataOne.componentFour.unsignedCharacter;
            difFile >> dataOne.componentFour.floatNumber;

            outFile << dataOne.number << endl;
            outFile << dataOne.text << endl;
            outFile << dataOne.character << endl;
            outFile << dataOne.componentOne.is << " " << dataOne.componentOne.unsignedCharacter << " " << dataOne.componentOne.floatNumber << endl;
            outFile << dataOne.componentTwo.is << " " << dataOne.componentTwo.unsignedCharacter << " " << dataOne.componentTwo.floatNumber << endl;
            outFile << dataOne.componentThree.is << " " << dataOne.componentThree.unsignedCharacter << " " << dataOne.componentThree.floatNumber << endl;
            outFile << dataOne.componentFour.is << " " << dataOne.componentFour.unsignedCharacter << " " << dataOne.componentFour.floatNumber << endl;
        }

        inFile.close();
        outFile.close();
        difFile.close();
    }
}

void SortInt(string pathOne, string pathTwo, string pathThree) {
    if (!OneOrLess(pathOne)) {
        fstream inFile;
        fstream outFile;
        fstream intFile;

        File data;

        int counter = -1;
        int counterTwo = -1;
        int a = 0;
        int b = 0;
        int h = 0;
        int j = 0;
        int temp = 0;

        inFile.open(pathOne.c_str(), fstream::in);
        outFile.open(pathTwo.c_str(), fstream::out | fstream::trunc);

        while (!inFile.eof()) {
            inFile >> data.number;

            outFile << data.number << endl;

            getline(inFile, data.text);
            getline(inFile, data.text);
            getline(inFile, data.character);

            inFile >> data.componentOne.is;
            inFile >> data.componentOne.unsignedCharacter;
            inFile >> data.componentOne.floatNumber;
            inFile >> data.componentTwo.is;
            inFile >> data.componentTwo.unsignedCharacter;
            inFile >> data.componentTwo.floatNumber;
            inFile >> data.componentThree.is;
            inFile >> data.componentThree.unsignedCharacter;
            inFile >> data.componentThree.floatNumber;
            inFile >> data.componentFour.is;
            inFile >> data.componentFour.unsignedCharacter;
            inFile >> data.componentFour.floatNumber;

            counter++;
        }

        inFile.close();
        outFile.close();

        for (int i = 0; i < counter; i++) {
            outFile.open(pathTwo.c_str(), fstream::in);
            intFile.open(pathThree.c_str(), fstream::out | fstream::trunc);

            outFile >> a;
            outFile >> b;

            counterTwo = 0;

            if (a > b) {
                h = a;
                a = b;
                b = h;
            }

            if (a != b) {
                intFile << a << endl;

                counterTwo++;
            }

            j = 0;

            while (!outFile.eof()) {
                outFile >> a;

                if (a > b) {
                    h = a;
                    a = b;
                    b = h;
                }

                j++;

                if (j == counter - 1) {
                    if (a < b) {
                        intFile << b << endl;

                        counterTwo++;
                    }
                    else {
                        intFile << a << endl;

                        counterTwo++;
                    }
                }
                else {
                    if (a != b) {
                        intFile << a << endl;

                        counterTwo++;
                    }
                }
            }

            outFile.close();
            intFile.close();

            outFile.open(pathTwo.c_str(), fstream::out);
            intFile.open(pathThree.c_str(), fstream::in);

            for (int j = 0; j < counter; j++) {
                intFile >> a;
                outFile << a << endl;
            }

            intFile.close();
            outFile.close();
        }

        outFile.open(pathTwo.c_str(), ofstream::out | ofstream::trunc);
        outFile.close();

        outFile.open(pathTwo.c_str(), fstream::out | fstream::app);
        intFile.open(pathThree.c_str(), fstream::in);

        for (int i = 0; i < counterTwo; i++) {
            inFile.open(pathOne.c_str(), fstream::in);

            intFile >> temp;

            for (int j = 0; j < counter; j++) {
                inFile >> data.number;

                getline(inFile, data.text);
                getline(inFile, data.text);
                getline(inFile, data.character);

                inFile >> data.componentOne.is;
                inFile >> data.componentOne.unsignedCharacter;
                inFile >> data.componentOne.floatNumber;
                inFile >> data.componentTwo.is;
                inFile >> data.componentTwo.unsignedCharacter;
                inFile >> data.componentTwo.floatNumber;
                inFile >> data.componentThree.is;
                inFile >> data.componentThree.unsignedCharacter;
                inFile >> data.componentThree.floatNumber;
                inFile >> data.componentFour.is;
                inFile >> data.componentFour.unsignedCharacter;
                inFile >> data.componentFour.floatNumber;

                if (data.number == temp) {
                    outFile << data.number << endl;
                    outFile << data.text << endl;
                    outFile << data.character << endl;
                    outFile << data.componentOne.is << " " << data.componentOne.unsignedCharacter << " " << data.componentOne.floatNumber << endl;
                    outFile << data.componentTwo.is << " " << data.componentTwo.unsignedCharacter << " " << data.componentTwo.floatNumber << endl;
                    outFile << data.componentThree.is << " " << data.componentThree.unsignedCharacter << " " << data.componentThree.floatNumber << endl;
                    outFile << data.componentFour.is << " " << data.componentFour.unsignedCharacter << " " << data.componentFour.floatNumber << endl;
                }
            }

            inFile.close();
        }

        intFile.close();
        outFile.close();

        inFile.open(pathOne.c_str(), fstream::out | fstream::trunc);
        outFile.open(pathTwo.c_str(), fstream::in);

        for (int i = 0; i < counter; i++) {
            outFile >> data.number;

            getline(outFile, data.text);
            getline(outFile, data.text);
            getline(outFile, data.character);

            outFile >> data.componentOne.is;
            outFile >> data.componentOne.unsignedCharacter;
            outFile >> data.componentOne.floatNumber;
            outFile >> data.componentTwo.is;
            outFile >> data.componentTwo.unsignedCharacter;
            outFile >> data.componentTwo.floatNumber;
            outFile >> data.componentThree.is;
            outFile >> data.componentThree.unsignedCharacter;
            outFile >> data.componentThree.floatNumber;
            outFile >> data.componentFour.is;
            outFile >> data.componentFour.unsignedCharacter;
            outFile >> data.componentFour.floatNumber;

            inFile << data.number << endl;
            inFile << data.text << endl;
            inFile << data.character << endl;
            inFile << data.componentOne.is << " " << data.componentOne.unsignedCharacter << " " << data.componentOne.floatNumber << endl;
            inFile << data.componentTwo.is << " " << data.componentTwo.unsignedCharacter << " " << data.componentTwo.floatNumber << endl;
            inFile << data.componentThree.is << " " << data.componentThree.unsignedCharacter << " " << data.componentThree.floatNumber << endl;
            inFile << data.componentFour.is << " " << data.componentFour.unsignedCharacter << " " << data.componentFour.floatNumber << endl;
        }

        inFile.close();
        outFile.close();
    }
}

void SortString(string pathOne, string pathTwo, string pathThree) {
    if (!OneOrLess(pathOne)) {
        fstream inFile;
        fstream outFile;
        fstream strFile;

        File data;

        int counter = -1;
        int counterTwo = -1;
        int j = 0;

        string a;
        string b;
        string h;
        string temp;

        inFile.open(pathOne.c_str(), fstream::in);
        outFile.open(pathTwo.c_str(), fstream::out | fstream::trunc);

        while (!inFile.eof()) {
            inFile >> data.number;

            getline(inFile, data.text);
            getline(inFile, data.text);
            getline(inFile, data.character);

            outFile << data.text << endl;

            inFile >> data.componentOne.is;
            inFile >> data.componentOne.unsignedCharacter;
            inFile >> data.componentOne.floatNumber;
            inFile >> data.componentTwo.is;
            inFile >> data.componentTwo.unsignedCharacter;
            inFile >> data.componentTwo.floatNumber;
            inFile >> data.componentThree.is;
            inFile >> data.componentThree.unsignedCharacter;
            inFile >> data.componentThree.floatNumber;
            inFile >> data.componentFour.is;
            inFile >> data.componentFour.unsignedCharacter;
            inFile >> data.componentFour.floatNumber;

            counter++;
        }

        inFile.close();
        outFile.close();

        for (int i = 0; i < counter; i++) {
            outFile.open(pathTwo.c_str(), fstream::in);
            strFile.open(pathThree.c_str(), fstream::out | fstream::trunc);

            getline(outFile, a);
            getline(outFile, b);

            counterTwo = 0;

            if (a > b) {
                h = a;
                a = b;
                b = h;
            }

            if (a != b) {
                strFile << a << endl;

                counterTwo++;
            }

            j = 0;

            while (!outFile.eof()) {
                getline(outFile, a);

                if (a > b) {
                    h = a;
                    a = b;
                    b = h;
                }

                j++;

                if (j == counter - 1) {
                    if (a < b) {
                        strFile << b << endl;

                        counterTwo++;
                    }
                    else {
                        strFile << a << endl;

                        counterTwo++;
                    }
                }
                else {
                    if (a != b) {
                        strFile << a << endl;

                        counterTwo++;
                    }
                }
            }

            outFile.close();
            strFile.close();

            outFile.open(pathTwo.c_str(), fstream::out);
            strFile.open(pathThree.c_str(), fstream::in);

            for (int j = 0; j < counter; j++) {
                getline(strFile, a);
                outFile << a << endl;
            }

            strFile.close();
            outFile.close();
        }

        outFile.open(pathTwo.c_str(), ofstream::out | ofstream::trunc);
        outFile.close();

        outFile.open(pathTwo.c_str(), fstream::out | fstream::app);
        strFile.open(pathThree.c_str(), fstream::in);

        for (int i = 0; i < counterTwo; i++) {
            inFile.open(pathOne.c_str(), fstream::in);

            getline(strFile, temp);

            for (int j = 0; j < counter; j++) {
                inFile >> data.number;

                getline(inFile, data.text);
                getline(inFile, data.text);
                getline(inFile, data.character);

                inFile >> data.componentOne.is;
                inFile >> data.componentOne.unsignedCharacter;
                inFile >> data.componentOne.floatNumber;
                inFile >> data.componentTwo.is;
                inFile >> data.componentTwo.unsignedCharacter;
                inFile >> data.componentTwo.floatNumber;
                inFile >> data.componentThree.is;
                inFile >> data.componentThree.unsignedCharacter;
                inFile >> data.componentThree.floatNumber;
                inFile >> data.componentFour.is;
                inFile >> data.componentFour.unsignedCharacter;
                inFile >> data.componentFour.floatNumber;

                if (data.text == temp) {
                    outFile << data.number << endl;
                    outFile << data.text << endl;
                    outFile << data.character << endl;
                    outFile << data.componentOne.is << " " << data.componentOne.unsignedCharacter << " " << data.componentOne.floatNumber << endl;
                    outFile << data.componentTwo.is << " " << data.componentTwo.unsignedCharacter << " " << data.componentTwo.floatNumber << endl;
                    outFile << data.componentThree.is << " " << data.componentThree.unsignedCharacter << " " << data.componentThree.floatNumber << endl;
                    outFile << data.componentFour.is << " " << data.componentFour.unsignedCharacter << " " << data.componentFour.floatNumber << endl;
                }
            }

            inFile.close();
        }

        strFile.close();
        outFile.close();

        inFile.open(pathOne.c_str(), fstream::out | fstream::trunc);
        outFile.open(pathTwo.c_str(), fstream::in);

        for (int i = 0; i < counter; i++) {
            outFile >> data.number;

            getline(outFile, data.text);
            getline(outFile, data.text);
            getline(outFile, data.character);

            outFile >> data.componentOne.is;
            outFile >> data.componentOne.unsignedCharacter;
            outFile >> data.componentOne.floatNumber;
            outFile >> data.componentTwo.is;
            outFile >> data.componentTwo.unsignedCharacter;
            outFile >> data.componentTwo.floatNumber;
            outFile >> data.componentThree.is;
            outFile >> data.componentThree.unsignedCharacter;
            outFile >> data.componentThree.floatNumber;
            outFile >> data.componentFour.is;
            outFile >> data.componentFour.unsignedCharacter;
            outFile >> data.componentFour.floatNumber;

            inFile << data.number << endl;
            inFile << data.text << endl;
            inFile << data.character << endl;
            inFile << data.componentOne.is << " " << data.componentOne.unsignedCharacter << " " << data.componentOne.floatNumber << endl;
            inFile << data.componentTwo.is << " " << data.componentTwo.unsignedCharacter << " " << data.componentTwo.floatNumber << endl;
            inFile << data.componentThree.is << " " << data.componentThree.unsignedCharacter << " " << data.componentThree.floatNumber << endl;
            inFile << data.componentFour.is << " " << data.componentFour.unsignedCharacter << " " << data.componentFour.floatNumber << endl;
        }
    }
}
