class Main:
    def solve(self):
        n = int(input())
        m = int(input())
        pos_map = {}
        conflict = False
        for _ in range(m):
            s = int(input())
            c = int(input())
            if s in pos_map:
                if pos_map[s] != c:
                    conflict = True
                    break
            pos_map[s] = c
        if conflict:
            print(-1)
            return
        for i in range(1000):
            s_candidate = str(i)
            if len(s_candidate) != n:
                continue
            valid = True
            for j in range(n):
                current_digit = int(s_candidate[j])
                required = pos_map.get(j+1)
                if required is not None:
                    if current_digit != required:
                        valid = False
                        break
                else:
                    if current_digit != 0:
                        if j == 0 and current_digit == 1:
                            pass
                        else:
                            valid = False
                            break
            if valid:
                print(s_candidate)
                return
        print(-1)

if __name__ == "__main__":
    Main().solve()
# End of Code
