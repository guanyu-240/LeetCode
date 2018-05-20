class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        punctuation_symbols = "!?',;."
        word_count = {}
        banned_words = set(banned)
        max_count = 0
        most_common_word = None
        for word in paragraph.split():
            word = word.strip(punctuation_symbols).lower()
            if word in banned_words:
                continue
            if word in word_count:
                count = word_count[word] + 1
            else:
                count = 1
            if count > max_count:
                max_count = count
                most_common_word = word
            word_count[word] = count
        return most_common_word
