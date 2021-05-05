#! /usr/bin/python

from jobs_ok import *


def test1():
	print(jobs_ok( 
	[
	['aziz', 'collins', 'vieira', 'liu'],
	['davis', 'ericson', 'kelly', 'singh'],
	['fitzgerald', 'gutierrez', 'martinez', 'tortorella'],
	['nguyen', 'jones', 'patel', 'zimmerman']],

	[
	['aziz', 1, 0, 0],
	['blumenthal', 0, 1, 1],
	['collins', 1, 1, 1],
	['davis', 1, 0, 0],
	['ericson', 1, 0, 0],
	['fitzgerald', 1, 0, 1],
	['gutierrez', 1, 0, 1],
	['jones', 1, 1, 1],
	['kelly', 0, 1, 1],
	['liu', 1, 0, 1],
	['martinez', 0, 1, 1],
	['nguyen', 1, 0, 0],
	['patel', 1, 1, 1],
	['qureshi', 1, 1, 0],
	['rodriguez', 1, 0, 0],
	['singh', 0, 1, 1],
	['tortorella', 0, 0, 1],
	['vieira', 0, 1, 0],
	['young', 0, 1, 0],
	['zimmerman', 1, 1, 1]]))
# True (example 1 from web)

def test2():
	print(jobs_ok( 
	[
	['young', 'collins', 'vieira', 'liu'],
	['davis', 'ericson', 'kelly', 'singh'],
	['fitzgerald', 'gutierrez', 'martinez', 'tortorella'],
	['nguyen', 'jones', 'patel', 'zimmerman']],
   
	[
	['aziz', 1, 0, 0],
	['blumenthal', 0, 1, 1],
	['collins', 1, 1, 1],
	['davis', 1, 0, 0],
	['ericson', 1, 0, 0],
	['fitzgerald', 1, 0, 1],
	['gutierrez', 1, 0, 1],
	['jones', 1, 1, 1],
	['kelly', 0, 1, 1],
	['liu', 1, 0, 1],
	['martinez', 0, 1, 1],
	['nguyen', 1, 0, 0],
	['patel', 1, 1, 1],
	['qureshi', 1, 1, 0],
	['rodriguez', 1, 0, 0],
	['singh', 0, 1, 1],
	['tortorella', 0, 0, 1],
	['williams', 1, 0, 0],
	['vieira', 0, 1, 0],
	['young', 0, 1, 0],
	['zimmerman', 1, 1, 1]]))

# False: young unqualified - phones.  Example 2 from web

def test3():
	print(jobs_ok( 
	[
	['aziz', 'collins', 'vieira', 'liu'],
	['davis', 'aziz', 'kelly', 'singh'],
	['fitzgerald', 'gutierrez', 'martinez', 'tortorella'],
	['nguyen', 'jones', 'patel', 'zimmerman']],
   
	[
	['aziz', 1, 0, 0],
	['blumenthal', 0, 1, 1],
	['collins', 1, 1, 1],
	['davis', 1, 0, 0],
	['ericson', 1, 0, 0],
	['fitzgerald', 1, 0, 1],
	['gutierrez', 1, 0, 1],
	['jones', 1, 1, 1],
	['kelly', 0, 1, 1],
	['liu', 1, 0, 1],
	['martinez', 0, 1, 1],
	['nguyen', 1, 0, 0],
	['patel', 1, 1, 1],
	['qureshi', 1, 1, 0],
	['rodriguez', 1, 0, 0],
	['singh', 0, 1, 1],
	['tortorella', 0, 0, 1],
	['williams', 1, 0, 0],
	['vieira', 0, 1, 0],
	['young', 0, 1, 0],
	['zimmerman', 1, 1, 1]]))

# False: aziz has 2 shifts.  Example 3 from web

