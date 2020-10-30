# NIM/Nama : 16519080/Zachrandika Alif Syahreza
# Tanggal : 1 april 2020
# Deskripsi : program yang menghitung jumlah kuadrat positif dari daftar angka-angka X yang dimasukkan hingga program menerima input -999

# Kamus
# sum, cond, pos = integer

# Algoritma
sum = 0
cond = 0
while(cond==0):
    pos=int(input())
    if(pos>0):
        sum=sum+pos*pos
    elif(pos == -999):
        cond=1
print(sum)
    