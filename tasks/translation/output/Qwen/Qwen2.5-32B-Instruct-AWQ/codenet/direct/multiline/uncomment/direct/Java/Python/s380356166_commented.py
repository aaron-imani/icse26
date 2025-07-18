class Solver:
    def solve(self, test_number, in_stream, out_stream):
        ans = 0
        K = in_stream.nextInt()
        S = in_stream.nextInt()
        wk = 0
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if 0 <= wk <= K:
                    ans += 1
        out_stream.write(f"{ans}\n")

class MyInput:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def nextInt(self):
        return int(self.input_stream.readline().strip())

class MyOutput:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def write(self, text):
        self.output_stream.write(text)

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    my_input = MyInput(input_stream)
    out = MyOutput(output_stream)
    solver = Solver()
    solver.solve(1, my_input, out)
    output_stream.flush()

if __name__ == "__main__":
    import sys
    main()  # End of Code
