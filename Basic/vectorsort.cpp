#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, int b){
    if(a > b)
        return true;
    return false;   
}

int main(){
    vector<int> a{1 ,2 ,3 ,4 ,5 };
    sort(a.begin(), a.end(), compare);
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
