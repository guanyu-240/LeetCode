class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        fs_len = []
        level_prev,level_cur = -1,0
        is_file = False
        i,j = 0,0
        len_names = 0
        ret = 0
        while j <= len(input):
            if j == len(input) or input[j] == '\n':
                # start processing the file/dir names
                if level_cur <= level_prev:
                    while level_cur < level_prev:
                        len_names -= fs_len[level_prev]
                        fs_len.pop()
                        level_prev -= 1
                    len_names = len_names-fs_len[level_cur]+j-i
                    fs_len[level_cur] = j-i
                else:
                    while level_prev < level_cur-1:
                        fs_len.append(0)
                        level_prev += 1
                    level_prev += 1
                    fs_len.append(j-i)
                    len_names += j-i
                if is_file:
                    ret = max(ret, len_names+level_cur)
                if j == len(input): break
                # start determining the level of the next file/dir name
                i = j + 1
                level_cur = 0
                while input[i] == '\t':
                    i += 1
                    level_cur += 1
                j = i
                is_file = False
            else:
                if input[j] == ".": is_file = True
                j += 1
        return ret
