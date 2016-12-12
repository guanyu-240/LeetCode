class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if self.validateIPV4(IP): return 'IPv4'
        elif self.validateIPV6(IP): return 'IPv6'
        else: return 'Neither'
        
    def validateIPV4(self, IP):
        split = IP.split('.')
        if len(split) != 4: return False
        for x in split:
            if len(x) <= 0 or len(x) > 3: return False
            num = 0
            for d in x:
                if d < '0' and d > '9': return False
                elif d == '0' and len(x) > 1: return False
                else: num = num*10 + ord(d)-ord('0')
            if num > 255: return False
        return True

    def validateIPV6(self, IP):
        split = IP.split(':')
        if len(split) != 8: return False
        valid_chars = set("0123456789abcdefABCDEF")
        for x in split:
            if len(x) <= 0 or len(x) > 4: return False
            for d in x:
                if d not in valid_chars: return False
        return True
