#include <iostream>
using namespace std;


struct A{
    int val;
};
int main(){
    A* b = new A;
    b->val = 2;
    int i = b->val;
    cout << i << endl;
    b->val = 3;
    cout << i << endl;
    return 0;


}
