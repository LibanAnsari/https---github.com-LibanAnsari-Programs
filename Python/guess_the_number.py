import random

def guess(choice):
    com = random.randint(1,3)
    print('\n')
    if(choice == com):
        print("Draw")
    elif(choice > com):
        if(choice == 2):
            print("")






# main
ch = 'y'
while(ch.lower() == 'y'):
    print("Press 1 for Rock\n Press 2 for Paper\n Press 3 for Scissors")
    x = int(input("Enter your choice: "))
    guess(x)
    
    ch = input("\nEnter 'y' to continue: ")
    