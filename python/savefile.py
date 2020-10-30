import csv

def save(x):
    global user_data
    global wahana_data
    global pembelian_data
    global penggunaan_data
    global tiket_data
    global refund_data
    global kritiksaran_data
    succsess = False
    daftar_file=["User","Daftar Wahana","Pembelian Tiket","Penggunaan Tiket","Kepemilikan Tiket","Refund Tiket","Kritik dan Saran"]
     
    for row in daftar_file:
        nama_file = input("Masukkan nama File " + row + ":" )
        with open(nama_file, mode='w',newline='') as csvfile:
            if nama_file == 'user.csv':
                write = csv.writer(csvfile)
                for row in user_data:
                    write.writerow(row)

            elif nama_file == 'wahana.csv':
                write = csv.writer(csvfile)
                for row in wahana_data:
                    write.writerow(row)
                      
            elif nama_file == 'pembelian.csv':
                write = csv.writer(csvfile)
                for row in pembelian_data:
                    write.writerow(row)
                    
            elif nama_file == 'penggunaan.csv':
                write = csv.writer(csvfile)
                for row in penggunaan_data:
                    write.writerow(row)
                    
            elif nama_file == 'tiket.csv':
                write = csv.writer(csvfile)
                for row in tiket_data:
                    write.writerow(row)
                    
            elif nama_file == 'refund.csv':
                write = csv.writer(csvfile)
                for row in refund_data:
                    write.writerow(row)
                    
            elif nama_file == 'kritiksaran.csv':
                write = csv.writer(csvfile)
                for row in kritiksaran_data:
                    write.writerow(row)
                    
    succses = True
    return success
