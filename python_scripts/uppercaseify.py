#!/usr/bin/env python3
import sys

def uppercaseify(string: str):
    result = ""

    for char in string:
        if char.islower():
            result += char.upper()
        else:
            result += char
    
    return result

def main():
    string = sys.argv[1]
    print(uppercaseify(string))

if __name__=="__main__":
    main()