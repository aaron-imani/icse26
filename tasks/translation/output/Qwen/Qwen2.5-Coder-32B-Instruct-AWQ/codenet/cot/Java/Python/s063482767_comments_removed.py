import sys

def main():
    n = int(input())
    queue = []
    for _ in range(n):
        queue.append(int(input()))
    queue.sort()
    sum_of_elements = sum(queue[:-1])
    print("Yes" if queue[-1] < sum_of_elements else "No")

if __name__ == "__main__":
    main()
# End of Code
