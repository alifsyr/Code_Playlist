/**
 * Employee.java
 * @author 18219036 Zachrandika Alif Syahreza
 */
public class Employee{
    private int compensation = 0;
    private int workload = 10;
    public Employee(){}
    public void compensate(int compensation){
        this.compensation += compensation; 
    }
    public void work() throws UnpaidException,UnderpaidException,BurnoutException{
        if(this.compensation == 0){
            throw new UnpaidException();
        }
        else if (this.compensation < 100){
            throw new UnderpaidException(100-this.compensation);
        }
        else if (this.workload == 0){
            throw new BurnoutException();
        }
        else{
            compensate(100);
            this.workload -= 1;
        }
    }
    public void nextDay(){
        this.workload = 10;
        this.compensation = 0;
    }
}
