class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            ss = ''.join(sorted(s))
            if ss in d:
                d[ss] += [s]
            else:
                d[ss] = [s]
        l = []
        for k, v in d.items():
            l.append(v)
        return l