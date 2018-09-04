class Solution {
public:
    string nearestPalindromic(string n) {
        set<string> candi;
        string tmp;
        for(int i = 0; i <= n.size(); i++){
            if(i == 0 || i == n.size())
                tmp += '1';
            else
                tmp += '0';
        }
        // generate 1xxxxxx1
        candi.insert(tmp);
        tmp.clear();
        if(n.size() == 1);
        else{
            for(int i = 0; i < n.size() - 1; i++)
                tmp += '9';
            candi.insert(tmp);
        }
        // generate 9
        if(n.size() % 2)
            tmp = n.substr(0, n.size() / 2 + 1);
        else
            tmp = n.substr(0, n.size() / 2);
        // split half of n
        string old_tmp = tmp;
        for(int i = -1; i <= 1; i++){
            tmp = old_tmp;
            if(i == -1 && (tmp[tmp.size() - 1] == '0'))
                continue;
            if(i == 1 && (tmp[tmp.size() - 1]) == '9')
                continue;
            tmp[tmp.size() - 1] += i;
            int start = n.size() % 2 ? tmp.size() - 2 : tmp.size() - 1;
            for(int i = 0; i < n.size() / 2; i++, start--){
                tmp += tmp[start];
            }
            candi.insert(tmp);
        }
        candi.erase(n);
        set<string>::iterator it;
        long long int diff = LONG_MAX;
        string res;
        stringstream ss;
        ss.str(n);
        long long int origin;
        long long int cur = LONG_MAX;
        ss >> origin;
        for(it = candi.begin(); it != candi.end(); it++){
            cout << *it << endl;
            ss.clear();
            ss.str(*it);
            long long int num;
            ss >> num;
            if(abs(num - origin) <= diff){
                if(abs(num - origin) == diff && num > cur)
                    continue;
                cur = num;
                res = *it;
                diff = abs(num - origin);
            }
        }
        return res;
    }
};
