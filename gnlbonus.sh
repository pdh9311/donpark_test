#! /bin/bash

#42TESTER-GNL, Get_Next_Line_Tester
cp get_next_line/get_next_line_bonus.c ./ 
cp get_next_line/get_next_line_utils_bonus.c ./
cp get_next_line/get_next_line_bonus.h ./

#42cursus_gnl_tests
chmod 777 ./42cursus_gnl_tests/compile.sh
chmod 777 ./42cursus_gnl_tests/compile_and_run.sh
chmod 777 ./42cursus_gnl_tests/run.sh
mkdir ./42cursus_gnl_tests/get_next_line
cp get_next_line/get_next_line_bonus.c ./42cursus_gnl_tests/get_next_line/ 
cp get_next_line/get_next_line_utils_bonus.c ./42cursus_gnl_tests/get_next_line/ 
cp get_next_line/get_next_line_bonus.h ./42cursus_gnl_tests/get_next_line/ 

#GNL_lover
cp get_next_line/get_next_line_bonus.c GNL_lover/copy_in_here_GNL_files/
cp get_next_line/get_next_line_utils_bonus.c GNL_lover/copy_in_here_GNL_files/
cp get_next_line/get_next_line_bonus.h GNL_lover/copy_in_here_GNL_files/
#gnlkiller
cp get_next_line/get_next_line_bonus.c gnlkiller/
cp get_next_line/get_next_line_utils_bonus.c gnlkiller/
cp get_next_line/get_next_line_bonus.h gnlkiller/
