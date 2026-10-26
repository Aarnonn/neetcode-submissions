class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        s = s.lower()
        idx1 = 0
        idx2 = len(s)-1
        while idx1 <= idx2:
            print(f"{idx1}")
            if s[idx1] != s[idx2]:
                print(f"{s[idx1]}, {s[idx2]}")
                return False
            else:
                idx1+=1
                idx2-=1
        return True