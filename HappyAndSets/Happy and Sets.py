# -*- coding: utf-8 -*-
'''
language = python

id = Happy and Sets

qlink = https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/happy-and-sets/

author: amir hejazi
'''


_, array = input(), [int( x ) for x in input().split()]
sum_of_products = array[0] % 1000000007
for a in array[1:]:
    sum_of_products = ((a + 1) * sum_of_products + a) % 1000000007
print( sum_of_products )