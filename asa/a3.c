Initialize a flag sorted = 0
While sorted = 0:
    - Set sorted = 1 (assume no swaps will happen this round).
    - Odd pass: Compare and swap the pairs of elements at odd indices (1,2),(3,4),...(1,2),(3,4),...if they are out of order. If any swap happens, set sorted = 0.
    - Even pass: Compare and swap the pairs at even indices (0,1),(2,3),…(0,1),(2,3),... If any swap happens, set sorted = 0.
The loop ends when a complete round of odd and even passes has no swaps, meaning sorted remains 1.

Example
array = [5, 2, 9, 1, 6, 3].
  Round 1:
    - Odd pass: Compare (1,2) => swap if needed, compare (3,4) => swap if needed, etc.
    - Even pass: Compare (0,1) => swap if needed, (2,3), (4,5), etc.
After each pass, the array may change. If any swap happened, set sorted = 0.
Continue rounds until there are no swaps in either pass. The array then becomes fully sorted.
