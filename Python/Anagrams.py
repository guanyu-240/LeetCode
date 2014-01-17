class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        strMap = {}
        for s in strs:
            ss = ''.join(sorted(s))
            anagrams = strMap.get(ss)
            if anagrams == None:
                anagrams = [s]
                strMap[ss] = anagrams
            else: anagrams.append(s)
        
        ret = []
        for k, v in strMap.items():
            if len(v) >= 2:
                for s in v: ret.append(s)
        return ret
