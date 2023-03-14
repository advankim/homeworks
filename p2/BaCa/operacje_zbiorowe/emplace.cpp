void EmplaceRecursive(char* sequences, int* set, int i) {
    if (*(sequences + i) == ' ') {
        EmplaceRecursive(sequences, set, ++i);
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

        *set |= bit;

        EmplaceRecursive(sequences, set, i);
    }
}

void Emplace(char* sequences, int* set) {
    int i = 0;
    *set = 0;

    EmplaceRecursive(sequences, set, i);
}