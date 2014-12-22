// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int remain = 0;
    int len = 0;
    char tmp[5];
    bool endOfFile= false;
    int read(char *buf, int n) {
        int ret = 0, r = 0;
        if (remain > 0) {                      // Bytes from previous read
            r = min(n, remain);
            memcpy(buf, tmp+(len-remain), r);
            remain -= r;
            ret += r;
            buf += r;
        }
        while (ret < n && !endOfFile) {        // requires bytes from file
            len = read4(tmp);
            if (len < 4) endOfFile = true;
            r = min(len, n-ret);
            memcpy(buf, tmp, r);
            remain = len - r;
            buf += r;
            ret += r;
        }
        return ret;
    }
};
