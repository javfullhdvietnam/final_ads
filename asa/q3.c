Input:
An array of size n=6
{5,3,8,6,2,4}
Iteration 1:
1,Odd-Indexed Phase:
Compare and swap adjacent elements at odd indices:
Compare arr[1] and arr[2], swap if arr[1]>arr[2]
Compare arr[3] and arr[4], swap if arr[3]>arr[4]
Result after Odd Phase:
{5,3,6,8,2,4}
2,Even-Indexed Phase:
Compare and swap adjacent elements at even indices:
Compare arr[0] and arr[1], swap if arr[0]arr[1]
Compare arr[2] and arr[3], swap if arr[2]>arr[3]
Compare arr[4] and arr[5], swap if arr[4]>arr[5]
Result after Even Phase:
{3,5,6,2,4,8}
Iteration 2:
1,Odd-Indexed Phase:
Compare and swap arr[1] and arr[2], arr[3] and arr[4]:
Result after Odd Phase:
{3,5,2,6,4,8}
2,Even-Indexed Phase:
Compare and swap arr[1] and arr[2], arr[3] ,arr[4] and arr[5]:
Result after Even Phase:
{3,2,5,4,6,8}
Iteration 3:
1,Odd-Indexed Phase:
Compare and swap arr[1] and arr[2], arr[3] and arr[4]:
Result after Odd Phase:
{3,2,4,5,6,8}
2,Even-Indexed Phase:
Compare and swap arr[1] and arr[2], arr[3] ,arr[4] and arr[5]:
Result after Even Phase:
{2,3,4,5,6,8}
Final Result:
The array is fully sorted:
{2,3,4,5,6,8}
