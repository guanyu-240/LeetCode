class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    def __init__(self):
        self.__ret = []
        self.__allTheLetters = string.ascii_lowercase
        self.__preds = {}
        
    def findLadders(self, start, end, dict):
        self.__ret = list()
        self.__preds.clear()
        for w in dict:
            self.__preds[w] = set()
        q = collections.deque()
        q.append(start)
        cands = set()
        endSearch = False
        while len(q) > 0:
            word = q.pop()
            wlist = list(word)
            n = len(word)
            for i in range(n):
                cc = wlist[i]
                for c in self.__allTheLetters:
                    wlist[i] = c
                    newWord = ''.join(wlist)
                    if newWord == end:
                        endSearch = True
                        self.__preds[newWord].add(word)
                    if not endSearch and newWord in dict:
                        cands.add(newWord)
                        self.__preds[newWord].add(word)
                wlist[i] = cc
            if len(q) == 0:
                if endSearch: break
                for cand in cands: 
                    q.append(cand)
                    dict.remove(cand)
                cands.clear()
        self.__genResults([end], start, end)
        return self.__ret
        
    def __genResults(self, result, start, end):
        if end == start:
            self.__ret.append(result[::-1])
            return
        preds = self.__preds.get(end)
        if preds == None: return
        for pred in preds:
            newResult = result[:]
            newResult.append(pred)
            self.__genResults(newResult, start, pred)
