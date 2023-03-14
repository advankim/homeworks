bool Inclusion(int setOne, int setTwo) {
    return ((setOne & setTwo) == setOne);
}

bool Equality(int setOne, int setTwo) {
    return (setOne == setTwo);
}