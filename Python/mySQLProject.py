#DETAILS BOX
print("\t_______________________________________________________________________")
print("\t|-------------------->>>>>ST. XAVIERS' SCHOOL<<<<<--------------------|")
print("\t|_____________________________________________________________________|")
print("\t|----------->>>TOPIC OF PROJECT: STUDENT RECORD MANAGMENT<<<----------|")
print("\t|_____________________________________________________________________|")
print("\t|~~~~~~~~~~~~~~~DONE BY: LIBAN ANSARI And YUSUF SIDDIQUI~~~~~~~~~~~~~~|")
print("\t|_____________________________________________________________________|")
print("\t|~~~~~~~~~~~~~~~~~~~~SUBMITTED TO: MRS. CHARU SOOD~~~~~~~~~~~~~~~~~~~~|")
print("\t|_____________________________________________________________________|")
print()

def Login_and_SignUP():#Login and Sign Up
    import mysql.connector as mys
    mycon=mys.connect(host='localhost',user='root',passwd='12345678',database='project')
    mycursor =mycon.cursor()
    mycursor.execute("create table if not exists signup(USERNAME varchar(30),PASSWORD varchar(30))")

    while True:
        print()
        print("1:SIGN UP")
        print("2:LOGIN")
        ch=int(input("SIGNUP/LOGIN(1,2): "))
        print()

        if ch==1:#SIGNUP
            username=input("Username: ")
            password=input("Password: ")
            mycursor.execute("insert into signup values('{}','{}')".format(username,password))
            mycursor.execute("commit")
            print("REGISTERED SUCCSESSFULLY!")
            print("LOGIN NOW!")

        elif ch==2:#LOGIN
            username=input("Username: ")
            mycursor.execute("select * from signup where USERNAME='{}'".format(username))
            user=mycursor.fetchone()
            if user is not None:
                print("VALID USERNAME!")
                print()
                password=input("Password: ")
                mycursor.execute("select * from signup where PASSWORD='{}'".format(password))
                a=mycursor.fetchone()
                if a is not None:
                    print("LOGIN SUCCESSFUL!")
                    break
                else:
                    print("WRONG PASSWORD!")
            else:
                print("INAVLID USERNAME!")
    mycon.close()
        
def addnew():#ADDING RECORDS
    import mysql.connector as mys
    mycon=mys.connect(host='localhost',user='root',passwd='12345678',database='project')
    mycursor =mycon.cursor()
    n=int(input("Enter the Number Of records you want to add: "))
    for i in range(n):
        sid=int(input("Enter the Student ID: "))
        sname=input("Enter the Student Name: ")
        gender=input("Enter the Gender: ")
        age=int(input("Enter the Age: "))
        DOA=input("Enter the Date of Admission(yyyy-mm-dd): ")
        address=input("Enter the Student Address: ")
        phone=int(input("Enter the Student Contact number: "))
        stream=input("Enter the student Stream(Science/Commerce/Humanities/Null): ")
        mycursor.execute("insert into student values({},'{}','{}',{},'{}','{}',{},'{}')".format(sid,sname,gender,age,DOA,address,phone,stream))
        mycursor.execute("commit")
        print("RECORD ADDED!")
        print()
    mycon.close()

def delrec():#DELETING RECORD
    import mysql.connector as mys
    mycon=mys.connect(host='localhost',user='root',passwd='12345678',database='project')
    mycursor =mycon.cursor()
    sid=int(input("Enter the Student ID to Delete: "))
    s_id=sid
    mycursor.execute("select * from student where STUDENT_ID={}".format(sid))
    a=mycursor.fetchone()
    if a is not None:
        print("The Details of the record Deleted is: ")
        mycursor.execute("select * from student where STUDENT_ID={}".format(sid))
        for (s_id,s_name,gender,age,DOA,address,phone,stream) in mycursor.fetchall():
            print('**************')
            print(s_id)
            print(s_name)
            print(gender)
            print(age)
            print(DOA)
            print(address)
            print(phone)
            print(stream)
            print('**************')
        mycursor.execute("delete from student where STUDENT_ID={}".format(s_id))
        mycursor.execute("commit")
        print("RECORD DELETED!")
        print()
        mycon.close()
    else:
        print("RECORD NOT FOUND!")
        print()

