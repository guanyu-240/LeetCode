class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        c_sets = [set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")]
        return filter(lambda w: any([set(w.lower()) <= s for s in c_sets]), words)
