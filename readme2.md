Static Predecessor Problem
Implementation Using a Sorted Array
Store Elements in Sorted Order:

Sort the elements initially. For example, given the set 
𝑆
=
{
10
,
4
,
7
,
15
}
S={10,4,7,15}, sort it to get 
𝑆
sorted
=
{
4
,
7
,
10
,
15
}
S 
sorted
​
 ={4,7,10,15}.
Predecessor Query:

To find the predecessor of a value 
𝑧
z, perform a binary search to find the largest element less than 
𝑧
z.
Example Implementation (Python):

python
Copy code
import bisect

class StaticPredecessor:
    def __init__(self, elements):
        self.sorted_elements = sorted(elements)
    
    def predecessor(self, z):
        # Find the insertion point for z
        pos = bisect.bisect_left(self.sorted_elements, z)
        # The predecessor will be the element just before the insertion point
        if pos > 0:
            return self.sorted_elements[pos - 1]
        else:
            return None  # No predecessor if z is smaller than all elements

# Example usage
sp = StaticPredecessor([10, 4, 7, 15])
print(sp.predecessor(8))  # Output: 7
print(sp.predecessor(4))  # Output: None
Dynamic Predecessor Problem
Implementation Using a Red-Black Tree
Use a Balanced Binary Search Tree (BST):

Implement the tree to maintain order and balance. Python’s sortedcontainers library provides a SortedList which is backed by a balanced BST.
Predecessor Query:

To find the predecessor of a value 
𝑧
z, you can use the bisect_left method to find the insertion point and retrieve the element just before it.
Example Implementation (Python with sortedcontainers):

python
Copy code
from sortedcontainers import SortedList

class DynamicPredecessor:
    def __init__(self):
        self.sorted_list = SortedList()
    
    def insert(self, x):
        self.sorted_list.add(x)
    
    def delete(self, x):
        if x in self.sorted_list:
            self.sorted_list.remove(x)
    
    def predecessor(self, z):
        # Find the insertion point for z
        pos = self.sorted_list.bisect_left(z)
        # The predecessor will be the element just before the insertion point
        if pos > 0:
            return self.sorted_list[pos - 1]
        else:
            return None  # No predecessor if z is smaller than all elements

# Example usage
dp = DynamicPredecessor()
dp.insert(10)
dp.insert(4)
dp.insert(7)
dp.insert(15)
print(dp.predecessor(8))  # Output: 7
print(dp.predecessor(4))  # Output: None

dp.delete(7)
print(dp.predecessor(8))  # Output: 10
Summary
Static Solution:

Use a sorted list and binary search for predecessor queries.
Efficient for cases where the dataset does not change.
Dynamic Solution:

Use a balanced BST or a sorted list data structure to support fast queries and updates.
Suitable for cases where the dataset frequently changes.