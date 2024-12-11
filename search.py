
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1


def sentinel_search(arr, x):
    n = len(arr)
    last = arr[n - 1]
    arr[n - 1] = x
    i = 0

    while arr[i] != x:
        i += 1

    arr[n - 1] = last

    if (i < n - 1) or (arr[n - 1] == x):
        return i
    return -1

roll_numbers = []
num_students = int(input("Enter the number of students: "))

print("Enter the roll numbers of students who attended the training program:")
for _ in range(num_students):
    roll_number = int(input())
    roll_numbers.append(roll_number)

print("Roll Numbers:", roll_numbers)


search_roll = int(input("Enter the roll number to search for: "))


result = linear_search(roll_numbers, search_roll)
if result != -1:
    print(f"Student with roll number {search_roll} attended the training program (Linear Search).")
else:
    print(f"Student with roll number {search_roll} did not attend the training program (Linear Search).")


result = sentinel_search(roll_numbers, search_roll)
if result != -1:
    print(f"Student with roll number {search_roll} attended the training program (Sentinel Search).")
else:
    print(f"Student with roll number {search_roll} did not attend the training program (Sentinel Search).")