def test4():
	print(jobs_ok( 
	[
	['aziz', 'collins', 'vieira', 'liu'],
	['davis', 'aziz', 'kelly', 'singh'],
	['gutierrez', 'gutierrez', 'martinez', 'tortorella'],
	['nguyen', 'jones', 'patel', 'zimmerman']],
   
	[
	['aziz', 1, 0, 0],
	['blumenthal', 0, 1, 1],
	['collins', 1, 1, 1],
	['davis', 1, 0, 0],
	['ericson', 1, 0, 0],
	['fitzgerald', 1, 0, 1],
	['gutierrez', 1, 0, 1],
	['jones', 1, 1, 1],
	['kelly', 0, 1, 1],
	['liu', 1, 0, 1],
	['martinez', 0, 1, 1],
	['nguyen', 1, 0, 0],
	['patel', 1, 1, 1],
	['qureshi', 1, 1, 0],
	['rodriguez', 1, 0, 0],
	['singh', 0, 1, 1],
	['tortorella', 0, 0, 1],
	['williams', 1, 0, 0],
	['vieira', 0, 1, 0],
	['young', 0, 1, 0],
	['zimmerman', 1, 1, 1]]))

# False: gutierrez has 2 jobs in one shift.  Example 4 from web


def test5():
	print(jobs_ok( 
	[
	['park', 'dunbar', 'khan', 'lloyd'],
	['bashir', 'trivedi', 'ramos', 'franklin'],
	['schmidt', 'nakamura', 'andrews', 'chen'],
	['evans', 'goldberg', 'macmillan', 'ortiz']],

	[
	['andrews', 1, 1, 1],
	['bashir', 1, 1, 1],
	['chen', 1, 1, 1],
	['dunbar', 1, 1, 1],
	['evans', 1, 1, 1],
	['franklin', 1, 1, 1],
	['goldberg', 1, 1, 1],
	['jefferson', 1, 1, 1],
	['khan', 1, 1, 1],
	['lloyd', 1, 1, 1],
	['macmillan', 1, 1, 1],
	['nakamura', 1, 1, 1],
	['ortiz', 1, 1, 1],
	['park', 1, 1, 1],
	['ramos', 1, 1, 1],
	['schmidt', 1, 1, 1],
	['trivedi', 1, 1, 1]]))
# True (example 5 from web)

def test6():
	print(jobs_ok( 
	[
	['park', 'dunbar', 'khan', 'lloyd'],
	['bashir', 'trivedi', 'ramos', 'franklin'],
	['schmidt', 'nakamura', 'andrews', 'chen'],
	['evans', 'goldberg', 'macmillan', 'ortiz']],

	[
	['andrews', 1, 1, 1],
	['bashir', 1, 1, 1],
	['chen', 1, 1, 1],
	['dunbar', 1, 1, 1],
	['evans', 1, 1, 1],
	['franklin', 1, 1, 1],
	['goldberg', 1, 1, 1],
	['jefferson', 1, 1, 1],
	['khan', 1, 1, 1],
	['lloyd', 1, 1, 1],
	['macmillan', 1, 0, 1],
	['nakamura', 1, 1, 1],
	['ortiz', 1, 1, 1],
	['park', 1, 1, 1],
	['ramos', 1, 1, 1],
	['schmidt', 1, 1, 1],
	['trivedi', 1, 1, 1]]))
# False (like test5, but macmillan is unqualified to fix computers)

def test7():
	print(jobs_ok( 
	[
	['park', 'dunbar', 'khan', 'lloyd'],
	['bashir', 'trivedi', 'ramos', 'franklin'],
	['schmidt', 'nakamura', 'andrews', 'chen'],
	['evans', 'goldberg', 'macmillan', 'ortiz']],

	[
	['andrews', 1, 1, 1],
	['bashir', 1, 1, 1],
	['chen', 1, 1, 1],
	['dunbar', 1, 1, 1],
	['evans', 1, 1, 1],
	['franklin', 1, 1, 0],
	['goldberg', 1, 1, 1],
	['jefferson', 1, 1, 1],
	['khan', 1, 1, 1],
	['lloyd', 1, 1, 1],
	['macmillan', 1, 1, 1],
	['nakamura', 1, 1, 1],
	['ortiz', 1, 1, 1],
	['park', 1, 1, 1],
	['ramos', 1, 1, 1],
	['schmidt', 1, 1, 1],
	['trivedi', 1, 1, 1]]))
# False (like test5, but franklin is unqualified to fix the network)

print("Test 1 - should be True:  ")
test1()
print()
print("Test 2 - should be False:  ")
test2()
print()
print("Test 3 - should be False:  ")
test3()
print()
print("Test 4 - should be False:  ")
test4()
print()
print("Test 5 - should be True:  ")
test5()
print()
print("Test 6 - should be False:  ")
test6()
print()
print("Test 7 - should be False:  ")
test7()
print()
