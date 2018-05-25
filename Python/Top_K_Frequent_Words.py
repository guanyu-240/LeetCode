class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        word_count = collections.Counter(words)
        top_k = heapq.nsmallest(k, word_count.iteritems(), key=lambda (w, c): (-c, w))
        top_k = map(lambda x: x[0], top_k)
        return top_k
        
