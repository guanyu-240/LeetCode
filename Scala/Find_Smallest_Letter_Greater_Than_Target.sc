object Solution {
    def nextGreatestLetter(letters: Array[Char], target: Char): Char = {
        def dist(target: Char, letter: Char): Int = {
            if (letter > target) letter - target
            else letter + 26 - target
        }
        
        letters.minBy(dist(target, _))
    }    
}
