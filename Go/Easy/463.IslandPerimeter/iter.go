func islandPerimeter(grid [][]int) int {
    res := 0
    for i := 0; i < len(grid); i++{
        for j := 0; j < len(grid[i]); j++{
            if grid[i][j] == 1{
                res += checkNeighbor(grid, i, j)
            }
        }
    }
    return res 
}

func checkNeighbor(grid [][]int, row int, col int) int{
    rLen := len(grid)
    cLen := len(grid[row])
    res := 0
    if row - 1 < 0 || grid[row - 1][col] == 0{
        res++;
    }
    if row + 1 >= rLen || grid[row + 1][col] == 0{
        res++;
    }
    if col - 1 < 0 || grid[row][col - 1] == 0{
        res++;
    }
    if col + 1 >= cLen || grid[row][col + 1] == 0{
        res++;
    }
    return res
}
