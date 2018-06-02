class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        subdomain_cnt = {}
        for cpdomain in cpdomains:
            splits = cpdomain.split();
            if len(splits) != 2: continue
            domain, cnt = splits[1], int(splits[0])
            start = 0
            while True:
                subdomain = domain[start:]
                if subdomain in subdomain_cnt:
                    subdomain_cnt[subdomain] += cnt
                else:
                    subdomain_cnt[subdomain] = cnt
                start = domain.find(".", start) + 1
                if start <= 0: break
                    
        return ["{} {}".format(v, k) for k,v in subdomain_cnt.iteritems()]
