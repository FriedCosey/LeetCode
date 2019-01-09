func flipAndInvertImage(A [][]int) [][]int {
    
    for _, row := range(A){
        
        for j := 0; j < len(row) / 2; j++{
            row[j], row[len(row) - j - 1] = row[len(row) - j - 1], row[j] 
            row[j] = 1 - row[j] 
            row[len(row) - j - 1] = 1 - row[len(row) - j - 1] 
        }
        
        if len(row) % 2 == 1{
            row[len(row) / 2] = 1 - row[len(row) / 2]
        }
        
    }
    return A 
}
