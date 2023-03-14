//Mateusz Rozdzinski

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
    int bit = 1;
    int pow = 0;

    if (set < 0) {
        pow++;
    }

    bit <<= 30;

    return CardinalityRecursive(set, bit, pow);
}''