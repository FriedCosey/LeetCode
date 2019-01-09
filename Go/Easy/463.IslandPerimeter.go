func islandPerimeter(grid [][]int) int {
    for i := 0; i < len(grid); i++{
        for j := 0; j < len(grid[i]); j++{
            if grid[i][j] == 1{
                return helper(grid, i, j)
            }
        }
    }
    return 0
}

func helper(grid [][]int, row int, col int) int {
    if !isValid(grid, row, col) || grid[row][col] == 0{
        return 1
    }
    if grid[row][col] == -1{
        return 0
    }
    
    grid[row][col] = -1
    return helper(grid, row + 1, col) + helper(grid, row - 1, col)  + helper(grid, row, col + 1) + helper(grid, row, col - 1)
    
        
}

func isValid(grid [][]int, row int, col int) bool{
    if row >= len(grid) || row < 0{
        return false
    }
    if col >= len(grid[row]) || col < 0{
        return false
    }
    return true
}
