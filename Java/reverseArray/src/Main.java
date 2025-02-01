import java.util.Scanner;

class reverseArray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the Array: ");
        int size = sc.nextInt();

        if(size <= 0){
            System.out.println("Not a Valid Size!");
            return;
        }
        int[] arr = new int[size];

        for (int i = 0 ; i < size ; i++) {
            System.out.print("Enter element " + (i+1) + ": ");
            arr[i] = sc.nextInt();
        }

        printReverseArray obj = new printReverseArray();
        obj.setSize(size);
        obj.setArr(arr);

        obj.printArrayUsingFor();
        obj.printArrayUsingWhileLoop();
        obj.printArrayUsingDoWhileLoop();
    }
}

class printReverseArray{
    int size;
    int[] arr;
    void setSize(int size){
        this.size = size;
        this.arr = new int[size];
    }
    void setArr(int[] arr){
        for (int i = 0; i < size ; i++) {
            this.arr[i] = arr[i];
        }
    }
    void printArrayUsingFor(){
        System.out.println("Reversed Array using for loop: ");
        for (int i = size - 1 ; i >= 0; i--) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    void printArrayUsingWhileLoop(){
        System.out.println("Reversed Array using while loop: ");
        int i = size - 1;
        while (i >= 0){
            System.out.print(arr[i]+" ");
            i--;
        }
        System.out.println();
    }
    void printArrayUsingDoWhileLoop(){
        System.out.println("Reversed Array using do while loop: ");
        int i = size - 1;
        do {
            System.out.print(arr[i]+" ");
            i--;
        }while (i >= 0);
        System.out.println();
    }
}