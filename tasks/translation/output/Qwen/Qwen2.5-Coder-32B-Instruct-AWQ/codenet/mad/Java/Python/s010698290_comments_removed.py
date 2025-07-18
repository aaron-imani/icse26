import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read().split()
        self.index = 0

    def next(self):
        result = self.input[self.index]
        self.index += 1
        return result

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        result = ' '.join(self.input[self.index:])
        self.index = len(self.input)
        return result

def main():
    s = FastReader()
    n = s.nextInt()
    m = s.nextInt()

    penal = [0] * (n + 1)
    solved = [False] * (n + 1)

    for _ in range(m):
        num = s.nextInt()
        str_input = s.next()
        if str_input[0] == 'A':
            solved[num] = True
        else:
            if not solved[num]:
                penal[num] += 1

    correct_ans = 0
    num_penal = 0
    for i in range(1, n + 1):
        if solved[i]:
            correct_ans += 1
            num_penal += penal[i]

    print(correct_ans, num_penal)

if __name__ == "__main__":
    main()
# End of Code
