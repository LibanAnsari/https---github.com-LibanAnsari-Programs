import java.util.Scanner;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Complex A = new Complex();
        A.real = 3;
        A.img = 5;

        Complex B = new Complex();
        B.real = 2;
        B.img = 3;

        Complex C = new Complex();
        C = A.add(B);

        System.out.print(C.real+" +i"+C.img);
    }
}

class  Complex{
    int real , img;
    Complex add(Complex obj){

        Complex temp = new Complex();
        temp.real = real + obj.real;
        temp.img = img + obj.img;

        return temp;
    }
}