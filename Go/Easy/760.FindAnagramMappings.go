func anagramMappings(A []int, B []int) []int {
    m := make(map[int][]int)
    for idx, val := range B{
       m[val] = append(m[val], idx)
    }
    
    res := []int{}
    for _, val := range A{
        res = append(res, m[val][0])
        if len(m[val]) > 1{
            m[val] = m[val][1:]
        }
    }
    return res
    
    
    
}
