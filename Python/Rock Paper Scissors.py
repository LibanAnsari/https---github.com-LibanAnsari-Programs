import random

def guess(choice):
    com = random.randint(1, 3)  # Computer's choice
    print("\nComputer chose:", com)

    # Rock-Paper-Scissors logic
    if choice == com:
        print("Draw")
    elif (choice == 1 and com == 3) or (choice == 2 and com == 1) or (choice == 3 and com == 2):
        print("You win!")
    else:
        print("Computer wins!")

# Main loop
ch = 'y'
while ch.lower() == 'y':
    print("Press 1 for Rock\nPress 2 for Paper\nPress 3 for Scissors")
    try:
        x = int(input("Enter your choice: "))
        if x in [1, 2, 3]:  # Validating user input
            guess(x)
        else:
            print("Invalid choice! Please enter 1, 2, or 3.")
    except ValueError:
        print("Invalid input! Please enter a number.")

    ch = input("\nEnter 'y' to continue, or any other key to exit: ")