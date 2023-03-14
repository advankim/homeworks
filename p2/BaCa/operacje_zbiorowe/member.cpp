//Mateusz Rozdzinski

bool MemberRecursive(char* sequences, int set, int i) {
    if (*(sequences + i) == ' ') {
        return MemberRecursive(sequences, set, ++i);
    }
    else if (*(sequences + i) == '0' || *(sequences + i) == '1') {
        int bit = 1;
        int temp = 0;

        if (*(sequences + i++) == '1') {
            temp += 16;
        }

        if (*(sequences + i++) == '1') {
            temp += 8;
        }

        if (*(sequences + i++) == '1') {
            temp += 4;
        }

        if (*(sequences + i++) == '1') {
            temp += 2;
        }

        if (*(sequences + i++) == '1') {
            temp += 1;
        }

        bit <<= temp;

        if (set & bit) {
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}

bool Member(char* sequences, int set) {
    int i = 0;

    return MemberRecursive(sequences, set, i);
}