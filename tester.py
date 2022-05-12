#!/usr/bin/env python

# Put this wherever you can call ./push_swap
# call with "python tester.py"

from __future__ import print_function

# for capturing output from ./push_swap
import shlex
from subprocess import Popen, PIPE

# creating permutations
import itertools
import re # regular expressions

from random import shuffle
from time import time

import sys

def get_exitcode_stdout_stderr(cmd):
    """
    Execute the external command and get its exitcode, stdout and stderr.
    """
    args = shlex.split(cmd)
    
    proc = Popen(args, stdout=PIPE, stderr=PIPE)
    out, err = proc.communicate()
    exitcode = proc.returncode
    return exitcode, out, err

def swap(array):
    if (len(array) < 2):
        print('invalid swap')
        exit(1)
    temp = array[0];
    array[0] = array[1]
    array[1] = temp

def push(destination, source):
    if (len(source) == 0):
        print('invalid push')
        exit(1)
    destination = [source[0]] + destination
    source = source[1:]
    return destination, source

def rotate(array):
    if (len(array) < 2):
        print('invalid rotate')
        exit(1)
    array = array[1:] + [array[0]]
    return array

def reverse_rotate(array):
    if (len(array) < 2):
        print('invalid reverse rotate')
        exit(1)
    array = [array[-1]] + array[:-1]
    return array

def perform_operation(first, second, operation):
    if (operation == 'sa'):
        swap(first)
    elif (operation == 'sb'):
        swap(second)
    elif (operation == 'ss'):
        swap(first)
        swap(second)
    elif (operation == 'pa'):
        first, second = push(first, second)
    elif (operation == 'pb'):
        second, first = push(second, first)
    elif (operation == 'ra'):
        first = rotate(first)
    elif (operation == 'rb'):
        second = rotate(second)
    elif (operation == 'rr'):
        first = rotate(first)
        second = rotate(second)
    elif (operation == 'rra'):
        first = reverse_rotate(first)
    elif (operation == 'rrb'):
        second = reverse_rotate(second)
    elif (operation == 'rrr'):
        first = reverse_rotate(first)
        second = reverse_rotate(second)
    else:
        print('invalid operation: |' + str(operation) + '|')
        exit(1)
    return first, second

def is_correct(permutation, output, should_print=1):
    output = output[:-1]
    if (output == "Error"):
        print("oops");
        exit(1);
    output = output.split(" ")
    permutation = list(permutation)
    first = list(permutation)
    second = []
    if not output[0] == '':
        for operation in output:
            first, second = perform_operation(first, second, operation)
    if (len(second)):
        print('length of second after operations is not 0')
        exit(1)
    goodness = True
    for i in range(len(first) - 1):
        if (first[i] > first[i + 1]):
            print('not sorted at end of operations for input: '
                  + str(list(permutation)) + ' and output ' + str(output))
            goodness = False
            break
    if (goodness):
        if (should_print):
            print('good :: length = ' + str(len(output)))
    else:
        print("not good!")
        exit(1)
    return len(output)

def convert_permutation_to_arguments(array):
    return re.sub('[(),]', '', str(array))

def tester_num_arguments(num_args, should_print=1):
    """
    tests push_swap for all possible inputs with num_args arguments
    """
    permutation_count = len(list(itertools.permutations(
                                [i for i in range(num_args)])))
    print("about to test " + str(num_args) + " argument permutations")
    i = 0
    for permutation in itertools.permutations([i for i in range(num_args)]):
        cmd = './push_swap ' + convert_permutation_to_arguments(permutation);
        if (should_print):
            print('testing "' + str(cmd) + '" ', end="")
        begin_time = time()
        exitcode, out, err = get_exitcode_stdout_stderr(cmd)
        end_time = time()
        if (should_print):
            print("time = " + str(end_time - begin_time)[:7] + "\t", end = " ")
        is_correct(permutation, out, should_print);
        if (i % 50 == 0):
            print("tested " + str(i) + " of " + str(permutation_count))
        i += 1

def test_thingy(thingy, should_print=1):
    # important not to include is_correct in timing because it takes N^2 time
    cmd = './push_swap ' + convert_permutation_to_arguments(thingy)[1:-1]
    begin_time = time()
    exitcode, out, err = get_exitcode_stdout_stderr(cmd)
    end_time = time()
    if (len(err)):
        print(err)
    output_length = is_correct(thingy, out, should_print);
    return end_time - begin_time, output_length

def test_randoms(num_args, number_to_test, should_print=1):
    total_time = 0
    lengths = []
    for i in range(number_to_test):
        thingy = [i for i in range(num_args)]
        shuffle(thingy)
        thing_time, thing_length = test_thingy(thingy, should_print)
        total_time += thing_time
        lengths.append(thing_length)
    return total_time, sum(lengths) / float(len(lengths))

def generate_spreadsheet_data(low, high, step, number_of_tests):
    for i in range(low, high, step):
        time_taken, average_length = test_randoms(i, number_of_tests, 0)
        print(str(i) + ' arguments took '
              + str(time_taken / number_of_tests)
              + ' seconds per test and average length = ' + str(average_length))

# Actual code

print("about to test all possible inputs up to 7 numbers")
print()
for i in range(1, 8):
    tester_num_arguments(i, 0);
    print()

print("done with testing all argument permutations between 1 and 7");

print()
print()
tests_to_run = 5
print("The following will create a random input with a given number of elements " + str(tests_to_run) + " times and average the running time and output length for those calls.")
print("Place the following in the spreadsheet: ")
print()
# (low value, high value, step, number of tests to run per number of arguments)
generate_spreadsheet_data(50, 2001, 50, tests_to_run)
print()
print("spreadsheet link: https://docs.google.com/spreadsheets/d/1yJpweZx_brf2LFbZkqXIxVdw681016XiLf9U3HxJUwI/edit?usp=sharing")
