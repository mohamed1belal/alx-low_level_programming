#!/bin/bash 
gcc -c *.c
ar -rc liball.a *a.o
ranlib liball.a
