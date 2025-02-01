import java.util.Scanner;

class Fibonacci{
    public int n;
    public void generateFibonacci(){
        System.out.print(0+" ");
        int first = 0;
        int second = 1;
        for(int i = 2 ; i <= n ; i++){
            System.out.print(second+" ");
            int next = first + second;
            first = second;
            second = next;
        }
    }
    public void setN(int n){
        this.n = n;
    }
}

class DisplaySeries{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of terms: ");
        int n = sc.nextInt();
        if(n <= 0){
            System.out.println("Invalid Input!");
            return;
        }
        Fibonacci fib = new Fibonacci();
        fib.setN(n);
        fib.generateFibonacci();
    }
}