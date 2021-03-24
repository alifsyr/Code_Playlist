/**
 * Main.java 
 * program utama yang menerima perintah untuk melakukan compensate, work, atau nextDay
 * @author 18219036 Zachrandika Alif Syahreza
 */

import java.lang.System;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Employee employee = new Employee();
        int countperintah = scanner.nextInt();
        for (int i = 0; i < countperintah; i++){
            int perintah = scanner.nextInt();
            if (perintah == 1){
                int gaji = scanner.nextInt();
                employee.compensate(gaji);
                System.out.println("Berhasil membayar pegawai sebesar V$" + gaji);
            }
            else if (perintah == 2){
                try{
                    employee.work();
                    System.out.println("Berhasil melakukan tugas");
                }
                catch (UnpaidException e){
                    System.out.println(e.getErrorMessage());
                }
                catch (UnderpaidException e){
                    System.out.println(e.getErrorMessage());
                }
                catch (BurnoutException e){
                    System.out.println(e.getErrorMessage());
                }
            }
            else if (perintah == 3){
                employee.nextDay();
                System.out.println("Gamti hari boi!");
            }
        }
        scanner.close();
    }
}