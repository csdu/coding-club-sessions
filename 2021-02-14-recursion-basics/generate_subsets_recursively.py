'''

Generating all subsets of a set:

{   1,      2,     3,     4   }
  (0,1)   (0,1)  (0,1)  (0,1)

So, we basically have 2 choices for each element in the set.
- Keep it    (1)
- Discard it (0)

It's called Inclusion-Exclusion
This is why we have 2^n subsets for an n-set (set of size n)

This task can be done iteratively using bit strings of length n.
They naturally show this property of Inclusion-Exclusion.

This is an example of all bit strings of length 3.
000
001
010
011
100
101
110
111

One can notice that we can have generate subsets using these bit patterns.
(This is explained well in the C++ implementation
 of this problem, do check that out)

Here we focus only on the recursive implementation, for iterative
implementation, see the C++ source file with the name
`generate_subsets.cpp`

'''

subsets = []
subset = []

# Solves the problem for the sub array starting at index i till the list end
# [i, ..., n - 1]
def generate_subsets_recursively(i: int, a: list) -> None:
    if i == len(a):
        # Appending a deep copy of `subset` list to `subsets` list
        subsets.append(subset[:])
        return

    # Inclusion
    subset.append(a[i])
    # [i + 1, ..., n - 1], with a[i] included
    generate_subsets_recursively(i + 1, a)

    # Exclusion
    subset.pop()
    # [i + 1, ..., n - 1], without a[i]
    generate_subsets_recursively(i + 1, a)


if __name__ == '__main__':
    a = [1, 2, 3]
    generate_subsets_recursively(0, a)
    print('Subsets:', subsets)
