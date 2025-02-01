import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Complex A = new Complex();
        Complex B = new Complex();

        System.out.print("Enter the Real Part of A: ");
        A.setReal(sc.nextInt());
        System.out.print("Enter the Imaginary Part of A: ");
        A.setImg(sc.nextInt());
        System.out.print("Enter the Real Part of B: ");
        B.setReal(sc.nextInt());
        System.out.print("Enter the Imaginary Part of B: ");
        B.setImg(sc.nextInt());
        System.out.println();

        Complex C = new Complex();

        C = A.add(B);
        System.out.print("Addition of A and B: ");
        C.display();

        C = A.subtraction(B);
        System.out.print("Subtraction of A and B: ");
        C.display();

        C = A.multiply(B);
        System.out.print("Multiplication of A and B: ");
        C.display();

        C = A.divide(B);
        System.out.print("Sum of A and B: ");
        C.display();
    }
}

class Complex {
    int real, img;

    Complex add(Complex obj) {
        Complex temp = new Complex();
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    Complex subtraction(Complex obj) {
        Complex temp = new Complex();
        temp.real = real - obj.real;
        temp.img = img - obj.img;
        return temp;
    }

    Complex multiply(Complex obj) {
        Complex temp = new Complex();
        temp.real = (real * obj.real) - (img * obj.img);
        temp.img = (real * obj.img) + (img * obj.real);
        return temp;
    }

    Complex divide(Complex obj) {
        Complex temp = new Complex();
        int denominator = obj.real * obj.real + obj.img * obj.img;
        temp.real = (real * obj.real + img * obj.img) / denominator;
        temp.img = (img * obj.real - real * obj.img) / denominator;
        return temp;
    }

    void display() {
        System.out.println(real + " + " + img + "i");
    }
    void setReal(int x) {
        real = x;
    }

    void setImg(int i) {
        img = i;
    }
}
