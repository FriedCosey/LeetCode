class Solution {
public:
    string countAndSay(int n) {
        string pre, cur;
        pre = "1";
        int j = 0;
        for(int i = 0, count = 1; i < n - 1; i++){
            for(j = 1, count = 1; j < pre.size(); j++){
                if(pre[j] == pre[j-1])
                    count++;
                else{
                    char tmp = count + '0';
                    string tmp_(1, tmp);
                    cur = cur + tmp_ + pre[j-1]; 
                    count = 1;
                }
            }
            char tmp = count + '0';
            string tmp_(1, tmp);
            cur = cur + tmp_ + pre[j-1]; 
            pre = cur;
            cur.clear();
        }
        return pre;
    }
};
