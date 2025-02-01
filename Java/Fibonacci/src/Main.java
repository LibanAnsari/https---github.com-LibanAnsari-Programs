import java.util.Scanner;

class Fibonacci {
    int limit;

    void generateFibonacci() {
        int first = 0;
        int second = 1;
        System.out.print("0 ");
        while (second <= limit) {
            System.out.print(second + " ");
            int next = first + second;
            first = second;
            second = next;
        }
    }

    void setLimit(int limit) {
        this.limit = limit;
    }
}

class DisplaySeries {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the limit for Fibonacci series: ");
        int limit = sc.nextInt();

        if (limit < 0) {
            System.out.println("Limit cannot be negative!");
            return;
        }

        Fibonacci fib = new Fibonacci();
        fib.setLimit(limit);
        fib.generateFibonacci();
    }
}
