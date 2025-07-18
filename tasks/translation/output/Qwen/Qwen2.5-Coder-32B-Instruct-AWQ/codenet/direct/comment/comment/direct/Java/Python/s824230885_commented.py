import sys

def solve():
    input = sys.stdin.read().split()
    N = int(input[0])
    list = [int(x) for x in input[1:]]
    max_val = 0
    output = 0
    for i in range(N):
        if max_val <= list[i]:
            max_val = list[i]
            output += 1
    print(output)

if __name__ == "__main__":
    solve()
# End of Code
