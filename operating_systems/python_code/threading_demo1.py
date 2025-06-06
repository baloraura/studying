#!/usr/bin/env python3
import threading

def thread_num(num):

    t1 = threading.Thread(target=cube,args=(num,))
    t2 = threading.Thread(target=square, args=(num,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print("Done")


def cube(num):
    print(f"Cube: {num * num * num}")

def square(num):
    print(f"Square: {num * num}")


if __name__=="__main__":
    thread_num(10)