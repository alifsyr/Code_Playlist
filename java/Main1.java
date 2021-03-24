/**
 * Main.java
 * Program menerima masukan berupa x y r (x dan y adalah koordinat titik pusat lingkaran, dan r adalah jari-jari lingkaran)
 * @author 18219036 Zachrandika Alif Syahreza
 */
import java.lang.System;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x;
        int y;
        float r;
    
        // Input x,y,r
        x = input.nextInt();  
        y = input.nextInt();
        r = input.nextFloat();

        // Tutup scanner
        input.close();

        Point origin = new Point(x,y);
        Circle circle = new Circle(origin,r);

        float keliling = circle.getCircumference();
        float luas = circle.getArea();

        // Output
        System.out.println(String.format("%d %d %f", x, y, r)); 
        System.out.println(Math.round(keliling)); 
        System.out.println(Math.round(luas));
    }
}