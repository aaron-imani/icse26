class InputReader:
    def __init__(self, stream):
        self.reader = BufferedReader(InputStreamReader(stream), 32768)
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())


def solve(sc, pw):
    t = 1
    while t > 0:
        n = sc.nextLong()
        m = sc.nextLong()
        if n == 0:
            pw.write(str(0) + '\n')
            continue
        if n == m:
            pw.write(str(0) + '\n')
            continue
        if n > m:
            n = m + n % m
            n -= m
            pw.write(str(min(m - n, n)) + '\n')
            continue
        pw.write(str(min(m - n, n)) + '\n')


def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = output_stream
    solve(in_reader, out_writer)
    out_writer.flush()


if __name__ == "__main__":
    main()  # End of Code
