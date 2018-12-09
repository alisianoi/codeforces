#!/usr/bin/env python

"""
If your rating is ~1500, then the probability for you to solve the
task with `rating` is given below:
"""

if __name__ == "__main__":

    rating = int(input())

    print(1 / (1 + pow(10, (rating - 1500) / 400)))
