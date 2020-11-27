# NIM/Nama : 18219036/Zachrandika Alif Syahreza
# Tanggal : 26 November 2020
# Deskripsi : program yang membaca data siswa dari suatu tempat kursus dari suatu file teks dan mengurutkan data tersebut ke layar berdasarkan NoInduk secara terurut membesar serta menuliskan kembali data tersebut dalam keadaan terurut ke layar.

# Program SortSiswa
# Spesifikasi 
import tulisdata

# KAMUS
# namafile: string


# ALGORITMA PROGRAM UTAMA
namafile = input()
'''
tulisdata.TulisDataSiswa(namafile)
'''
f = open(namafile,"r")
a = []
found = False

while (not found):
    x = f.readline()
    if (x != "99999999"):
        row1 = [x]
        y = f.readline()
        if (y != "99999999"):
            row2 = [y]
            z = f.readline()
            if (z != "99999999"):
                row3 = [z]
                a += [row1,row2,row3]
            else:
                found = True
        else:
            found = True
    else:
        found = True

for i in a:
    print (i)