class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        assert target >= 0
        combs = [[] for i in range(target+1)]
        cands = sorted(candidates)
        n = len(cands)
        for i in range(n):
            if cands[i] <= target: combs[cands[i]].append([cands[i], i])
        for i in range(1, target+1):
            if (len(combs[i])) == 0: continue
            for comb in combs[i]:
                k = comb[-1]
                for j in range(k, n):
                    if i + cands[j] <= target:
                        newComb = comb[:-1]
                        newComb.append(cands[j])
                        newComb.append(j)
                        combs[i+cands[j]].append(newComb)
                    else: break
        ret = combs[target]
        for i in range(len(ret)):
            ret[i] = ret[i][:-1]
        return ret
