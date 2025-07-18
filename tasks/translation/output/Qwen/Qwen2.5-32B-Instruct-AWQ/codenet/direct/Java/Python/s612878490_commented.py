import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    index += 1
    M = int(data[index])
    index += 1
    
    shortage = []
    
    for i in range(M):
        A = int(data[index])
        index += 1
        shortage.append(max(0, N - A))
    
    shortage.sort()
    
    ans = sum(shortage[:-1])
    
    print(ans)

if __name__ == "__main__":
    main()  # End of Code
