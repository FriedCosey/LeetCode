func numUniqueEmails(emails []string) int {
    m := map[string]bool{}
    for _, val := range(emails){
        i := strings.Index(val, "@")
        local := val[:i]
        domain := val[i:]
        
        if i = strings.Index(local, "+"); i != -1{
            local = local[:i]
        }
        
        local_ := ""
        for _, val := range local{
            if val != '.'{
                local_ += string(val)
            }
        }
        
        m[local_ + domain] = true
    }
    return len(m) 
}
