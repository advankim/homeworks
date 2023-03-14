#include <iostream>
#include <bitset>
#include "bitwise_operations.h"

using namespace std;

int main() {
    char seq[200] = {};
    int* number;
    int temp = 0;
    number = &temp;

    cout.setf(cout.boolalpha);

//    cout << GreatThen(3, 4) << endl;
//
//    cout << GreatEqual(2, 2) << endl;
//
//    cout << LessEqual(1, -1) << endl;
//
//    cout << LessThen(2, 2) << endl;
//
//    cout << Cardinality(-3) << endl;
//    cout << Cardinality(-2) << endl;

//    Complement(x, number);
//
//    cout << *number << endl;

//    Difference(x, y, number);
//
//    cout << *number << endl;

//    Symmetric(x, y, number);
//
//    cout << *number << endl;

//    Intersection(x, y, number);
//
//    cout << *number << endl;

//    Union(x, y, number);
//
//    cout << *number << endl;

//    cout << Inclusion(5, 7) << endl;
//
//    cout << (-7 & -3) << endl;

//    cout << Equality(-5, -5) << endl;

//    cout << Disjoint (4, 2) << endl;

//    cout << Conjunctive (4, 2) << endl;

    Emplace("00000 00001 00100", number);

    cout << *number << endl;

    cout << bitset<32>(*number) << endl;

    cout << Member("   00100   ", *number) << endl;

    cout << Emptiness(-1) << endl;

    Print(*number, seq);

    cout << seq << endl;

    cout.unsetf(cout.boolalpha);

    return 0;
}
