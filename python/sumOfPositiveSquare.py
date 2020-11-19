# NIM/Nama  : 18219036/Zachrandika Alif Syahreza
# Tanggal   : 19 November 2020
# Deskripsi : program yang menghitung jumlah kuadrat positif dari daftar angka-angka X yang dimasukkan hingga program menerima input -999

# Algoritma
sum = 0
cond = True
while(cond):
    pos=int(input())
    if(pos>0):
        sum=sum+pos*pos
    elif(pos == -999):
        cond = False
print(sum)