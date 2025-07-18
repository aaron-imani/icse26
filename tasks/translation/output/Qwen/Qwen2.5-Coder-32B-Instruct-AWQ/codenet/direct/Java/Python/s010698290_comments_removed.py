import sys

class FastReader:
    def __init__(self):
        self.buffer = sys.stdin.read().splitlines()
        self.index = 0

    def next(self):
        while self.index < len(self.buffer) and not self.buffer[self.index].strip():
            self.index += 1
        if self.index >= len(self.buffer):
            return None
        token = self.buffer[self.index].split()
        if len(token) == 0:
            self.index += 1
            return self.next()
        ret = token[0]
        self.buffer[self.index] = ' '.join(token[1:])
        return ret

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        if self.index >= len(self.buffer):
            return None
        ret = self.buffer[self.index]
        self.index += 1
        return ret

def main():
    s = FastReader()
    n = s.nextInt()
    m = s.nextInt()

    penal = [0] * (n + 1)
    solved = [False] * (n + 1)

    for _ in range(m):
        num = s.nextInt()
        str_input = s.next()
        if str_input == 'A':
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
