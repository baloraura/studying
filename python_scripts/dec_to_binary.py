#!/usr/bin/env python3
import sys

def dec_to_binary(num: int):
    result = ""

    while (num > 0):
        if num % 2 == 0:
            result = "0" + result
        else:
            result = "1" + result
        num = num // 2
    
    return result

def main():

    try:
        if len(sys.argv) != 2:
            print("Usage: ./dec_to_binary.py <num>")
            exit()
        num = int(sys.argv[1])
        print(dec_to_binary(num))
    except ValueError:
        print("Please enter an integer")

if __name__=="__main__":
    main()