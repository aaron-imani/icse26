import sys
def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1
    m = int(data[idx]); idx += 1

    solved = [False] * (n + 1)
    penalties = [0] * (n + 1)

    for _ in range(m):
        problem = int(data[idx]); idx += 1
        status = data[idx]; idx += 1

        if status[0] == 'A':
            solved[problem] = True
        else:
            if not solved[problem]:
                penalties[problem] += 1

    correct = 0
    total_penalty = 0
    for i in range(1, n+1):
        if solved[i]:
            correct += 1
            total_penalty += penalties[i]

    print(f"{correct} {total_penalty}")
if __name__ == "__main__":
    main()
# End of Code
