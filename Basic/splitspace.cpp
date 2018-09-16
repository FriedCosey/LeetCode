#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string s = "aaaa\tbbbbb\tccccccc\tdddddd";
    cout << s << endl;
    istringstream ss(s);
    string tmp;
    while(getline(ss, tmp, '\t')){
        cout << tmp << endl;
    }
    return 0;


}
