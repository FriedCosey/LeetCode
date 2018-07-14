#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void backtracking(string cur, vector<string>& res, int left, int right){
		cout << left << " " << right << " " << cur << endl;
        if(left == 0 && right == 0){
            res.push_back(cur);
            //return;
        }
        if(left > 0){
            backtracking(cur + '(', res, left - 1, right);
        }
        if(left < right){
            backtracking(cur + ')', res, left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> res;
        backtracking(cur, res, n, n);
        return res;
    }
};

int main(){

	Solution tester;
	tester.generateParenthesis(3);

}
