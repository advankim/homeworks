int CardinalityRecursive(int set, int bit, int pow) {
    if (bit != 0) {
        if (set & bit) {
            pow++;
        }

        bit >>= 1;

        return CardinalityRecursive(set, bit, pow);
    }

    return pow;
}

int Cardinality(int set) {
    if (set == 0) {
        return 0;
    }
    else {
        int bit = 1;
        int pow = 0;

        bit <<= 30;

        if (set < 0) {
            pow++;
        }

        return CardinalityRecursive(set, bit, pow);
    }
}