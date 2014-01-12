class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        m = len(A)
        n = len(B)
        if (m+n)%2 == 0: 
            return (self.getKthNumber(A, B, (m+n)/2) + self.getKthNumber(A, B, (m+n)/2+1))/2.0
        else: 
            return self.getKthNumber(A, B, (m+n)/2+1)
        
    def getKthNumber(self, A, B, k):
        leftA = 0
        rightA = len(A)-1
        leftB = 0
        rightB = len(B)-1
        midA = 0
        midB = 0
        while leftA <= rightA or leftB <= rightB:
            if leftA > rightA: return B[leftB+k-1]
            if leftB > rightB: return A[leftA+k-1]
            if k <= 1: return min(A[leftA], B[leftB])
            midA = (leftA + rightA)/2
            midB = (leftB + rightB)/2
            if A[midA] < B[midB]:
                if (midA-leftA+1) + (midB-leftB+1) > k:
                    rightB = midB - 1;
                else:
                    k = k - (midA-leftA+1)
                    leftA = midA + 1
            else:
                if (midA-leftA+1) + (midB-leftB+1) > k:
                    rightA = midA - 1;
                else:
                    k = k - (midB-leftB+1)
                    leftB = midB + 1
        return None
