#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a;
    int i = 1;
    a.push_back(i++);
    a.push_back(i++);
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    vector<vector<int> > b;
    vector<int> c;
    c.push_back(2);
    b.push_back(c);
    c.clear();
    b.push_back(c);
    c.push_back(3);
    b.push_back(c);
    for(int i = 0; i < b.size(); i++)
        for(int j = 0; j < b[i].size(); j++)
            cout << b[i][j] << " ";
    cout << endl;
    return 0;

}
