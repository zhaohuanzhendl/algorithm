/*
 * Filename   Sort_Colors.cc
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
using namespace std;

class Solution {
	void sortColors_A(int A[], int n)
	{
		int count[3] = {0};	
		for (int i=0; i<n; i++){
			count[A[i]]++;
		}

		for(int i=0, index=0; i<3; i++ ) {
			for (int j=0; j<count[i]; j++) {
				A[index++] = i;
			}	
		}
	}


	void sortColors_B(int A[], int n)
	{
		//A include 0, 1, 2
		int red=0, blue = n-1;
		for (int i=0; i<blue -1) {
			if (A[i] == 0) {
				swap(A[i++], A[red++]);
			} else if (A[i] == 2) {
				swap(A[i++], A[blue--]);	
			} else {
				i++;
			}
		}
	}
};



