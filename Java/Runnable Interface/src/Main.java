class OddNumPrint implements Runnable {
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
        // Create two Runnable objects with different starting points
        OddNumPrint oddTask1 = new OddNumPrint(1); // Starts at 1
        OddNumPrint oddTask2 = new OddNumPrint(1); // Also starts at 1

        // Create threads from the Runnable objects
        Thread thread1 = new Thread(oddTask1, "Thread 1");
        Thread thread2 = new Thread(oddTask2, "Thread 2");

        // Start the threads
        thread1.start();
        thread2.start();
    }
}
