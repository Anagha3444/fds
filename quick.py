def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

def display_top_five(arr):
    top_five = arr[-5:] if len(arr) >= 5 else arr
    top_five.reverse()  # Because we need the highest scores
    print("Top Five Scores are:", top_five)

def main():
    num_students = int(input("Enter the number of students: "))
    percentages = []

    print("Enter the percentages of students:")
    for _ in range(num_students):
        percentage = float(input())
        percentages.append(percentage)

    sorted_percentages = quick_sort(percentages)
    print("Sorted Percentages in Ascending Order:", sorted_percentages)
    display_top_five(sorted_percentages)

if __name__ == "__main__":
    main()
