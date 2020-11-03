#NIM    18219001
#Nama   Dimas Farhan Anshari
#Tanggal   22/10/2020
#Topik praktikum Max 3 bilangan
#Deskripsi  Menghitung max dari 3 input bilangan

X = int(input())
Y = int(input())
Z = int(input())

def max3bil(X,Y,Z):
    if (X >= Y) and (X >= Z):
        return X
    elif (Y >= X) and (Y >= Z):
        return Y
    else:
        return Z
print(max3bil(X,Y,Z))