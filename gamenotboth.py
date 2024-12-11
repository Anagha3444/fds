def intersection(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val in lst2:
            lst3.append(val)
    return lst3



def diff(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3

def union(lst1,lst2):
    lst3=lst1.copy()
    for val in lst2:
        if val not in lst3:
            lst3.append(val)
    return lst3


def sym_diff(lst1,lst2):
    lst3=[]
    D1=diff(lst1,lst2)
    print("Difference between Cricket and Badminton (C-B) is : ", D1)
    D2=diff(lst2,lst1)
    print("Difference between Badminton and Cricket (B-C) is : ", D2)
    lst3=union(D1,D2)
    return lst3



def eCeB(lst1,lst2):
    lst3=sym_diff(lst1,lst2)
    print("\nList of students who play either cricket or badminton but not both is : ",lst3)
    return len(lst3)



def CBnF(lst1,lst2,lst3):
    lst4=diff(intersection(lst1,lst2),lst3)
    print("\n\nList of students who play cricket and football but not badminton is : ",lst4)
    return len(lst4)


SEComp = []
n = int(input("\nEnter number of students in SE COMP: "))
print("Enter the names of",n,"students (Please press ENTER after entering each students name) :")
for i in range(0, n):
    ele = input()
    SEComp.append(ele) 
print("Original list of students in SEComp : " + str(SEComp))


Cricket = []
n = int(input("\n\nEnter number of students who play cricket : "))
print("Enter the names of",n,"students who play cricket (Please press ENTER after entering each students name) :")
for i in range(0, n):
    ele = input()
    Cricket.append(ele)  
print("Original list of students playing cricket is :" +str(Cricket))



Football = []
n = int(input("\n\nEnter number of students who play football : "))
print("Enter the name of",n,"students who play football (Please press ENTER after entering each students name) :")
for i in range(0, n):
    ele = input()
    Football.append(ele)  
print("Original list of students playing football :" +str(Football))



Badminton = []
n = int(input("\n\nEnter number of students who play badminton : "))
print("Enter the name of",n,"students who play badminton (Please press ENTER after entering each students name) :")
for i in range(0, n):
    ele = input()
    Badminton.append(ele)  
print("Original list of students playing badminton :" +str(Badminton))




flag=1
while flag==1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. List of students who play either cricket or badminton but not both")
    print("2. Number of students who play cricket and football but not badminton")
    print("3. Exit\n")
    ch=int(input("Enter your Choice (from 1 to 5) :"))


    if ch==1:
        print("Number of students who play either cricket or badminton but not both : ", eCeB(Cricket, Badminton))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

   

    elif ch==2:
        print("Number of students who play cricket and football but not badminton : ", CBnF(Cricket,Football,Badminton))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

    elif ch==5:
        flag=0
        print("Thanks for using this program!")

    else:
        print("!!Wrong Choice!! ")
        a=input("\n\nDo you want to continue (yes/no) :")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thanks for using this program")