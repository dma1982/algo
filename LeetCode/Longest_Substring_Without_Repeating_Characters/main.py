class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        idx = [];
        max_len = 0;
        str_len = len(s);

        for i, c in enumerate(s):
            found = False;
            for j, cc in enumerate(s[i+1:]):
                if (c == cc):
                    idx.append(j + i + 1);
                    found = True;
                    break;
            if (not found):
                idx.append(str_len);

        for i, j in enumerate(idx):
            cur_len = j;
            cur_idx = i + 1;
            cur_max = 0;
            while (cur_idx < cur_len):
                cur_len = min (cur_len, idx[cur_idx]);
                cur_idx = cur_idx + 1;
                cur_max = cur_max + 1;
            max_len = max (cur_max, max_len);

        return max_len + 1;

if __name__ == "__main__":
    sln = Solution();
    print sln.lengthOfLongestSubstring("abcabcbb");
    print sln.lengthOfLongestSubstring("bbbbb");
    print sln.lengthOfLongestSubstring("hchzvfrkmlnozjk");
