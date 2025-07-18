import sys

class Solution:
    def __init__(self):
        import sys
        for line in sys.stdin:
            line = line.strip()
            if not line:
                continue
            self.run_case(line)
    
    def run_case(self, line):
        parts = line.split()
        N = int(parts[0])
        K = int(parts[1])
        length = 0
        while N > 0:
            N = N // K
            length += 1
        print(length)

if __name__ == "__main__":
    Solution()
# End of Code
