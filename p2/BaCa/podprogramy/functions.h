//Mateusz Rozdzinski

#include <string>
#include <cstdarg>
#include "Sum.cpp"
#include "Mult.cpp"
#include "Operation.cpp"

using namespace std;

string Sum(int, const string*);
string Sum(int, ...);
void Sum(string*, int, const string*);
void Sum(string*, int, ...);
void Sum(string&, int, const string*);
void Sum(string&, int, ...);

string Mult(int, const string*);
string Mult(int, ...);
void Mult(string*, int, const string*);
void Mult(string*, int, ...);
void Mult(string&, int, const string*);
void Mult(string&, int, ...);

string Operation(string(*)(int, const string*), int, const string*);
string Operation(string(*)(int, const string*), int, ...);
void Operation(string*, string(*)(int, const string*), int, ...);
void Operation(string*, string(*)(int, const string*), int, const string*);
void Operation(string&, void(*)(string*, int, const string*), int, const string*);
void Operation(string&, void(*)(string*, int, const string*), int, ...);