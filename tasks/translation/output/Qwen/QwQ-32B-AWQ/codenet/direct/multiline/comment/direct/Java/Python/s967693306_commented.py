import sys

def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    pos_to_digit = {}

    for _ in range(m):
        s, c = map(int, sys.stdin.readline().split())
        if s in pos_to_digit:
            if pos_to_digit[s] != c:
                print(-1)
                return
        else:
            pos_to_digit[s] = c

    for num_candidate in range(0, 1000):
        s = str(num_candidate)
        if len(s) != n:
            continue
        valid = True
        for j in range(n):
            current_digit = int(s[j])
            pos = j + 1
            required = pos_to_digit.get(pos)
            if required is not None:
                if current_digit != required:
                    valid = False
                    break
            else:
                if j == 0 and current_digit == 1:
                    continue  # allowed
                else:
                    if current_digit != 0:
                        valid = False
                        break
        if valid:
            print(s)
            return
    print(-1)

if __name__ == "__main__":
    main()
# End of Code
