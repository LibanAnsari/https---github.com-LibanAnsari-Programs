/*
    PROGRAM 7 :3
 */

import java.util.Scanner;
interface InterfaceCalculator {
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double logarithm(double a);
    double exponent(double a);
}

class Calculator implements InterfaceCalculator {
    public double add(double a, double b) {
        return a + b;
    }
    public double subtract(double a, double b) {
        return a - b;
    }
    public double multiply(double a, double b) {
        return a * b;
    }
    public double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            System.out.println("Error! Division by zero.");
            return Double.NaN;
        }
    }
    public double logarithm(double a){
        if (a > 0) {
            return Math.log(a);
        } else {
            System.out.println("Error! Logarithm undefined for non-positive values.");
            return Double.NaN;
        }
    }
    public double exponent(double a){ return Math.exp(a); }
}

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int a = sc.nextInt();
        System.out.print("Enter second number: ");
        int b = sc.nextInt();

        InterfaceCalculator calc = new Calculator();

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