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

- Partition into independent *subproblems*
