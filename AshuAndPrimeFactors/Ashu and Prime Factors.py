# -*- coding: utf-8 -*-
'''
language = python

id = Ashu and Prime Factors

qlink = https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/ashu-and-prime-factors-4/

author: amir hejazi
'''
from sys import stdin, stdout
 
def main ():
    read = stdin.readline
    write = stdout.write
    pd = ['0\n', '0\n', '500000\n', '166667\n', '0\n', '66667\n', '0\n', '38095\n', '0\n', '0\n', '0\n', '20779\n', '0\n', '15984\n', '0\n', '0\n', '0\n', '11284\n', '0\n', '9503\n', '0\n', '0\n', '0\n', '7435\n', '0\n', '0\n', '0\n', '0\n', '0\n', '5647\n', '0\n', '5099\n', '0\n', '0\n', '0\n', '0\n', '0\n', '4137\n', '0\n', '0\n', '0\n', '3618\n', '0\n', '3357\n', '0\n', '0\n', '0\n', '2983\n', '0\n', '0\n', '0\n', '0\n', '0\n', '2576\n', '0\n', '0\n', '0\n', '0\n', '0\n', '2262\n', '0\n', '2144\n', '0\n', '0\n', '0\n', '0\n', '0\n', '1911\n', '0\n', '0\n', '0\n', '1776\n', '0\n', '1701\n', '0\n', '0\n', '0\n', '0\n', '0\n', '1554\n', '0\n', '0\n', '0\n', '1461\n', '0\n', '0\n', '0\n', '0\n', '0\n', '1355\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '1245\n', '0\n', '0\n', '0\n', '1196\n', '0\n', '1172\n', '0\n', '0\n', '0\n', '1131\n', '0\n', '1110\n', '0\n', '0\n', '0\n', '1075\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '965\n', '0\n', '0\n', '0\n', '938\n', '0\n', '0\n', '0\n', '0\n', '0\n', '899\n', '0\n', '887\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '833\n', '0\n', '821\n', '0\n', '0\n', '0\n', '0\n', '0\n', '795\n', '0\n', '0\n', '0\n', '0\n', '0\n', '764\n', '0\n', '0\n', '0\n', '746\n', '0\n', '0\n', '0\n', '0\n', '0\n', '720\n', '0\n', '0\n', '0\n', '0\n', '0\n', '698\n', '0\n', '690\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '655\n', '0\n', '648\n', '0\n', '0\n', '0\n', '634\n', '0\n', '630\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '594\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '563\n', '0\n', '0\n', '0\n', '552\n', '0\n', '548\n', '0\n', '0\n', '0\n', '540\n', '0\n', '0\n', '0\n', '0\n', '0\n', '524\n', '0\n', '519\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '497\n', '0\n', '0\n', '0\n', '0\n', '0\n', '486\n', '0\n', '0\n', '0\n', '0\n', '0\n', '474\n', '0\n', '0\n', '0\n', '0\n', '0\n', '463\n', '0\n', '458\n', '0\n', '0\n', '0\n', '0\n', '0\n', '447\n', '0\n', '0\n', '0\n', '440\n', '0\n', '435\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '419\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '399\n', '0\n', '0\n', '0\n', '392\n', '0\n', '389\n', '0\n', '0\n', '0\n', '382\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '368\n', '0\n', '0\n', '0\n', '0\n', '0\n', '361\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '350\n', '0\n', '348\n', '0\n', '0\n', '0\n', '341\n', '0\n', '0\n', '0\n', '0\n', '0\n', '334\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '326\n', '0\n', '0\n', '0\n', '0\n', '0\n', '316\n', '0\n', '0\n', '0\n', '0\n', '0\n', '309\n', '0\n', '0\n', '0\n', '305\n', '0\n', '0\n', '0\n', '0\n', '0\n', '300\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '292\n', '0\n', '0\n', '0\n', '290\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '284\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '275\n', '0\n', '271\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '263\n', '0\n', '261\n', '0\n', '0\n', '0\n', '0\n', '0\n', '255\n', '0\n', '0\n', '0\n', '251\n', '0\n', '0\n', '0\n', '0\n', '0\n', '246\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '241\n', '0\n', '0\n', '0\n', '239\n', '0\n', '237\n', '0\n', '0\n', '0\n', '234\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '225\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '219\n', '0\n', '0\n', '0\n', '216\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '211\n', '0\n', '0\n', '0\n', '206\n', '0\n', '0\n', '0\n', '0\n', '0\n', '202\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '197\n', '0\n', '195\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '185\n', '0\n', '0\n', '0\n', '0\n', '0\n', '182\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '178\n', '0\n', '0\n', '0\n', '0\n', '0\n', '173\n', '0\n', '0\n', '0\n', '0\n', '0\n', '171\n', '0\n', '169\n', '0\n', '0\n', '0\n', '0\n', '0\n', '166\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '161\n', '0\n', '0\n', '0\n', '0\n', '0\n', '157\n', '0\n', '0\n', '0\n', '0\n', '0\n', '156\n', '0\n', '153\n', '0\n', '0\n', '0\n', '0\n', '0\n', '150\n', '0\n', '0\n', '0\n', '0\n', '0\n', '148\n', '0\n', '0\n', '0\n', '145\n', '0\n', '143\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '137\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '132\n', '0\n', '130\n', '0\n', '0\n', '0\n', '127\n', '0\n', '0\n', '0\n', '0\n', '0\n', '125\n', '0\n', '0\n', '0\n', '0\n', '0\n', '122\n', '0\n', '121\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '115\n', '0\n', '0\n', '0\n', '112\n', '0\n', '0\n', '0\n', '0\n', '0\n', '110\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '106\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '100\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '98\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '95\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '93\n', '0\n', '0\n', '0\n', '0\n', '0\n', '90\n', '0\n', '0\n', '0\n', '0\n', '0\n', '88\n', '0\n', '0\n', '0\n', '87\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '86\n', '0\n', '0\n', '0\n', '0\n', '0\n', '84\n', '0\n', '0\n', '0\n', '81\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '77\n', '0\n', '0\n', '0\n', '75\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '69\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '67\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '64\n', '0\n', '63\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '59\n', '0\n', '57\n', '0\n', '0\n', '0\n', '55\n', '0\n', '54\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '51\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '48\n', '0\n', '0\n', '0\n', '46\n', '0\n', '45\n', '0\n', '0\n', '0\n', '43\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '40\n', '0\n', '0\n', '0\n', '39\n', '0\n', '38\n', '0\n', '0\n', '0\n', '36\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '31\n', '0\n', '0\n', '0\n', '30\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '26\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '24\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '22\n', '0\n', '0\n', '0\n', '20\n', '0\n', '0\n', '0\n', '0\n', '0\n', '18\n', '0\n', '0\n', '0\n', '0\n', '0\n', '16\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '13\n', '0\n', '0\n', '0\n', '10\n', '0\n', '0\n', '0\n', '0\n', '0\n', '9\n', '0\n', '0\n', '0\n', '0\n', '0\n', '6\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '0\n', '4\n', '0\n', '0\n', '0\n', '0\n', '0\n', '2\n', '0\n', '0\n', '0\n']
    # code to create list pd
    MAXX = 1000001
    MAXXSQ = 1000
    prime = bytearray ([1]) * MAXX
    pd = ["0\n"] * (MAXXSQ + 1)
    pd [2] = "500000\n"
    prime [4::2] = 499999 * [0]
    cnt = 1
    for j in range (9, MAXX, 3):
        if (prime [j]):
            prime [j] = 0
            cnt += 1
    pd [3] = str (cnt) + '\n'
    for i_ in range (5, MAXXSQ - 2, 6):
        for i in (i_, i_ + 2):
            if (prime [i]):
                cnt = 1
                for j in range (i * i, MAXX, i):
                    if (prime [j]):
                        prime [j] = 0;
                        cnt += 1
                pd [i] = str (cnt) + '\n'
    t = int (read ())
    for t_ in range (t):
        n = int (read ())
        write ("1\n" if n > 1000 else pd [n])
 
if __name__ == "__main__": main ()