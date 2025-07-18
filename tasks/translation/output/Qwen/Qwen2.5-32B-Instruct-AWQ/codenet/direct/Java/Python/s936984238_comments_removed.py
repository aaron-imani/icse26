import sys

def main():
    sc = Scanner()
    
    while read(sc):
        solve()

def read(sc):
    number = sc.nextInt()
    if number == 0:
        return False
    
    score = [sc.nextInt() for _ in range(number)]
    global scores
    scores = score
    return True

def solve():
    scores.sort()
    sum = 0
    for i in range(1, len(scores) - 1):
        sum += scores[i]
    print(sum // (len(scores) - 2))

class Scanner:
    def __init__(self):
        self.tokens = []
        self.token_index = 0
        self.input = sys.stdin

    def nextInt(self):
        if self.token_index == len(self.tokens):
            self.tokens = self.input.readline().strip().split()
            self.token_index = 0
        token = self.tokens[self.token_index]
        self.token_index += 1
        return int(token)

if __name__ == "__main__":
    main()  # End of Code
