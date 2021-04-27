./printfdel.sh
cd ft_printf
make
make clean
# printf-tester			[./test.sh]
git clone https://github.com/AntoineBourin/printf-tester.git
cp libftprintf.a printf-tester
cd printf-tester
chmod 777 test.sh
./test.sh
