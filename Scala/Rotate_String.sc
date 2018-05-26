object Solution {
    def rotateString(A: String, B: String): Boolean = {
        return A.length() == B.length() && (B+B).contains(A)
    }
}
