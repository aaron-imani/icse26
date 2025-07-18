import sys
from collections import defaultdict, deque

class Solver:
    def __init__(self, input_stream, output_stream):
        self.input = input_stream
        self.output = output_stream

    def solve(self):
        H = int(next(self.input))
        W = int(next(self.input))
        C = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
        
        for i in range(H):
            line = next(self.input).strip()
            for j in range(W):
                C[i + 1][j + 1] = line[j]
                
        if H == 1 and W == 1:
            self.output.write("No\n")
            return
        
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i-1][j] != '#' and C[i+1][j] != '#' and C[i][j-1] != '#' and C[i][j+1] != '#':
                    self.output.write("No\n")
                    return
                    
        self.output.write("Yes\n")

def main():
    input_stream = iter(sys.stdin.readline, '')
    output_stream = sys.stdout
    solver = Solver(input_stream, output_stream)
    solver.solve()

if __name__ == "__main__":
    main()  # End of Code
