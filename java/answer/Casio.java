/**
 * Casio.java
 * sebuah kelas bernama Casio yang mengimplementasika interface Calculator
 * @author 18219036 Zachrandika Alif Syahreza
 */

public class Casio implements Calculator{
    public int hasil = 0;
    public int baterai = 100;

    public int plus(int angka){
        hasil += angka;
        baterai -= 5;
        return hasil;
    }
    public int minus(int angka){
        hasil -= angka;
        baterai -= 5;
        return hasil;
    }
    public int checkBattery(){
        return baterai;
    }
}