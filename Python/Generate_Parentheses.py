class Solution:
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        cands = [["", 0]]
        newCands = []
        for i in range(2*n):
            for cand in cands:
                s = cand[0]
                countLeft = cand[1]
                countRight = i - countLeft
                if countLeft > countRight:
                    newCands.append([s+')', countLeft])
                    if countLeft < n:
                        newCands.append([s+'(', countLeft+1])
                else:
                    newCands.append([s+'(', countLeft+1])
            cands = newCands
            newCands = []
        ret = []
        for cand in cands: ret.append(cand[0])
        return ret
