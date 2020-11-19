# NIM/Nama  : 18219036/Zachrandika Alif Syahreza
# Tanggal   : 12 November 2020
# Deskripsi : program yang digunakan untuk membaca masukan berat tubuh mahasiswa (dalam bentuk angka) dalam suatu kelas, sampai pengguna mengetikkan -999 (-999 tidak termasuk nilai yang diproses).

# Algoritma
count           = 0
golongan_1      = 0
golongan_2      = 0
jumlah          = 0

berat = int(input())
while (berat != -999):
    if (berat >= 30 and berat <= 200):
        count += 1
        jumlah += berat
        if (berat >= 100):
            golongan_1 += 1

        elif (berat <= 50):
            golongan_2 += 1

        berat = int(input())

    else:
        berat = int(input())

if (count == 0):
    print ("Data kosong")
else:
    print(count)
    print(golongan_2)
    print(golongan_1)
    avg = jumlah/count
    print((round(avg)))