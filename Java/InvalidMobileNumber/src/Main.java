import java.util.Scanner;

class InvalidMobileNumberException extends Exception {
    public InvalidMobileNumberException(String message) {
        super(message);
    }
}

class MobileNumberValidator {
    public static void validateMobileNumber(String mobileNumber) throws InvalidMobileNumberException {
        if (mobileNumber == null || mobileNumber.isEmpty()) {
            throw new InvalidMobileNumberException("Mobile number cannot be null or empty.");
        }

        if (mobileNumber.length() < 10 || mobileNumber.length() > 15) {
            throw new InvalidMobileNumberException("Mobile number must be between 10 and 15 characters.");
        }

        if (!mobileNumber.matches("[0-9]+")) {
            throw new InvalidMobileNumberException("Mobile number can only contain digits.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try (scanner) {
            System.out.print("Enter your mobile number: ");
            String mobileNumber = scanner.nextLine();
            validateMobileNumber(mobileNumber);
            System.out.println("Valid mobile number: " + mobileNumber);
        } catch (InvalidMobileNumberException e) {
            System.out.println(e.getMessage());
        }
    }
}
