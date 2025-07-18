# Python translation of the provided Java code

import sys

class FastReader:
    def __init__(self):
        self.br = sys.stdin
        self.st = None

    def next(self):
        while self.st == None or not self.st:
            try:
                self.st = self.br.readline().strip().split()
            except Exception as e:
                print(e)
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        try:
            return self.br.readline().strip()
        except Exception as e:
            print(e)


def main():
    fr = FastReader()
    n = fr.next_int()
    m = fr.next_int()

    penal = [0] * (n + 1)
    solved = [False] * (n + 1)

    for _ in range(m):
        num = fr.next_int()
        str_input = fr.next()
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

if __name__ == "__main__":
    main()  # End of Code
