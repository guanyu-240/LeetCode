func detectCapitalUse(word string) bool {
    match,_ := regexp.MatchString("^([a-z]*|[A-Z]([A-Z]*|[a-z]*))$", word)
    return match
}
