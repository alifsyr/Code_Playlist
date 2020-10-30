# NIM/Nama      : 16519080 / Zachrandika Alif Syahreza
# Tanggal       : 19/11/2019
# Deskripsi     : Problem 1

#kamus
# df = data frame tipe csv

#Algoritma
import pandas as pd
df = pd.read_csv('stei-abcd.csv')# pandas akan membaca file stei-abcd.csv yang ada di folder yang sama dengan tempat kode python ini disimpan
print("Banyaknya data : ",len(df))# program membaca banyak data
print()
print(df[:10])# program membaca 10 data pertama
print()
print(df[50:61])# program membaca data ke-50 
print()
print(df['fakultas'].value_counts())# program membaca banyak mahasiswa tiap fakultas
print()
print(df['nilai_fis'].corr(df['nilai_kim']))# program menghitung nilai korelasi
print()
print("kesimpulan : karena hasil korelasi adalah 0.8037804275433461 yang dimana mendekati 1 maka nilai korelasinya berbanding lurus")