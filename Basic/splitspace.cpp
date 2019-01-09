#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
struct hehe{
    string a;
};
class Solution {
public:
    void getWords(string &s, vector<string>& words,hehe a){
        a.a = "aa";
        cout << a.a << endl;
        istringstream ss(s);
        string tmp;
        while(getline(ss, tmp, ' ')){
            if(tmp[0] == ' ' || tmp[0] == '\t' || tmp[0] == '\n')
                continue;
            int end = tmp.size() - 1;
            while(end >= 0 && (tmp[end] == ' ' || tmp[end] == '\t' || tmp[end] == '\n'))
                end--;
            // if(end < 0)
               // continue;
            tmp = tmp.substr(0, end + 1);
            words.push_back(tmp);
        }
    } 
    void reverse(vector<string>& words){
        int left = 0, right = words.size() - 1;
        while(left < right){
            swap(words[left], words[right]);
            left++, right--;
        }
    }
    void reverseWords(string &s) {
        vector<string> words;
        hehe a;
        getWords(s, words, a);
        reverse(words);
        s.clear();
        cout << words.size() << endl;
        for(int i = 0; i < words.size(); i++){
            s += words[i];
            s += ' ';
        }
        s.pop_back();
        
    }
};
int main(){
    string s = "aaaa\tbbbbb\tccccccc\tdddddd";
    //cout << s << endl;
    istringstream ss(s);
    string tmp;
    while(getline(ss, tmp, '\t')){
        // cout << tmp << endl;
    }
    vector<string> la;
    // string space = "    aaaa bbb cccc ddeeeee";
    // getWords(space, la);
    Solution tester;
    string in = "    ";
    tester.reverseWords(in);
    cout << in << endl;

    return 0;


}
