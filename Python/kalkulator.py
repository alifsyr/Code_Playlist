def kalkulator(n):
    if (n==0):
        return 0
    else:
        return (kalkulator(n/5) + (n%5))

print(kalkulator(2903))