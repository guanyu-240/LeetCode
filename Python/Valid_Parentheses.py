class Solution:
    # @return a boolean
    def isValid(self, s):
        l = []
        for c in s:
            if c == '(' or c == '[' or c == '{': l.append(c)
            elif len(l) > 0 and l[-1] == self.match(c):
                l.pop(-1)
            else: return False
        if len(l) == 0: return True
        else: return False
            
    def match(self, c):
        if c == ')': return '('
        elif c == ']': return '['
        elif c == '}': return '{'
        else: return None
