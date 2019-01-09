func numUniqueEmails(emails []string) int {
    m := map[string]bool{}
    for _, val := range(emails){
        i := strings.Index(val, "@")
        local := val[:i]
        domain := val[i:]
        
        if i = strings.Index(local, "+"); i != -1{
            local = local[:i]
        }
        
        for i = strings.Index(local, "."); i != -1;{
            head := local[:i] 
            end := local[i+1:]
            local = head + end
            i = strings.Index(local, ".")
        }
        
        m[local + domain] = true
    }
    return len(m) 
}
