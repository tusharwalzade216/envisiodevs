//============================================================================
// Name        : InterleavingString.cpp
// Author      : tushar
// Version     :
// Copyright   : copyright
// Description : Program to check a string is interleaving of other two's
// How to run  : Run as a normal C++ Code
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 10

// The main function that returns true if C is
// an interleaving of A and B, otherwise false.
bool isInterleaved(char* A, char* B, char* C) {
	// Find lengths of the two strings
	int M = strlen(A), N = strlen(B);

	// Let us create a 2D table to store solutions of
	// subproblems.  C[i][j] will be true if C[0..i+j-1]
	// is an interleaving of A[0..i-1] and B[0..j-1].
	bool Array[M + 1][N + 1];

	memset(Array, 0, sizeof(Array)); // Initialize all values as false.

	// C can be an interleaving of A and B only of sum
	// of lengths of A & B is equal to length of C.
	if ((M + N) != strlen(C))
		return false;

	// Process all characters of A and B
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j <= N; ++j) {
			// two empty strings have an empty string
			// as interleaving
			if (i == 0 && j == 0)
				Array[i][j] = true;

			// A is empty
			else if (i == 0 && B[j - 1] == C[j - 1])
				Array[i][j] = Array[i][j - 1];

			// B is empty
			else if (j == 0 && A[i - 1] == C[i - 1])
				Array[i][j] = Array[i - 1][j];

			// Current character of C matches with current character of A,
			// but doesn't match with current character of B
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
				Array[i][j] = Array[i - 1][j];

			// Current character of C matches with current character of B,
			// but doesn't match with current character of A
			else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
				Array[i][j] = Array[i][j - 1];

			// Current character of C matches with that of both A and B
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
				Array[i][j] = (Array[i - 1][j] || Array[i][j - 1]);
		}
	}

	return Array[M][N];
}

// A function to run test cases
void test(char *A, char *B, char *C) {
	if (isInterleaved(A, B, C))
		cout << C << " is interleaved of " << A << " and " << B << endl;
	else
		cout << C << " is not interleaved of " << A << " and " << B << endl;
}

// Driver program to test above functions
int main() {
	char *A;
	char *B;
	char *C;
	A = new char[SIZE];
	B = new char[SIZE];
	C = new char[SIZE * 2];
	cout << "enter A : "; // "XXY";
	cin >> A;
	cout << "enter B : "; // "XXZ";
	cin >> B;
	cout << "enter C : "; // "XXZXXXY";
	cin >> C;
	test(A, B, C);
	test(B, A, C);
	return 0;
}
