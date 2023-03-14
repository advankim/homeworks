void Union(int setOne, int setTwo, int* setResult) {
    *setResult = (setOne | setTwo);
}

void Intersection(int setOne, int setTwo, int* setResult) {
    *setResult = (setOne & setTwo);
}

void Symmetric(int setOne, int setTwo, int* setResult) {
    *setResult = (setOne ^ setTwo);
}

void Difference(int setOne, int setTwo, int* setResult) {
    *setResult = (setOne & ~setTwo);
}

void Complement(int set, int* setResult) {
    *setResult = (~set);
}