# NIM/Nama  : 18219036/Zachrandika Alif Syahreza
# Tanggal   : 19 November 2020
# Deskripsi : program yang digunakan untuk menghitung total harga makanan

# Algoritma
n   = int(input())
sum = 0
for i in range (n):
    kode = int(input())
    if ((i+1)%2==1):
        sum = sum + kode*100
    else:
        sum = sum + kode*200
print(str(sum)+" rupiah")