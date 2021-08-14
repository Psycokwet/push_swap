#!/bin/bash

ARG=""
COUNT=0
function unit_test ()
{
	echo "Test:"$COUNT
	echo ""
	echo "Test:"$COUNT" ARGS: "$ARG>> result 2>&1
	echo "" >> result 2>&1
	RESULT=$( ./push_swap $ARG)

	echo "Naked output" >> result 2>&1
	echo -e "$RESULT" >> result 2>&1
	echo "$RESULT" > tmp_file
	sed -i '${/^$/d}' tmp_file
	echo "checker output" >> result 2>&1
	cat tmp_file | ./checker_linux $ARG >> result 2>&1
	echo "my checker output" >> result 2>&1
	cat tmp_file | ./checker_scarboni $ARG >> result 2>&1
	valgrind --leak-check=full ./push_swap $ARG
	echo "" >> result 2>&1
	((COUNT=COUNT+1))
	rm tmp_file
}

function testeur ()
{
	echo "Start script" > result

	echo "---Push_swap identité---" >> result
	echo "" >> result
	ARG=""
	unit_test
	
	ARG="42"
	unit_test

	ARG="0 1 2 3"
	unit_test

	ARG="0 1 2 3 4 5 6 7 8 9"
	unit_test
	
	echo "---Push_swap tests simples---" >> result
	echo "" >> result

	ARG="2 1 0"
	unit_test
	
	echo "---Push_swap d'autres tests tout aussi simples---" >> result
	echo "" >> result

	ARG="1 5 2 4 3"
	unit_test

	echo "Enter 5 parameters of your choice"
	ARG=$(cat)
	unit_test

	echo "---Push_swap tests intermédiairs---" >> result
	echo "" >> result

	ARG="100 PARAMS AU CHOIX"
	unit_test

	echo "---Push_swap tests avancé---" >> result
	echo "" >> result

	ARG="500 PARAMS AU CHOIX"
	unit_test

	echo "---Push_swap tests PERSOS---" >> result
	echo "" >> result

	ARG="4 67 3 87 23"
	unit_test

	ARG="2 1"
	unit_test

	ARG="1 2"
	unit_test

	ARG="1 2 3"
	unit_test

	ARG="1 3 2"
	unit_test

	ARG="3 1 2"
	unit_test

	ARG="3 2 1"
	unit_test

	ARG="2 3 1"
	unit_test

	ARG="2 1 3"
	unit_test

	ARG="-1 5 2 4 3"
	unit_test

	ARG="--1 5 2 4 3"
	unit_test

	ARG="3 4 23 67 87"
	unit_test

	ARG="3  2147483647 2 32147483647 -2147483648 b"
	unit_test

	ARG="3  2147483647 2 b"
	unit_test

	ARG="3  2147483647 2 5 5"
	unit_test

	ARG="3  2147483647 2 5 3"
	unit_test

}

make bonus && testeur