/**
 * FruitPrinter.java
 * sebuah kelas bernama FruitPrinter yang dapat Mencetak nama buah dan properti buah ke layar
 * @author 18219036 Zachrandika Alif Syahreza
 */
import java.util.ArrayList;
import java.util.List;

public class FruitPrinter {
    private List<Fruit> list = new ArrayList<Fruit>();

    /**
     * Add fruit. Menambahkan buah ke array
     * 
     * @param fruit objek Fruit
     */
    public void addFruit(Fruit fruit) {
        // Tambahkan buah ke list
        list.add(fruit);
    }

    /**
     * Print fruits. Mencetak nama buah yang ada di dalam array ke layar.
     */
    public void printFruits() {
        // Hint: gunakan instanceof untuk memeriksa apakah suatu objek
        // merupakan suatu tipe tertentu.
        // Misalnya: Pada list berisi objek [Banana, Banana, Orange, Apple].
        // Maka, cetak ke layar:
        // Banana
        // Banana
        // Orange
        // Apple
        for (Fruit f : list){
            if (f instanceof Banana){
                System.out.println("Banana");
                Banana b = (Banana) f;
                System.out.println(b.getBananaType());
            }
            else if (f instanceof Apple){
                System.out.println("Apple");
                Apple a = (Apple) f;
                System.out.println(a.isAppleSeedless());
            }
            else if (f instanceof Orange){
                System.out.println("Orange");
                Orange o = (Orange) f;
                System.out.println(o.isOrangeSeedless());
                System.out.println(o.isOrangeSweet());
            }
        }

    }
}
