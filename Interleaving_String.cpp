class Solution {
public:
    /*
        s1 = c1i(1<=i<=len1)
        s2 = c2j(1<=j<=1len2)
        s3 is the interleave of the two
        For example:
        s3 = c11,c12,c21,c13,c14,c15,c22......
        In this case s3[7] = c22
        s3[0, 7] is formed by interleaving of s1[0, 5] and s2[0, 2]
        s3[0, 6] is formed by interleaving of s1[0, 5] and s2[0, 1] 
        We get this:
        For each (i, j) pair,
        s3[0, i+j] is formed by interleaving of s1[0, i] and s2[0, j]
        When:
        s3[0, i+j-1] is formed by interleaving of s1[0, i-1] and s2[0,j](s3[i+j] = s1[i])
        or
        s3[1, i+j-1] is formed by interleaving of s1[0, i] and s2[0,j-1](s3[i+j] = s2[j])
        Therefore we define a matching table match[len1 + 1][len2 + 1]
        match[i][j] indicates that s3[i + j] matches s1[i] and s2[j]
    */
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3){
            return false;
        }
        int i, j, up, left;
        bool match[len1 + 1][len2 + 1];
        for (i = 0; i <= len1; i ++){
            for (j = 0; j <= len2; j++){
                match[i][j] = false;
            }
        }
        match[0][0] = true;
        for (int n = 1; n <= len3; n ++){
            i = 0;
            while (i <= min(n, len1)){
                j = n - i;
                if (j > len2){
                    i++;
                    continue;
                }
                up = i - 1;
                left = j - 1;
                if (up >= 0 && match[up][j] == true && s1[i-1] == s3[n-1]){
                    match[i][j] = true;
                }
                if (left >= 0 && match[i][left] == true && s2[j-1] == s3[n-1]){
                    match[i][j] = true;
                }
                i++;
            }
        }
        return match[len1][len2];
    }
};
