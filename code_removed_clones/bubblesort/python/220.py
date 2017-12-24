#!/usr/bin/python3
__author__ = "Vilde Arntzen"
from sys import stdin
from string import ascii_lowercase as chars
from random import randint, choice
from operator import itemgetter
from collections import defaultdict


def bubblesort(in_list):
    length = len(in_list) - 1
    unsorted = True

    while unsorted:
        unsorted = False
        for element in range(0,length):
            if in_list[element] > in_list[element + 1]:
                hold = in_list[element + 1]
                in_list[element + 1] = in_list[element]
                in_list[element] = hold
                unsorted = True

def main():
    d = int(stdin.readline())
    strings = []
    for line in stdin:
        strings.append(line.rstrip())
    bubblesort(strings)
    for string in strings:
        print(string)


if __name__ == "__main__":
    main()
