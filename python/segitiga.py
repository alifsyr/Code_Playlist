# NIM/Nama  : 18219036/Zachrandika Alif Syahreza
# Tanggal   : 5 November 2020
# Deskripsi : program yang digunakan untuk menghitung luas segitiga

# Algoritma
alas, tinggi = input().split()
alas = int(alas)
tinggi = int(tinggi)

if (alas>0 and tinggi>0):
    luas = 0.5 * alas * tinggi
    print(int(round(luas)))
else: 
    print("Alas dan tinggi harus > 0")
