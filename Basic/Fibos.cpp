int fibo(int n){
    if(n == 1 || n == 0)    
        return 1;
    return fibo(n-1) + fibo(n-2);
}

int fiboIter(int n){
    int old = 1, oold = 1, cur = 0;
    for(int i = 2; i <= 10; i++){
        cur = old + oold; 
        oold = old;
        old = cur;
    }
    return cur;
}

// DP
int fibo(vector<int>& mem, int n){
    counter++;
    if(n == 1 || n == 0)   
        return 1;
    if(mem[n] != -1)
        return mem[n];
    mem[n] = fibo(mem, n-2) + fibo(mem, n-1);
    return mem[n];
}
