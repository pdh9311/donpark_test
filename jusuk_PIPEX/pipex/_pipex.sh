#! /bin/bash

# echo -e "\n\033[31m""출력할 문자""\033[0m"
# 31(빨강), 32(초록), 33(노랑), 34(파랑), 35(보라), 36(하늘)
# wc, rev
echo -e "\n\033[33m""./pipex infile wc rev outfile && cat outfile""\033[0m"
./pipex infile wc rev outfile && cat outfile
echo -e "\033[32m""< infile wc | rev > outfile && cat outfile""\033[0m"
exec < infile wc | rev > outfile && cat outfile
# grep a, rev
echo -e "\n\033[33m""./pipex infile "grep a" rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev > outfile && cat outfile
# grep 1, rev
echo -e "\n\033[33m""./pipex infile "grep 1" rev outfile && cat outfile""\033[0m"
./pipex infile "grep 1" rev outfile && cat outfile
echo -e "\033[32m""< infile grep 1 | rev > outfile && cat outfile""\033[0m"
exec < infile grep 1 | rev > outfile && cat outfile
# grep A, rev
echo -e "\n\033[33m""./pipex infile "grep A" rev outfile && cat outfile""\033[0m"
./pipex infile "grep A" rev outfile && cat outfile
echo -e "\033[32m""< infile grep A | rev > outfile && cat outfile""\033[0m"
exec < infile grep A | rev > outfile && cat outfile
# grep A, rev, wc
echo -e "\n\033[33m""./pipex infile "grep A" rev wc outfile && cat outfile""\033[0m"
./pipex infile "grep A" rev wc outfile && cat outfile
echo -e "\033[32m""< infile grep A | rev | wc> outfile && cat outfile""\033[0m"
exec < infile grep A | rev | wc > outfile && cat outfile
# wc, wc, wc, wc
echo -e "\n\033[33m""./pipex infile wc wc wc wc  outfile && cat outfile""\033[0m"
./pipex infile wc wc wc wc outfile && cat outfile
echo -e "\033[32m""< infile wc | wc | wc | wc > outfile && cat outfile""\033[0m"
exec < infile wc | wc | wc | wc > outfile && cat outfile
# grep a, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev > outfile && cat outfile
# grep a, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev | rev | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev, rev, rev, rev, rev
# grep a, rev, rev, rev, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev rev rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev rev rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev, rev, rev, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev rev rev rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev rev rev rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile
# grep a, rev, rev, rev, rev, rev, rev, rev, rev, rev
echo -e "\n\033[31m""./pipex infile "grep a" rev rev rev rev rev rev rev rev rev outfile && cat outfile""\033[0m"
./pipex infile "grep a" rev rev rev rev rev rev rev rev rev outfile && cat outfile
echo -e "\033[32m""< infile grep a | rev | rev | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile""\033[0m"
exec < infile grep a | rev | rev | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile
