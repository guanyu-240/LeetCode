class Solution:
    # @param s, a string
    # @return a boolean
    """
    Finite auto-mata solution
       char index from 0 to 4 are '+/-', 'digit', 'E/e', '.', ' '.
       9 states:
          0: start
          1: +/- after start
          2: digits
          3: middle '.' discovered
          4: E/e discovered
          5: +/- after E/e
          6: digits after e
          7: beginning '.' discovered
          8: traling ' '
    """
    def __init__(self):
        self.__transitMatrix = [
            [ 1,  2, -1,  7,  0],
            [-1,  2, -1,  7, -1],
            [-1,  2,  4,  3,  8],
            [-1,  2,  4, -1,  8],
            [ 5,  6, -1, -1, -1],
            [-1,  6, -1, -1, -1],
            [-1,  6, -1, -1,  8],
            [-1,  2, -1, -1, -1],
            [-1, -1, -1, -1,  8]]
        
    def isNumber(self, s):
        state = 0
        dotCount = 0
        for c in s:
            if c == '.': dotCount += 1
        if dotCount >= 2: return False
        charIndex = -1
        state = 0
        for c in s:
            charIndex = self.__getCharIndex(c)
            if charIndex == -1: return False
            state = self.__transitMatrix[state][charIndex]
            if state == -1: return False
            
        if state in [2, 3, 6, 8]: return True
        return False
    
    def __getCharIndex(self, c):
        if c == '+' or c == '-': return 0;
        if c >= '0' and c <= '9': return 1;
        if c == 'E' or c == 'e': return 2;
        if c == '.': return 3;
        if c == ' ': return 4;
        return -1;
