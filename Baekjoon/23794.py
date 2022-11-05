import sys
input=sys.stdin.readline

N = int(input())

for i in range(N+2):
    if i == 0 or i == N+1 :
        for _ in range(N+2) :
            print("@", end="")
        print()
    else:
        print("@", end="")
        
        for _ in range(N) :
            print(" ", end="")
        print("@")
