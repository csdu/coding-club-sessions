# Simple Recursive Linear Search
def recursive_linear_search(i: int, a: list, k: int) -> bool:
    if i == len(a):
        return False
    if a[i] == k:
        return True
    return recursive_linear_search(i + 1, a, k)


'''

- This recursive strategy is known as Depth First Search (DFS).
  (Apparently the most well known and common recursive strategy)

- Recursion can be seen as a decisive strategy, at each step,
  we can have multiple choices or paths to recurse to.

- Such a structure can be well explained via a Decision Tree.

- For simplicity, for recursion, we call it a Recursion Tree.

'''

if __name__ == '__main__':
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    if recursive_linear_search(0, a, k):
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
