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
ARG="289 328 148 423 144 345 171 258 158 84 12 495 324 447 330 21 489 44 457 335 277 130 451 179 460 298 18 186 388 241 384 453 274 134 111 113 240 299 420 6 320 456 90 391 461 318 272 497 428 256 255 433 500 135 188 288 86 161 250 13 363 118 192 231 340 354 449 121 359 25 101 41 88 377 269 199 58 251 39 396 169 123 147 189 285 92 403 491 350 59 466 315 273 293 427 243 499 316 128 278 " ; ./push_swap $ARG | ./checker_linux $ARG 
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ') ; ./push_swap $ARG | ./checker_scarboni $ARG ; ./push_swap $ARG | ./checker_linux $ARG ; echo $ARG

$ARG ARG="0 1 2 3" ; ./push_swap $ARG | ./checker_scarboni $ARG ; ./push_swap $ARG | ./checker_linux $ARG ; ./push_swap $ARG