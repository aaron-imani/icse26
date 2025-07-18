class Main:
    def __init__(self):
        import sys
        self.tokens = iter(sys.stdin.read().split())
        
    def ni(self):
        return int(next(self.tokens))
    
    def solve(self):
        a = self.ni()
        b = self.ni()
        print(max(0, a - 2 * b))
        
if __name__ == "__main__":
    Main().solve() # End of Code
