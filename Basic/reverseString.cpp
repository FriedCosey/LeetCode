#include <iostream>
#include <string>
using namespace std;

void reverse(string& s){
    int i = 0, j = s.size() - 1;

    for(; i <= j; i++ , j--){
        swap(s[i], s[j]);
    }

}

int main(){
    
    string a = "abcdef";
    string b = "abcdefg";
    reverse(a), reverse(b);
    cout << a << endl;
    cout << b << endl;


}
