# NIM/Nama : 16519080/Zachrandika Alif Syahreza
# Tanggal : 5 November 2019
# Deskripsi : program yang menerima masukan N dan menuliskan matriks segitiga pascal berukuran N×N

# Kamus:
# n = integer
# matriks = matriks integer dengan besar n X n

# Algoritma:
n = int(input('Masukan N: '))# user diminta memasukan besarnya N
matriks = [[1 for j in range (n)] for i in range (n)]# matriks mulanya diinisialisasi dengan baris pertama 1 dan semua nilai kolom 1
for i in range (1,n):# looping untuk mengisi matriks sebesar n baris
    for j in range (1,n):# looping untuk mengisi matriks sebesar n kolom
        matriks[i][j] = matriks[i-1][j] + matriks [i][j-1]# program untuk membuat matriks segitiga pascal
for i in range (n):
    for j in range (n):
        print (matriks[i][j], end= ' ')
    print()