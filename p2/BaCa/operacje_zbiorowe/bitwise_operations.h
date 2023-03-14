#include "emplace.cpp"
#include "insert.cpp"
#include "erase.cpp"
#include "print.cpp"
#include "emptiness_nonempty.cpp"
#include "member.cpp"
#include "disjoint_conjunctive.cpp"
#include "inclusion_equality.cpp"
#include "operations.cpp"
#include "cardinality.cpp"
#include "relations.cpp"

void Emplace(char*, int*);

void Insert(char*, int*);

void Erase(char*, int*);

void Print(int, char*);

bool Emptiness(int);

bool Nonempty(int);

bool Member(char*, int);

bool Disjoint(int, int);

bool Conjunctive(int, int);

bool Inclusion(int, int);

bool Equality(int, int);

void Union(int, int, int*);

void Intersection(int, int, int*);

void Symmetric(int, int, int*);

void Difference(int, int, int*);

void Complement(int, int*);

int Cardinality(int);

bool LessThen(int, int);

bool LessEqual(int, int);

bool GreatEqual(int, int);

bool GreatThen(int, int);