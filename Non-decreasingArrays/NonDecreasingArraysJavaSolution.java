/*
	Language: Java
	ID: 26651
	Qlink: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/make-it-non-decreasing-7d3391fd/
	Author: cssu.ama
*/

import java.util.Scanner;
 
public class NonDecreasingArraysJavaSolution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int t = scan.nextInt();
		
		for(int j = 0; j < t; j++) {
		
			int n = scan.nextInt();
			
			long[] A = new long[n];
			for(int i = 0; i < n; i++) {
				A[i] = scan.nextInt();
			}
			
			System.out.print(A[0] + " ");
			
			for(int i = 1; i < n; i++) {
				A[i] = A[i]*((A[i-1]+A[i]-1)/A[i]);
                
                System.out.print(
					A[i] + " "
				);
			}
		
			System.out.println();
		}
	}
}
