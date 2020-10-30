# NIM/Nama : 16519081/ Akifa Nabil Ufairah
# Hari/Tanggal : Rabu/1 April 2020
# Deskripsi : Python - Skema standar

# Program Cari Character
# Input: N : integer (Dilakukan validasi hingga 0<N<=100)
#            Lalu menerima input sebanyak N buah character
#       : CC : character
# Output: Mengeluarkan output sesuai dengan input CC dan input character yang dimasukkan

# KAMUS
# Variabel
#    N,i : integer
#    A : Array [0..N-1] of character
#    CC : character
#    founds, foundl, foundx : boolean

# ALGORITMA PROGRAM UTAMA
N = int(input(""))
# Validasi Input hingga diperoleh input yang sesuai
while N<=0 or N>100:
    print("Masukan salah. Ulangi!")
    N = int(input(""))

# Deklarasi Array untuk menyimpan inputan N buah character
A = ['' for i in range(N)]
# Mengisi Array A
for i in range(N):
    A[i] = input("")
#Meminta input sebuah character CC
CC = input("")
if CC == 'S' or CC == 's':
    founds = False
    for i in range (N):
        if founds == False and 97<=ord(A[i])<=122:
            founds = True
            print(i+1,A[i])
    if founds == False:
        print("Tidak ada huruf kecil")
elif CC == 'L' or CC == 'l':
    foundl = False
    for i in range(N):
        if foundl == False and 65<=ord(A[i])<=90:
            foundl = True
            print(i+1,A[i])
    if foundl == False:
        print("Tidak ada huruf besar")
elif CC == 'X' or CC == 'x':
    foundx = False
    for i in range(N):
        if foundx == False and not(65<=ord(A[i])<=90) and not(97<=ord(A[i])<=122):
            foundx = True
            print(i+1, A[i])
    if foundx == False:
        print("Semua huruf")
else:
    print("Tidak diproses")