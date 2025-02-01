/*
    EXCEPTION HANDLING
    If Marks < 0, throw MarksException
    use try, catch and finally
 */

import java.util.Scanner;
class MarksException extends Exception{
    MarksException(String msg){
        super(msg);
    }
}
class MarksValidator{
    public static void ValidMarks(int marks) throws MarksException{
        if(marks < 0){
            throw new MarksException("Marks Cannot be Negative.");
        }
    }
    public static void main(String[] args) {
        try{
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter Marks: ");
            int marks = sc.nextInt();
            ValidMarks(marks);
        }catch (MarksException ex){
            System.out.println(ex.getMessage());
        }finally {
            System.out.println("Marks Finalized.");
        }
    }
}