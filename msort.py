def selectionsort(arr,n):
    for i in range(n):
        min=i
        for j in range(i+1,n):
            if(arr[j]<arr[min]):
                min=j
        temp=arr[i]
        arr[i]=arr[min]
        arr[min]=temp
    print(arr)
    
def bubblesort(arr,n):
    for i in range(len(arr)-1):
        for j in range(len(arr)-1):
            if(arr[j]>arr[j+1]):
                temp=arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp
    print(arr)
    print("top 5 scores are:")            
    for i in range(len(arr)-1,len(arr)-6,-1):
        print(arr[i])
        
print("\nHow many students are in first year:")
n=int(input())
array=[]
i=0
for i in range(n):
    item=float(input("Enter percentage of each students:"))
    array.append(item) 
    
print("\nYou have following score:")
print(array)
print("\nScore by selection sort:")
selectionsort(array,n) 
print("\nScore by bubble sort:")
bubblesort(array,n)          
    