#! /bin/bash

cp pipex.h pipex_bonus.h
cp cmd_execve.c cmd_execve_bonus.c
cp here_doc.c here_doc_bonus.c
cp main.c main_bonus.c
cp pipe.c pipe_bonus.c
cp redirect.c redirect_bonus.c
cp run_cmd_mid.c run_cmd_mid_bonus.c
cp run_cmd1.c run_cmd1_bonus.c
cp run_cmdn.c run_cmdn_bonus.c
cp run_only_cmd1.c run_only_cmd1_bonus.c
cp util.c util_bonus.c

sed -i 's/pipex\.h/pipex_bonus\.h/' pipex_bonus.h

sed -i 's/cmd_execve\.c/cmd_execve_bonus\.c/' cmd_execve_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' cmd_execve_bonus.c

sed -i 's/here_doc\.c/here_doc_bonus\.c/' here_doc_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' here_doc_bonus.c

sed -i 's/main\.c/main_bonus\.c/' main_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' main_bonus.c

sed -i 's/pipe\.c/pipe_bonus\.c/' pipe_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' pipe_bonus.c

sed -i 's/redirect\.c/redirect_bonus\.c/' redirect_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' redirect_bonus.c

sed -i 's/run_cmd_mid\.c/run_cmd_mid_bonus\.c/' run_cmd_mid_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' run_cmd_mid_bonus.c

sed -i 's/run_cmd1\.c/run_cmd1_bonus\.c/' run_cmd1_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' run_cmd1_bonus.c

sed -i 's/run_cmdn\.c/run_cmdn_bonus\.c/' run_cmdn_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' run_cmdn_bonus.c

sed -i 's/run_only_cmd1\.c/run_only_cmd1_bonus\.c/' run_only_cmd1_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' run_only_cmd1_bonus.c

sed -i 's/util\.c/util_bonus\.c/' util_bonus.c
sed -i 's/pipex\.h/pipex_bonus\.h/' util_bonus.c
