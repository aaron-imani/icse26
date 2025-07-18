import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    penal = [0] * (n + 1)
    solved = [False] * (n + 1)
    
    for _ in range(m):
        parts = sys.stdin.readline().split()
        num = int(parts[0])
        action = parts[1]
        if action == 'A':
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
    main()
# End of Code
