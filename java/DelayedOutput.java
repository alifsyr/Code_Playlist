/**
 * DelayedOutput.java 
 * Class yang memiliki sebuah method printDelayed yang mengeluarkan suatu string ke output setelah delay sekian milidetik.
 * @author 18219036 Zachrandika Alif Syahreza
 */
public class DelayedOutput {
    public static void printDelayed(int delayMillisec, String output) {
        Runnable printdelay = new Runnable(){    
        public void run(){
            try { 
                Thread.sleep(delayMillisec);
            } catch(InterruptedException ex){ 
                Thread.currentThread().interrupt();
                throw new RuntimeException(ex);
            }

            System.out.println(output);
            }
        };
        Thread delay = new Thread(printdelay);
        delay.start();
    }
}