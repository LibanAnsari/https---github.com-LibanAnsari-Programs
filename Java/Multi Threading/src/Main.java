class OddNumPrint extends Thread {
    private int start;

    public OddNumPrint(int start) {
        this.start = start;
    }

    public void run() {
        for (int i = start; i <= 100; i += 2) {
            System.out.println(Thread.currentThread().getName() + " printed: " + i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Create two threads
        OddNumPrint thread1 = new OddNumPrint(1); // Starts at 1
        OddNumPrint thread2 = new OddNumPrint(1); // Also starts at 1

        // Set names for the threads
        thread1.setName("Thread 1");
        thread2.setName("Thread 2");

        // Start the threads
        thread1.start();
        thread2.start();
    }
}
