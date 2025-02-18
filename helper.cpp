
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <iomanip> 
using namespace std;

string to_string_with_precision(double value, int precision) {
    ostringstream out;
    out << fixed << setprecision(precision) << value;
    return out.str();
}
