#### Recursion
```(Reference: https://www.youtube.com/watch?v=GZm6xMnNmgw)```

- Does not always take more memory than iterative
```C++
int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a % b);
}
```

```C++
int gcd(int a, int b){
    int tmp = 0;
    while(b){
        tmp = b;
        b %= a;
        a = tmp;
    }
    return a
}
```

- a call b call a (Recursive Indirectly)

- Partition into **independent subproblems**

- Stack: function call <-> Heap: Dynamic Memory Allocation
    - Everytime doing recursion, use more stack space?
        - **Tail Recursion**: ```https://stackoverflow.com/questions/33923/what-is-tail-recursion``` 
```C++
// Do -> Recursion
main(){
    printf("tail");
    tail(x);
    return 0;
}
```

```C++
// Head -> Recursion
main(){
    head(x);
    printf("head");
    return 0;
}
```

