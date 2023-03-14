int CardinalityRecursiveTwo(int set, int bit, int pow) {
    if (bit != 0) {
        if (set & bit) {
            pow++;
        }

        bit >>= 1;

        return CardinalityRecursiveTwo(set, bit, pow);
    }

    return pow;
}

int CardinalityTwo(int set) {
    if (set == 0) {
        return 0;
    }
    else if (set == 1) {
        return 1;
    }
    else {
        int bit = 1;
        int pow = 0;

        bit <<= 30;

        if (set < 0) {
            pow++;
        }

        return CardinalityRecursiveTwo(set, bit, pow);
    }
}

bool LessThen(int setOne, int setTwo) {
    int setOnePow = CardinalityTwo(setOne);
    int setTwoPow = CardinalityTwo(setTwo);

    return (setOnePow < setTwoPow || setOne < setTwo && setOnePow == setTwoPow);
}

bool LessEqual(int setOne, int setTwo) {
    int setOnePow = CardinalityTwo(setOne);
    int setTwoPow = CardinalityTwo(setTwo);

    return (setOnePow < setTwoPow || setOne <= setTwo && setOnePow == setTwoPow);
}

bool GreatEqual(int setOne, int setTwo) {
    int setOnePow = CardinalityTwo(setOne);
    int setTwoPow = CardinalityTwo(setTwo);

    return (setOnePow > setTwoPow || setOne >= setTwo && setOnePow == setTwoPow);
}

bool GreatThen(int setOne, int setTwo) {
    int setOnePow = CardinalityTwo(setOne);
    int setTwoPow = CardinalityTwo(setTwo);

    return (setOnePow > setTwoPow || setOne > setTwo && setOnePow == setTwoPow);
}