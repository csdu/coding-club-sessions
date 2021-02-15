# Simple Iterative Binary Search
def binary_search(a: list, k: int) -> bool:
    low, high = 0, len(a) - 1
    while low <= high:
        mid = (low + high) // 2
        if a[mid] == k:
            return True
        elif a[mid] > k:
            high = mid - 1
        else:
            low = mid + 1
    return False


# Simple Recursive Binary Search
def binary_search_recursive(low: int, high: int, a: list, k: int) -> bool:
    # Base case: invalid range (search space)
    # This happens when we exhaust all of our list
    if low > high:
        return False

    mid = (low + high) // 2
    if a[mid] == k:
        return True

    if a[mid] > k:
        return binary_search_recursive(low, mid - 1, a, k)
    else:
        return binary_search_recursive(mid + 1, high, a, k)


if __name__ == '__main__':
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))

    print('Iterative: ', end='')

    if binary_search(a, k):
        print('FOUND!')
    else:
        print('NOT FOUND!')

    print('Recursive: ', end='')

    if binary_search_recursive(0, len(a) - 1, a, k):
        print('FOUND!')
    else:
        print('NOT FOUND!')

'''
Inputs:
5 4
1 2 3 4 5

5 8
1 2 3 4 5
'''
