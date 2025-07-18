class TaskB:
    def solve(self, test_number, in_stream, out_stream):
        n = int(in_stream.readline())
        a = [list(in_stream.readline().strip()) for _ in range(n)]
        P, Q = 37, 47
        pow_p = [1] * (n + 1)
        pow_q = [1] * (n + 1)
        for i in range(1, n + 1):
            pow_p[i] = pow_p[i - 1] * P
            pow_q[i] = pow_q[i - 1] * Q

        hash_row = [[0] * n for _ in range(n)]
        hash_col = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    hash_row[i][k] += ord(a[i][j]) * pow_p[(j - k + n) % n]
                    hash_col[j][k] += ord(a[i][j]) * pow_p[(i - k + n) % n]

        ans = 0
        for A in range(n):
            for B in range(n):
                ok = True
                for i in range(n):
                    if hash_row[(i + A) % n][B] != hash_col[(i + B) % n][A]:
                        ok = False
                        break
                ans += 1 if ok else 0
        out_stream.write(f"{ans}\n")


def main():
    import sys
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = TaskB()
    solver.solve(1, in_stream, out_stream)


if __name__ == "__main__":
    main()  # End of Code
