class Solution {
public:
    void genNextWord(queue<string>& curWord, unordered_set<string>& wordMap, string head){
        for(int i = 0; i < head.size(); i++){
            string next = head;
            for(int j = 0; j < 26; j++){
                next[i] = 'a' + j;
                if(wordMap.find(next) == wordMap.end())
                    continue;
                wordMap.erase(next);
                curWord.push(next);
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        queue<string> curWord;
        curWord.push(beginWord);
        int counter = 0;
        unordered_set<string> wordMap;
        for(int i = 0; i < wordList.size(); i++){
            wordMap.insert(wordList[i]);
        }
        
        while(!curWord.empty()){
            int total = curWord.size();
            counter++;
            for(int i = 0; i < total; i++){
                string head = curWord.front();
                curWord.pop();
                if(head == endWord)
                    return counter;
                genNextWord(curWord, wordMap, head);
            }
        }
        
        return 0;
    }
};
