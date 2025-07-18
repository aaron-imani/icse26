import sys

def main():
    class FastScanner:
        def __init__(self, stream):
            self.stream = stream
            self.buf = ''
            self.ptr = 0

        def next(self):
            while self.ptr >= len(self.buf):
                self.buf = self.stream.readline()
                if not self.buf:
                    return None
                self.ptr = 0
            start = self.ptr
            while self.ptr < len(self.buf) and self.buf[self.ptr] not in ' \n':
                self.ptr += 1
            res = self.buf[start:self.ptr]
            self.ptr += 1
            return res

        def nextInt(self):
            return int(self.next())

    sc = FastScanner(sys.stdin)
    n = sc.nextInt()
    m = sc.nextInt()

    condition = {}
    for _ in range(m):
        s = sc.nextInt()
        c = sc.nextInt()
        if s in condition:
            if condition[s] != c:
                print(-1)
                return
        condition[s] = c

    for i in range(1000):
        s = str(i)
        if len(s) != n:
            continue
        valid = True
        for j in range(n):
            pos = j + 1
            digit = int(s[j])
            required = condition.get(pos)
            if required is not None:
                if digit != required:
                    valid = False
                    break
            else:
                if digit != 0:
                    if j == 0 and digit == 1:
                        continue
                    else:
                        valid = False
                        break
        if valid:
            print(s)
            return
    print(-1)

if __name__ == "__main__":
    main()
# End of Code
