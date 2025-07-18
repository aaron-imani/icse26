import sys

def main():
    sc = Scanner()
    while read(sc):
        solve()

def read(sc):
    number = sc.nextInt()
    if number == 0:
        return False
    global score
    score = [sc.nextInt() for _ in range(number)]
    return True

def solve():
    score.sort()
    sum = 0
    for i in range(1, len(score) - 1):
        sum += score[i]
    print(sum // (len(score) - 2))

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
