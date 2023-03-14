bool Disjoint(int setOne, int setTwo) {
    return !(setOne & setTwo);
}

bool Conjunctive(int setOne, int setTwo) {
    return !Disjoint(setOne, setTwo);
}