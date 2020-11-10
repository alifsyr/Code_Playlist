# NIM/Nama  : 18219036/Zachrandika Alif Syahreza
# Tanggal   : 5 November 2020
# Deskripsi : program yang digunakan untuk membaca masukan sejumlah data gaji pegawai (dalam ratusan ribu rupiah) di sebuah perusahaan, sampai pengguna mengetikkan -9999 (-9999 tidak termasuk nilai yang diproses)

# Algoritma
count       = 0
golongan_1  = 0
golongan_2  = 0
golongan_3  = 0
jumlah         = 0

gaji = int(input())
while (gaji != -9999):
    if (gaji >= 500):
        count += 1
        if (gaji > 5000):
            golongan_1 += 1
            jumlah = jumlah + gaji
            gaji = int(input())
        elif (gaji > 2000 and gaji <= 5000):
            golongan_2 += 1
            jumlah = jumlah + gaji
            gaji = int(input())
        else:
            golongan_3 += 1
            jumlah = jumlah + gaji
            gaji = int(input())
    else:
        gaji = int(input())

if (count == 0):
    print ("Data kosong")
else:
    print(count)
    print("1:" + str(golongan_1))
    print("2:" + str(golongan_2))
    print("3:" + str(golongan_3))
    avg = jumlah/count
    print(int(round(avg)))