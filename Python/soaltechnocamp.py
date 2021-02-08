'''
def makeMatrix (n):
    a = []
    for i in range(n):
        b = []
        for j in range (n):
            elmnt = int(input("Masukan elemen baris "+str(i+1)+" kolom "+str(j+1)+": "))
            b =  b + [elmnt]
        a = a + [b]
    return a

def cetakMatrix (matrix,n):
    print("Matriks akhir:")
    for i in range(n):
        for j in range(n):
            print(matrix[i][j],end = " ")
        print()

n = int(input("masukan nilai n: "))
matrix = makeMatrix(n)
x = input("Apa yang ditukar (baris/kolom): ")
if x == "baris":
    y = int(input("Masukan indeks baris/kolom pertama: "))
    z = int(input("Masukan indeks baris/kolom kedua: "))
    matrix[y-1],matrix[z-1] = matrix[z-1],matrix[y-1]
elif x == 'kolom':
    y = int(input("Masukan indeks baris/kolom pertama: "))
    z = int(input("Masukan indeks baris/kolom kedua: "))
    for i in range(n):
        matrix[i][y-1],matrix[i][z-1] = matrix[i][z-1],matrix[i][y-1]

cetakMatrix(matrix, n)
'''


def makeMatrix (m,n):
    a = []
    for i in range(m):
        b = []
        for j in range (n):
            elmnt = int(input("Masukan elemen baris "+str(i+1)+" kolom "+str(j+1)+": "))
            b =  b + [elmnt]
        a = a + [b]
    return a

def operator(endprogram,x,matrix):
    if x == "b":
        a = int(input("Masukan baris pertama yang ingin ditukar: "))
        while a > m:
            print("Indeks baris tidak terdefinisi!")
            a = int(input("Masukan baris pertama yang ingin ditukar: "))
        b = int(input("Masukan baris kedua yang ingin ditukar: "))
        while b > m:
            print("Indeks baris tidak terdefinisi!")
            b = int(input("Masukan baris kedua yang ingin ditukar: "))
        matrix[a-1],matrix[b-1] = matrix[b-1],matrix[a-1]

    elif x == "k":
        a = int(input("Masukan kolom pertama yang ingin ditukar: "))
        while a > n:
            print("Indeks kolom tidak terdefinisi!")
            a = int(input("Masukan kolom pertama yang ingin ditukar: "))
        b = int(input("Masukan kolom kedua yang ingin ditukar: "))
        while b > n:
            print("Indeks kolom tidak terdefinisi!")
            b = int(input("Masukan kolom kedua yang ingin ditukar: "))
        for i in range(m):
            matrix[i][a-1],matrix[i][b-1] = matrix[i][b-1],matrix[i][a-1]

    elif x == "x":
        print("Kondisi matriks sekarang adalah")
        for i in range(m):
            for j in range(n):
                print(matrix[i][j],end = " ")
            print()
        endprogram = True
    else:
        print("Operator tidak terdaftar!")

    return endprogram, matrix

m = int(input("Masukan nilai m: "))
n = int(input("Masukan nilai n: "))
matrix = makeMatrix(m,n)
endprogram = False
while(not endprogram):
    x = input("Masukan operator: ")
    endprogram, matrix = operator(endprogram,x,matrix)