#!/usr/bin/python3
def uppercase(s):
    for char in s:
        if ord('a') <= ord(char) <= ord('z'):
            print(chr(ord(char) - ord('a') + ord('A')), end="")
        else:
            print(char, end="")
    print()
