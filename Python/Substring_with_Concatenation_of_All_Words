class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        expected = {}
        for s in L:
            count = expected.get(s)
            if count == None: count = 1
            else: count = count + 1
            expected[s] = count
        
        ret = []
        n = len(S)
        if len(L) == 0: return ret
        k = len(L[0])
        substrLen = len(L)*k
        if n < substrLen or substrLen == 0: return ret
        
        for i in range(n-substrLen+1):
            appeared = {}
            valid = True
            for j in range(i, i+substrLen, k):
                s = S[j: j+k]
                ce = expected.get(s)
                if ce == None:
                    valid = False
                    break
                ca = appeared.get(s)
                if ca == None: ca = 1
                elif ca < ce: ca = ca + 1
                else:
                    valid = False
                    break
                appeared[s] = ca
            if valid: ret.append(i)
        return ret
