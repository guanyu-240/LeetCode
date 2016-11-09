class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        char_count = {}
        for c in s:
            if c in char_count: char_count[c] += 1
            else: char_count[c] = 1
        sorted_char_count = sorted(char_count.items(), key=lambda x: x[1], reverse=True)
        ret = ""
        for count_entry in sorted_char_count:
            ret += count_entry[1]*count_entry[0]
        return ret
