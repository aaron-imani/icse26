import sys

class Scanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.tokens = []
        self.token_index = 0

    def next(self):
        if self.token_index == len(self.tokens):
            self.tokens = self.in_stream.readline().split()
            self.token_index = 0
        current_token = self.tokens[self.token_index]
        self.token_index += 1
        return current_token

    def close(self):
        self.in_stream.close()


class Printer:
    def __init__(self, out):
        self.out = out

    def println(self, value):
        print(value, file=self.out)

    def close(self):
        self.out.close()


def solve(sc, pr):
    n = int(sc.next())
    k = int(sc.next())

    a = [int(sc.next()) for _ in range(n)]

    cumsum = [0] * (n + 1)
    for i in range(n):
        cumsum[i + 1] = cumsum[i] + a[i]

    b = []
    max_val = 0
    for i in range(n):
        for j in range(i, n):
            val = cumsum[j + 1] - cumsum[i]
            b.append(val)
            max_val = max(max_val, val)

    mask = 1 << (max_val.bit_length() - 1)
    while mask > 0:
        tmp = [e for e in b if (e & mask) != 0]
        if len(tmp) >= k:
            b = tmp
        mask >>= 1

    if len(b) < k:
        pr.println(0)
    else:
        ans = -1
        for e in b:
            ans &= e
        pr.println(ans)


def main():
    sc = Scanner(sys.stdin)
    pr = Printer(sys.stdout)
    solve(sc, pr)
    pr.close()
    sc.close()


if __name__ == "__main__":
    main()
# End of Code
