# NIM/Nama      : 16519080 / Zachrandika Alif Syahreza
# Tanggal       : 19/11/2019
# Deskripsi     : Problem 2

#kamus
# df = data frame tipe csv
# imax = data frame nilai fisika tertinggi
# kimia = data frame nilai kimia berurutan
 
#Algoritma
import pandas as pd
df = pd.read_csv('stei-abcd.csv')# pandas akan membaca file stei-abcd.csv yang ada di folder yang sama dengan tempat kode python ini disimpan
print (df.loc[df['nama'] == 'Tuan Yon'])# program membaca nilai matematika, fisika, dan kimia milik Tuan Yon
print ()
imax = df['nilai_fis'].idxmax()
print (df[imax:imax + 1])# program menampilkan mahasiswa dengan nilai fisika tertinggi. 
print ()
kimia = df.sort_values(["nilai_kim"], ascending=[0])
print (kimia[0:10])# program menampilkan 10 mahasiswa dengan nilai kimia tertinggi.
print ()
print("Banyaknya nilai matematika di bawah 50 : ",len(df.loc[(df['nilai_mat'] < 50)]))# program menampilkan banyaknya nilai matematika di bawah 50
print()
print("Banyaknya mahasiswa FMIPA : ",len(df.loc[df['fakultas'] == 'FMIPA']))# program menampilkan banyaknya mahasiswa FMIPA