/**
 * Circle.java
 * Sebuah kelas untuk membuat objek lingkaran
 * @author 18219036 Zachrandika Alif Syahreza
 */


public class Circle {
    public float radius;
    public Point origin;
    /**
     * Konstruktor
     * @param origin Titik pusat lingkaran
     * @param radius Jari-jari lingkaran
     */
    public Circle(Point origin, float radius) {
        this.origin = origin; this.radius = radius;
    }

    /**
     * Hitung luas lingkaran
     * Asumsi pi = 3.14
     * @return luas lingkaran
     */
    public float getArea() {
        return 3.14f * radius * radius ;
    }

    /**
     * Hitung keliling lingkaran
     * Asumsi pi = 3.14
     * @return keliling lingkaran
     */
    public float getCircumference() {
        return 3.14f * 2 * radius ;
    }
}