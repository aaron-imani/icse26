import sys
import io

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(sys.stdin.buffer.read())
        self.line = self.buffer.readline().decode().strip()
        self.tokens = self.line.split()
        self.index = 0

    def next(self):
        if self.index >= len(self.tokens):
            self.line = self.buffer.readline().decode().strip()
            self.tokens = self.line.split()
            self.index = 0
        token = self.tokens[self.index]
        self.index += 1
        return token

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        self.line = self.buffer.readline().decode().strip()
        self.tokens = self.line.split()
        self.index = 0
        return self.line

def main():
    try:
        s = FastReader()
        n = s.nextInt()
        m = s.nextInt()

        penal = [0] * (n + 1)
        solved = [False] * (n + 1)

        for i in range(m):
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

        print(f"{correct_ans} {num_penal}")

    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()
# End of Code
