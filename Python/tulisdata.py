# NIM/Nama : 18219036/Zachrandika Alif Syahreza
# Tanggal : 26 November 2020
# Deskripsi : program yang membaca data siswa dari suatu tempat kursus dari suatu file teks dan mengurutkan data tersebut ke layar berdasarkan NoInduk secara terurut membesar serta menuliskan kembali data tersebut dalam keadaan terurut ke layar.

# Module untuk menulis data file keperluan praktikum

# type dataSiswa  : (NoInduk: string, KodeKursus : string, Nilai : integer)

def TulisDataSiswa(namafile):
    # Menulis data mahasiswa ke file namafile
    # Kamus
    # f : file teks
    # Algoritma
    f = open(namafile,'w')
    row1 = input().rstrip() # NoInduk
    # simpan sampai teks = 99999999
    while (row1 != "99999999"):
        # asumsikan selalu baca 3 data
        f.write(row1) # write NoInduk
        row2 = input() # KdKul
        f.write(row2) # write KodeKursus
        row3 = input() # nilai
        f.write(row3) # write Nilai
        # simpan ke file
        row1 = input().rstrip() # next-NoInduk
    # tulis mark
    f.write(row1) # mark
    f.close()
    return