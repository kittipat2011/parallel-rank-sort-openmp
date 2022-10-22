# parallel-rank-sort-openmp
This repository is part of the IITCS443 Parallel and Distributed Systems course. The purpose of this repository is to provide a better understanding of parallel rank sort in OpenMP. Our group will do our best not to make any mistakes or give our readers false information. Thank you for your interest and please enjoy our work.

Instruction to run our program.
1. compile the program using command:
	gcc -o Rank_Sort_openmp -fopenmp Rank_Sort_openmp.c
2. Run the program using command:
	./Rank_Sort_openmp
3. Input the size of the array
4. Input the number of threads
5. wait for the result (wait time depend on the size of array)
6. obtain the result including:
	- sequential time to sort the integers
	- parallel time to sort the integers
	- speed up for the input array(using time_in_sequential/time_in_parallel)


For Example
1. gcc -o Rank_Sort_openmp -fopenmp Rank_Sort_openmp.c
2. ./Rank_Sort_openmp
3. 100000
4. 16
5. obtain result.
6. end of the program.


Member of the project
1. 6388019 Sorawanan Jeamjantarasakhon
2. 6388119 Kittipat Arpanon
