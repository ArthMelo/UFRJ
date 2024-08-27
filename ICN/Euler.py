import math

def euler(n):
    e = 0
    for k in range(0, n):
        e = e + (1/math.factorial(k))
    print(f"Euler eh {e} para n = {n}")

euler(20)
euler(50)
euler(100)
euler(1000)

def fatorial(k):
    if k == 0 or k == 1:
        return 1
    else:
        return (k*(fatorial(k-1)))

def novoEuler(n):
    e = 0
    for k in range(0, n):
        e = e + (1/fatorial(k))
    print(f"Euler eh {e} para n = {n}")

novoEuler(20)
novoEuler(50)
novoEuler(100)
novoEuler(1000)


