#!/bin/bash

ARG="4 67 3 87 23"
COUNT=0
function unit_test ()
{
	echo "Test:"$COUNT
	echo ""
	echo "Test:"$COUNT" ARGS: "$ARG>> result 2>&1
	echo "" >> result 2>&1
	./push_swap $ARG >> result 2>&1
	valgrind --leak-check=full ./push_swap $ARG
	echo "" >> result 2>&1
	((COUNT=COUNT+1))
}

function testeur ()
{
	echo "Start script" > result
	echo "Start script"
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

make  && testeur