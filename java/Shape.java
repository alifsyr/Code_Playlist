/**
 * Shape.java
 * Shape.java merupakan abstrack class
 * @author 18219036 Zachrandika Alif Syahreza
 */

public abstract class Shape{
    String namaBentuk;
    public Shape(String namaBentuk){
        this.namaBentuk = namaBentuk;
    }
    public void printShapeName(){
        System.out.println("Hi, I'm a " + namaBentuk +"!");
    }
    abstract double getArea();
    abstract double getCircumference();
}