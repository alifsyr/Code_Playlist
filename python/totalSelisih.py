# NIM/Nama : 16519080/Zachrandika Alif Syahreza
# Tanggal : 8 april 2020
# Deskripsi : menghitung total selisih dari daftar angka – angka yang dimasukkan

# Kamus
# N, A, B, sum = integer

#ALGORITMA
N=int(input())
A=int(input())
sum = 0
if (N == 1):
    print(sum)
else:
    N -= 1
    while (N != 0):
        B=int(input())
        sum += abs(A-B)
        A = B
        N -= 1
    print(sum)
