class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        assert target > 0
        cands = sorted(candidates)
        n = len(cands)
        combs = [[] for i in range(target+1)]
        for i in range(n):
            if not ((i > 0 and cands[i] == cands[i-1]) or (cands[i] > target)):
                combs[cands[i]].append([cands[i], i])
        for i in range(1, target+1):
            for comb in combs[i]:
                k = comb[-1]
                for j in range(k+1, n):
                    if cands[j] + i > target: break
                    if j > k+1 and cands[j] == cands[j-1]: continue
                    newComb = comb[:-1]
                    newComb.append(cands[j])
                    newComb.append(j)
                    combs[i+cands[j]].append(newComb)
        ret = combs[target]            
        for i in range(len(ret)):
            ret[i] = ret[i][:-1]
        return ret
