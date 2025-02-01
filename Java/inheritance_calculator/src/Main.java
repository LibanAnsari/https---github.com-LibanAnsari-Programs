/*
    PROGRAN 6 ><
 */

import java.util.Scanner;
class Calculator{
    public double add(int x, int y){
        return x + y;
    }
    public double subtract(int x, int y){
        return x - y;
    }
    public double multiply(int x, int y){
        return x * y;
    }
    public double divide(int x, int y){
        if(y != 0){
            return (double)(x / y);
        }else{
            System.out.println("Error! Division by zero.");
            return Double.NaN;
        }
    }
}

class ScientificCalculator extends Calculator{
    public double logarithm(double x) {
        if (x > 0) {
            return Math.log(x);
        } else {
            System.out.println("Error! Logarithm undefined for non-positive values.");
            return Double.NaN;
        }
    }
    public double exponent(double x) {
        return Math.exp(x);
    }
}

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int a = sc.nextInt();
        System.out.print("Enter second number: ");
        int b = sc.nextInt();

        ScientificCalculator calc = new ScientificCalculator();

        System.out.println("Addition: " + calc.add(a, b));
        System.out.println("Subtraction: " + calc.subtract(a, b));
        System.out.println("Multiplication: " + calc.multiply(a, b));
        System.out.println("Division: " + calc.divide(a, b));

        // Scientific operations
        System.out.println("Logarithm (ln("+a+")): " + calc.logarithm(a));
        System.out.println("Logarithm (ln("+b+")): " + calc.logarithm(b));
        System.out.println("Exponent (e^"+a+"): " + calc.exponent(a));
        System.out.println("Exponent (e^"+b+"): " + calc.exponent(b));

    }
}