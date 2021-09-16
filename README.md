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
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ') ; ./push_swap $ARG 
ARG="3 249 306 124 111 428 436 79 215 131 190 485 418 494 354 261 232 291 365 305 439 143 324 403 213 150 469 67 338 343 198 172 136 164 117 54 132 187 93 5 295 167 208 63 479 256 431 202 15 217 432 175 239 385 152 313 464 38 90 423 471 452 99 72 170 59 48 138 219 129 440 270 284 470 301 348 317 483 103 139 70 416 251 281 447 406 489 65 240 475 88 11 499 427 268 462 243 177 244 300" ; ./push_swap $ARG | ./checker_scarboni $ARG ; ./push_swap $ARG | ./checker_linux $ARG 
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ') ; ./push_swap $ARG | ./checker_scarboni $ARG ; ./push_swap $ARG | ./checker_linux $ARG ; echo $ARG

$ARG ARG="0 1 2 3" ; ./push_swap $ARG | ./checker_scarboni $ARG ; ./push_swap $ARG | ./checker_linux $ARG ; ./push_swap $ARG