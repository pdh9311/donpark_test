./printfdel.sh
cd ft_printf
# PFT					[./enable-test 42(84), disable-test bonus , ./reset-to-default-enabled-tests , ./test]
git clone https://github.com/gavinfielder/pft.git pft && echo "pft/" >> .gitignore
cd pft
./disable-test bonus
./test
