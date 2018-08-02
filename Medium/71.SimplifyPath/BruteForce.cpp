class Solution {
public:
    string simplifyPath(string path) {
        string cur;
        for(int i = 0; i < path.size(); i++){
            while(path[i] == '/' && path[i+1] == '/')
                i++; // skip /
            if(path[i] == '.' && path[i+1] == '.' && (i + 2 == path.size() || path[i+2] == '/')){
                i++;
                cur.pop_back();
                while(!cur.empty() && cur.back() != '/')
                    cur.pop_back();
                if(!cur.empty())
                    cur.pop_back();
            }
            else if(path[i] == '.' && (i + 1 == path.size() || path[i + 1] == '/'))
                cur.pop_back();
            else{
                cur += path[i];
                while(path[i] == '.' && path[i + 1] == '.')
                    i++, cur += path[i];
            }
        }
        if(cur.back() == '/')
            cur.pop_back();
        if(cur.empty())
            cur += '/';
        return cur;
    }
};
