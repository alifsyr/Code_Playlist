/**
 * VehicleManager.java
 * sebuah kelas bernama VehicleManager yang dapat melakukan method sesui dengan jenis kendaraan tertentu
 * @author 18219036 Zachrandika Alif Syahreza
 */
import java.util.ArrayList;
import java.util.List;

public class VehicleManager {
    private List<Vehicle> list = new ArrayList<Vehicle>();

    /**
     * Menambahkan kendaraan ke array
     * 
     * @param vehicle objek Vehicle
     */
    public void addVehicle(Vehicle vehicle) {
        // Tambahkan kendaraan ke list
        list.add(vehicle);
    }

    /**
     * Memarkirkan semua kendaraan pada list menggunakan method park pada Vehicle
     */
    public void parkAllVehicles() {
        for (Vehicle vehicle : this.list) {
            vehicle.park();
        }
    }

    /**
     * Membuka semua pintu pada kendaraan yang memiliki pintu menggunakan method
     * openDoor pada Door
     */
    public void openAllDoors() {
        for (Vehicle vehicle : this.list){
            if (vehicle instanceof Helicopter){
                Helicopter h = (Helicopter) vehicle;
                h.openDoor();
            }
            else if (vehicle instanceof Car){
                Car c = (Car) vehicle;
                c.openDoor();
            }
        }
    }

    /**
     * Menutup semua pintu pada kendaraan yang memiliki pintu menggunakan method
     * closeDoor pada Door
     */
    public void closeAllDoors() {
        for (Vehicle vehicle : this.list){
            if (vehicle instanceof Helicopter){
                Helicopter h = (Helicopter) vehicle;
                h.closeDoor();
            }
            else if (vehicle instanceof Car){
                Car c = (Car) vehicle;
                c.closeDoor();
            }
        }
    }

    /**
     * Menyalakan semua mesin pada kendaraan yang memiliki mesin menggunakan method
     * startEngine pada Engine
     */
    public void startAllEngines() {
        for (Vehicle vehicle : this.list){
            if (vehicle instanceof Helicopter){
                Helicopter h = (Helicopter) vehicle;
                h.startEngine();
            }
            else if (vehicle instanceof Car){
                Car c = (Car) vehicle;
                c.startEngine();
            }
            else if (vehicle instanceof Motorcycle){
                Motorcycle m = (Motorcycle) vehicle;
                m.startEngine();
            }
        }
    }

    /**
     * Mematikan semua mesin pada kendaraan yang memiliki mesin menggunakan method
     * stopEngine pada Engine
     */
    public void stopAllEngines() {
        for (Vehicle vehicle : this.list){
            if (vehicle instanceof Helicopter){
                Helicopter h = (Helicopter) vehicle;
                h.stopEngine();
            }
            else if (vehicle instanceof Car){
                Car c = (Car) vehicle;
                c.stopEngine();
            }
            else if (vehicle instanceof Motorcycle){
                Motorcycle m = (Motorcycle) vehicle;
                m.stopEngine();
            }
        }
    }

    /**
     * Mengganti semua ban pada kendaraan yang memiliki ban menggunakan method
     * changeTyre pada Tyre
     */
    public void changeAllTyres() {
        for (Vehicle vehicle : this.list){
            if (vehicle instanceof Bicycle){
                Bicycle b = (Bicycle) vehicle;
                b.changeTyre();
            }
            else if (vehicle instanceof Car){
                Car c = (Car) vehicle;
                c.changeTyre();
            }
            else if (vehicle instanceof Motorcycle){
                Motorcycle m = (Motorcycle) vehicle;
                m.changeTyre();
            }
        }
    }
}