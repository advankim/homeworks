void Print(int set, char* sequences) {
    int i = 0;
    int space = 0;

    if (set < 0) {
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';

        if (space == 0) {
            space = 1;
        }
    } //31

    if (set & 1073741824) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //30

    if (set & 536870912) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //29

    if (set & 268435456) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //28

    if (set & 134217728) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //27

    if (set & 67108864) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //26

    if (set & 33554432) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //25

    if (set & 16777216) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //24

    if (set & 8388608) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //23

    if (set & 4194304) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //22

    if (set & 2097152) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //21

    if (set & 1048576) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //20

    if (set & 524288) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //19

    if (set & 262144) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //18

    if (set & 131072) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //17

    if (set & 65536) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //16

    if (set & 32768) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //15

    if (set & 16384) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //14

    if (set & 8192) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //13

    if (set & 4096) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //12

    if (set & 2048) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //11

    if (set & 1024) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //10

    if (set & 512) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //9

    if (set & 256) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //8

    if (set & 128) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //7

    if (set & 64) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //6

    if (set & 32) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //5

    if (set & 16) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //4

    if (set & 8) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '1';
    } //3

    if (set & 4) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
        *(sequences + i++) = '0';
    } //2

    if (set & 2) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '1';
    } //1

    if (set & 1) {
        if (space == 0) {
            space = 1;
        }
        else {
            *(sequences + i++) = ' ';
        }

        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
        *(sequences + i++) = '0';
    } //0

    if (i == 0) {
        *(sequences + i++) = 'e';
        *(sequences + i++) = 'm';
        *(sequences + i++) = 'p';
        *(sequences + i++) = 't';
        *(sequences + i++) = 'y';
    }

    *(sequences + i) = '\0';
}