func findDisappearedNumbers(nums []int) []int {
    lookup := make([]bool, len(nums) + 1)
    res := []int{}
    for _, val := range nums{
        lookup[val] = true
    }
    for key, val := range lookup{
        if val == false{
            res = append(res, key)
        }
    }
    return res[1:]
    
}
