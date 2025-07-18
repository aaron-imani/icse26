class FastReader:
    def __init__(self):
        self.st = []
        self.br = iter(sys.stdin.read().split())

    def next(self):
        if not self.st:
            self.st = next(self.br).split()
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return next(self.br)


import sys

if __name__ == "__main__":
    try:
        s = FastReader()
        n = s.nextInt()
        m = s.nextInt()

        penal = [0] * (n + 1)
        solved = [False] * (n + 1)

        for i in range(m):
            num = s.nextInt()
            str = s.next()
            if str[0] == 'A':
                solved[num] = True
            elif not solved[num]:
                penal[num] += 1

        correct_ans = 0
        num_penal = 0
        for i in range(1, n + 1):
            if solved[i]:
                correct_ans += 1
                num_penal += penal[i]

        print(f"{correct_ans} {num_penal}")
    except Exception as e:
        print(e)

# End of Code
