# push_swap
42

test : 
cd project
bash basic_test.sh

test correction :
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 23 67 87"; ./push_swap $ARG | ./checker_linux $ARG