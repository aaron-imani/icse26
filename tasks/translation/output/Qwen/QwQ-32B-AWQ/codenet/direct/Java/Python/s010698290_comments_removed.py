import sys

def main():
    data = sys.stdin.read().split()
    ptr = 0
    n = int(data[ptr]); ptr +=1
    m = int(data[ptr]); ptr +=1

    penal = [0]*(n+1)
    solved = [False]*(n+1)

    for _ in range(m):
        num = int(data[ptr]); ptr +=1
        str_action = data[ptr]; ptr +=1
        if str_action[0] == 'A':
            solved[num] = True
        else:
            if not solved[num]:
                penal[num] +=1

    correct_ans = sum(1 for i in range(1, n+1) if solved[i])
    num_penal = sum(penal[i] for i in range(1, n+1) if solved[i])

    print(f"{correct_ans} {num_penal}")

if __name__ == "__main__":
    main() # End of Code
