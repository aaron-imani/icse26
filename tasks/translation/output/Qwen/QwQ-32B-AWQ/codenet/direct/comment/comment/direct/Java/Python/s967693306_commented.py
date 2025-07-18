import sys

def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    d = {}
    for _ in range(m):
        parts = sys.stdin.readline().split()
        s = int(parts[0])
        c = int(parts[1])
        if s in d:
            if d[s] != c:
                print(-1)
                return
        else:
            d[s] = c
    found = False
    for i in range(0, 1000):
        s_str = str(i)
        if len(s_str) < n:
            continue
        if len(s_str) != n:
            continue
        flag = True
        for j in range(n):
            pos = j + 1
            current_digit = int(s_str[j])
            if pos in d:
                if current_digit != d[pos]:
                    flag = False
                    break
            else:
                if j == 0:
                    if current_digit !=  dagen = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    d = {}
    for _ in range(m):
        parts = sys.stdin.readline().split()
        s = int(parts[0])
        c = int(parts[1])
        if s in d:
            if d[s] != c:
                print(-1)
                return
        else:
            d[s] = c
    found = False
    for i in range(0, 1000):
        s_str = str(i)
        if len(s_str) < n:
            continue
        if len(s_str) != n:
            continue
        flag = True
        for j in range(n):
            pos = j + 1
            current_digit = int(s_str[j])
            if pos in d:
                if current_digit != d[pos]:
                    flag = False
                    break
            else:
                if j == 0:
                    if current_digit != 1:
                        flag = False
                        break
                else:
                    if current_digit != 0:
                        flag = False
                        break
        if flag:
            print(s_str)
            return
    print(-1)

if __name__ == "__main__":
    main() # End of Code
