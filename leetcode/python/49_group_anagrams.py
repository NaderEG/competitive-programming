class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        my_dict = {}
        for word in strs:
            if ''.join(sorted(word)) in my_dict:
                my_dict[''.join(sorted(word))].append(word)
            else:
                my_dict[''.join(sorted(word))] = [word]

        result = []
        for key in my_dict:
            result.append(my_dict[key])
        return result