import sys

def main():
    lines = sys.stdin.read().splitlines()
    N = int(lines[0])
    arr = list(map(int, lines[1].split()))
    max_val = 0
    output = 
    for num in arr:
        if num >= max_val:
            max_val = num
            output += 1
    print(output)

if __name__ == "__main__":
    main()
// End of Code
