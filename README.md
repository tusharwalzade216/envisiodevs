# envisiodevs
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C
is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in
individual strings is preserved.
The simple solution doesn’t work if strings A and B have some common characters. For example A =
“XXY”, string B = “XXZ” and string C = “XXZXXXY”. To handle all cases, two possibilities need to be
considered.
a) If first character of C matches with first character of A, we move one character ahead in A and C and
recursively check.
b) If first character of C matches with first character of B, we move one character ahead in B and C and
recursively check.
If any of the above two cases is true, we return true, else false. Following is simple recursive
implementation of this approach

# How to run :
Run as normal cpp code.
