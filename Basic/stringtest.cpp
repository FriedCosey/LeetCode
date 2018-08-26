#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(){

    int i = -1;
    stringstream ss;
    ss << i;
    cout << ss.str() << endl; 
    string a = "asdf";
    string b = "fffff";

    cout << a + b << endl;

    return 0;

}

