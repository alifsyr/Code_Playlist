#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum nilai ekstrim
#Deskripsi  mencari nilai ekstrim

N = int(input())
arr = [int(input()) for i in range(N)]
X = int(input())
maximum = 0
minimum = 0

found = False
for i in range (N):
    if arr[i] == X:
        found = True
        if ((X == max(arr)) and (X==min(arr))):
            maximum = X
            minimum = X
        elif (X == max(arr)):
            maximum = X
        elif (X == min(arr)):
            minimum = X

if ((X == maximum) and (X==minimum)):
    print("maksimum")
    print("minimum")
elif (X == maximum):
    print("maksimum")
elif (X == minimum):
    print("minimum")
elif (found == False):
    print(str(X)+"tidak ada")
else:
    print("N#A")



