#!/usr/bin/env python3
import sys

def lowercaseify(string: str):
    result = ""

    for char in string:
        if char.isupper():
            result += char.lower()
        else:
            result += char
    
    return result

def main():
    string = sys.argv[1]
    print(lowercaseify(string))

if __name__=="__main__":
    main()