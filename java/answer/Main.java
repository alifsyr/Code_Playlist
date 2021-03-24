/**
 * Main.java
 * sebuah driver yang menerima instruksi untuk melakukan perhitungan dan memberikan output yang sesuai
 * @author 18219036 Zachrandika Alif Syahreza
*/

import java.lang.System;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner inputUser = new Scanner(System.in);
        Casio casio = new Casio();
        CasioKW casioKW = new CasioKW();
        String kata;

        kata = inputUser.nextLine();
        int angka; 
        while (!kata.toUpperCase().equals("END")){
            if (kata.toUpperCase().substring(0,4).equals("PLUS")){
                angka = Integer.parseInt(kata.substring(5,kata.length())); // merubah string menjadi integer
                System.out.println("Casio: " + casio.plus(angka));
                System.out.println("CasioKW: " + casioKW.plus(angka));
            }
            else if (kata.toUpperCase().substring(0,5).equals("MINUS")){
                angka = Integer.parseInt(kata.substring(6,kata.length())); // merubah string menjadi integer
                System.out.println("Casio: " + casio.minus(angka));
                System.out.println("CasioKW: " + casioKW.minus(angka));
            }
            else if (kata.toUpperCase().equals("CHECK_BATTERY")){
                System.out.println("Battery Casio: " + casio.checkBattery());
                System.out.println("Battery CasioKW: " + casioKW.checkBattery());
            }
            kata = inputUser.nextLine();
        }
        inputUser.close();
    }
}
