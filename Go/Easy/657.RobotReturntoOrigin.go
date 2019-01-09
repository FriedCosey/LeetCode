func judgeCircle(moves string) bool {
    hori := 0
    verti := 0
    for _, val := range moves{
        switch val{
            case 'U':
            verti++
            case 'D':
            verti--
            case 'L':
            hori++
            case 'R':
            hori--
        }
    }
    return hori == 0 && verti == 0
    
}
