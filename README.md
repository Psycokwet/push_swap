# push_swap
42

test : 
cd project
bash basic_test.sh

test correction :
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 23 67 87"; ./push_swap $ARG | ./checker_linux $ARG

bash generate_array.sh 5 3


./push_swap $(shuf -i 1-500 -n 100 | tr '\n' ' ')
ou
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ') && ./push_swap 

$ARG ARG="0 1 2 3" ; ./push_swap $ARG | ./checker_scarboni $ARG ; ./push_swap $ARG | ./checker_linux $ARG ; ./push_swap $ARG