def modify():#MODIFYING RECORD
    import mysql.connector as mys
    mycon=mys.connect(host='localhost',user='root',passwd='12345678',database='project')
    mycursor =mycon.cursor()
    sid=int(input("Enter the Student ID to Update: "))
    mycursor.execute("select * from student where STUDENT_ID={}".format(sid))
    a=mycursor.fetchone()
    if a is not None:
        s_id=int(input("Enter the Student ID: "))
        s_name=input("Enter the Student Name: ")
        gender=input("Enter the Gender: ")
        age=int(input("Enter the Age: "))
        DOA=input("Enter the Date of Admission(yyyy-mm-dd): ")
        address=input("Enter the Student Address: ")
        phone=int(input("Enter the Student Contact number: "))
        stream=input("Enter the student Stream(Science/Commerce/Humanities/Null): ")
        mycursor.execute("update student set STUDENT_ID={},STUDENT_NAME='{}',GENDER='{}',AGE={},DATE_OF_ADMISSION='{}',ADDRESS='{}',PHONE={},STREAM='{}' where STUDENT_ID={}".format(s_id,s_name,gender,age,DOA,address,phone,stream,sid))
        print("RECORD UPDATED!")
        print()
        print("The Details of the Updated Record is: ")
        mycursor.execute("select * from student where STUDENT_ID={}".format(s_id))
        for (s_id,s_name,gender,age,DOA,address,phone,stream) in mycursor.fetchall():
            print('**************')
            print(s_id)
            print(s_name)
            print(gender)
            print(age)
            print(DOA)
            print(address)
            print(phone)
            print(stream)
            print('**************')
        mycursor.execute("commit")
        mycon.close()
    else:
        print("RECORD NOT FOUND!")
        print()

def search():#SEARCHING RECORDS
    import mysql.connector as mys
    mycon=mys.connect(host='localhost',user='root',passwd='12345678',database='project')
    mycursor =mycon.cursor()
    print("Press 1 for search by Student ID")
    print("Press 2 for search by Student Name")
    print("Press 3 for search by Stream")
    c=int(input("Enter Choice: "))
    if c==1:
        s_id=int(input("Enter the Student ID: "))
        mycursor.execute("select * from student where STUDENT_ID={}".format(s_id))
    elif c==2:
        s_name=input("Enter the Student Name: ")
        mycursor.execute("select * from student where STUDENT_NAME='{}'".format(s_name))
    elif c==3:
        stream=input("Enter the Stream(Science/Commerce/Humanities/Null): ")
        mycursor.execute("select * from student where STREAM='{}'".format(stream))
    else:
        print("INVALID CHOICE!")
    for (s_id,s_name,gender,age,DOA,address,phone,stream) in mycursor.fetchall():
        print('**************')
        print(s_id)
        print(s_name)
        print(gender)
        print(age)
        print(DOA)
        print(address)
        print(phone)
        print(stream)
        print('**************')
        print()
def display():
    import mysql.connector as mys
    mycon=mys.connect(host='localhost',user='root',passwd='12345678',database='project')
    mycursor =mycon.cursor()
    mycursor.execute("select * from student")
    mydata=mycursor.fetchall()
    for row in mydata:
        print(row)

#MAIN START
Login_and_SignUP()
while True:
    print()
    print("\t\t\t----------MENU PROGRAM DRIVEN----------")
    print("Press 1 to Add Records")
    print("Press 2 to Delete a Record")
    print("Press 3 to Modify a Record")
    print("Press 4 to Search a Record")
    print("Press 5 to Display all Records")
    print("Press 6 to Break")
    c=int(input("Enter Choice: "))
    print()
    if c==1:
        addnew()
    elif c==2:
        delrec()
    elif c==3:
        modify()
    elif c==4:
        search()
    elif c==5:
        display()
    elif c==6:
        print("\t\t\t---------------THANK YOU---------------")
        break
    else:
        print("INVALID CHOICE!")
