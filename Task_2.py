from math import log, gcd #gcd - НОД

prime_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127]

def Pollard(n: int, B:int):
    M = 1
    for p in prime_list:
        if p > B:
            break
        M = M * p**int(log(B)/log(p))
    aM = pow(2, M, n)
    g = gcd(aM-1, n)
    if 1 < g < n:
        return g
    return 1

n = int(input())
N = int(input())
print(Pollard(n,N))    