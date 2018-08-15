class Solution {
public:
    void printArr(int** arr, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int **isPalindrom = new int* [n];
        for(int i = 0; i < n; i++)
            isPalindrom[i] = new int [n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                isPalindrom[i][j] = false;
        for(int i = 0; i < n; i++)
            isPalindrom[i][i] = 1;
        for(int i = 1; i < n; i++)
            isPalindrom[i][i - 1] = 1;
        // initialize 
        // 0 1 1 2 2 3
        int max = 1;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                int add = len == 2 ? 1 : 2;
                isPalindrom[i][j] = s[i] == s[j] ? isPalindrom[i + 1][j - 1] + add : isPalindrom[i + 1][j - 1];
                isPalindrom[i][j] = isPalindrom[i][j] > isPalindrom[i][j - 1] ? isPalindrom[i][j] : isPalindrom[i][j - 1];
                isPalindrom[i][j] = isPalindrom[i][j] > isPalindrom[i + 1][j] ? isPalindrom[i][j] : isPalindrom[i + 1][j];
                max = isPalindrom[i][j] > max ? isPalindrom[i][j] : max;
            }
        }
        //printArr(isPalindrom, n); 
        return max;
        
    }
};
