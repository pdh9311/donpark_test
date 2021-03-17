#! /bin/bash

#42TESTER-GNL, Get_Next_Line_Tester
cp get_next_line/junghan/get_next_line.c ./ 
cp get_next_line/junghan/get_next_line_utils.c ./
cp get_next_line/junghan/get_next_line.h ./

#42cursus_gnl_tests
chmod 777 ./42cursus_gnl_tests/compile.sh
chmod 777 ./42cursus_gnl_tests/compile_and_run.sh
chmod 777 ./42cursus_gnl_tests/run.sh
mkdir ./42cursus_gnl_tests/get_next_line
cp get_next_line/junghan/get_next_line.c ./42cursus_gnl_tests/get_next_line/ 
cp get_next_line/junghan/get_next_line_utils.c ./42cursus_gnl_tests/get_next_line/ 
cp get_next_line/junghan/get_next_line.h ./42cursus_gnl_tests/get_next_line/ 

#GNL_lover
cp get_next_line/junghan/get_next_line.c GNL_lover/copy_in_here_GNL_files/
cp get_next_line/junghan/get_next_line_utils.c GNL_lover/copy_in_here_GNL_files/
cp get_next_line/junghan/get_next_line.h GNL_lover/copy_in_here_GNL_files/

#gnlkiller
cp get_next_line/junghan/get_next_line.c gnlkiller/
cp get_next_line/junghan/get_next_line_utils.c gnlkiller/
cp get_next_line/junghan/get_next_line.h gnlkiller/
