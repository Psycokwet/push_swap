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

	echo "Naked output" >> combinaison 2>&1
	echo -e "$RESULT" >> combinaison 2>&1
	echo "Naked output" >> result 2>&1
	echo -e "$RESULT" >> result 2>&1
	echo "count lines" >> result 2>&1
	echo -e "$RESULT" | wc -l >> result 2>&1
	
	echo "$RESULT" > tmp_file
	sed -i '${/^$/d}' tmp_file
	echo "checker output" >> result 2>&1
	cat tmp_file | ./checker_linux $ARG >> result 2>&1
	echo "my checker output" >> result 2>&1
	cat tmp_file | ./checker_scarboni $ARG >> result 2>&1
	# valgrind --leak-check=full ./push_swap $ARG
	echo "" >> result 2>&1
	((COUNT=COUNT+1))
	rm tmp_file
}



function testeur ()
{
	echo "Start script" > result

	ARG="0 1 2 3" 
	unit_test
	ARG="0 1 3 2" 
	unit_test
	ARG="0 2 1 3" 
	unit_test
	ARG="0 2 3 1" 
	unit_test
	ARG="0 3 1 2" 
	unit_test
	ARG="0 3 2 1" 
	unit_test
	ARG="1 0 2 3" 
	unit_test
	ARG="1 0 3 2" 
	unit_test
	ARG="1 2 0 3" 
	unit_test
	ARG="1 2 3 0" 
	unit_test
	ARG="1 3 0 2" 
	unit_test
	ARG="1 3 2 0" 
	unit_test
	ARG="2 0 1 3" 
	unit_test
	ARG="2 0 3 1" 
	unit_test
	ARG="2 1 0 3" 
	unit_test
	ARG="2 1 3 0" 
	unit_test
	ARG="2 3 1 0" 
	unit_test
	ARG="2 3 0 1" 
	unit_test
	ARG="3 0 1 2" 
	unit_test
	ARG="3 0 2 1" 
	unit_test
	ARG="3 1 0 2" 
	unit_test
	ARG="3 1 2 0" 
	unit_test
	ARG="3 2 0 1" 
	unit_test
	ARG="3 2 1 0" 
	unit_test

	ARG="4 0 1 2 3" 
	unit_test
	ARG="4 0 1 3 2" 
	unit_test
	ARG="4 0 2 1 3" 
	unit_test
	ARG="4 0 2 3 1" 
	unit_test
	ARG="4 0 3 1 2" 
	unit_test
	ARG="4 0 3 2 1" 
	unit_test
	ARG="4 1 0 2 3" 
	unit_test
	ARG="4 1 0 3 2" 
	unit_test
	ARG="4 1 2 0 3" 
	unit_test
	ARG="4 1 2 3 0" 
	unit_test
	ARG="4 1 3 0 2" 
	unit_test
	ARG="4 1 3 2 0" 
	unit_test
	ARG="4 2 0 1 3" 
	unit_test
	ARG="4 2 0 3 1" 
	unit_test
	ARG="4 2 1 0 3" 
	unit_test
	ARG="4 2 1 3 0" 
	unit_test
	ARG="4 2 3 1 0" 
	unit_test
	ARG="4 2 3 0 1" 
	unit_test
	ARG="4 3 0 1 2" 
	unit_test
	ARG="4 3 0 2 1" 
	unit_test
	ARG="4 3 1 0 2" 
	unit_test
	ARG="4 3 1 2 0" 
	unit_test
	ARG="4 3 2 0 1" 
	unit_test
	ARG="4 3 2 1 0" 
	unit_test


	ARG="0 4 1 2 3" 
	unit_test
	ARG="0 4 1 3 2" 
	unit_test
	ARG="0 4 2 1 3" 
	unit_test
	ARG="0 4 2 3 1" 
	unit_test
	ARG="0 4 3 1 2" 
	unit_test
	ARG="0 4 3 2 1" 
	unit_test
	ARG="1 4 0 2 3" 
	unit_test
	ARG="1 4 0 3 2" 
	unit_test
	ARG="1 4 2 0 3" 
	unit_test
	ARG="1 4 2 3 0" 
	unit_test
	ARG="1 4 3 0 2" 
	unit_test
	ARG="1 4 3 2 0" 
	unit_test
	ARG="2 4 0 1 3" 
	unit_test
	ARG="2 4 0 3 1" 
	unit_test
	ARG="2 4 1 0 3" 
	unit_test
	ARG="2 4 1 3 0" 
	unit_test
	ARG="2 4 3 1 0" 
	unit_test
	ARG="2 4 3 0 1" 
	unit_test
	ARG="3 4 0 1 2" 
	unit_test
	ARG="3 4 0 2 1" 
	unit_test
	ARG="3 4 1 0 2" 
	unit_test
	ARG="3 4 1 2 0" 
	unit_test
	ARG="3 4 2 0 1" 
	unit_test
	ARG="3 4 2 1 0" 
	unit_test

	ARG="0 1 4 2 3" 
	unit_test
	ARG="0 1 4 3 2" 
	unit_test
	ARG="0 2 4 1 3" 
	unit_test
	ARG="0 2 4 3 1" 
	unit_test
	ARG="0 3 4 1 2" 
	unit_test
	ARG="0 3 4 2 1" 
	unit_test
	ARG="1 0 4 2 3" 
	unit_test
	ARG="1 0 4 3 2" 
	unit_test
	ARG="1 2 4 0 3" 
	unit_test
	ARG="1 2 4 3 0" 
	unit_test
	ARG="1 3 4 0 2" 
	unit_test
	ARG="1 3 4 2 0" 
	unit_test
	ARG="2 0 4 1 3" 
	unit_test
	ARG="2 0 4 3 1" 
	unit_test
	ARG="2 1 4 0 3" 
	unit_test
	ARG="2 1 4 3 0" 
	unit_test
	ARG="2 3 4 1 0" 
	unit_test
	ARG="2 3 4 0 1" 
	unit_test
	ARG="3 0 4 1 2" 
	unit_test
	ARG="3 0 4 2 1" 
	unit_test
	ARG="3 1 4 0 2" 
	unit_test
	ARG="3 1 4 2 0" 
	unit_test
	ARG="3 2 4 0 1" 
	unit_test
	ARG="3 2 4 1 0" 
	unit_test


	ARG="0 1 2 4 3" 
	unit_test
	ARG="0 1 3 4 2" 
	unit_test
	ARG="0 2 1 4 3" 
	unit_test
	ARG="0 2 3 4 1" 
	unit_test
	ARG="0 3 1 4 2" 
	unit_test
	ARG="0 3 2 4 1" 
	unit_test
	ARG="1 0 2 4 3" 
	unit_test
	ARG="1 0 3 4 2" 
	unit_test
	ARG="1 2 0 4 3" 
	unit_test
	ARG="1 2 3 4 0" 
	unit_test
	ARG="1 3 0 4 2" 
	unit_test
	ARG="1 3 2 4 0" 
	unit_test
	ARG="2 0 1 4 3" 
	unit_test
	ARG="2 0 3 4 1" 
	unit_test
	ARG="2 1 0 4 3" 
	unit_test
	ARG="2 1 3 4 0" 
	unit_test
	ARG="2 3 1 4 0" 
	unit_test
	ARG="2 3 0 4 1" 
	unit_test
	ARG="3 0 1 4 2" 
	unit_test
	ARG="3 0 2 4 1" 
	unit_test
	ARG="3 1 0 4 2" 
	unit_test
	ARG="3 1 2 4 0" 
	unit_test
	ARG="3 2 0 4 1" 
	unit_test
	ARG="3 2 1 4 0" 
	unit_test


	ARG="0 1 2 3 4" 
	unit_test
	ARG="0 1 3 2 4" 
	unit_test
	ARG="0 2 1 3 4" 
	unit_test
	ARG="0 2 3 1 4" 
	unit_test
	ARG="0 3 1 2 4" 
	unit_test
	ARG="0 3 2 1 4" 
	unit_test
	ARG="1 0 2 3 4" 
	unit_test
	ARG="1 0 3 2 4" 
	unit_test
	ARG="1 2 0 3 4" 
	unit_test
	ARG="1 2 3 0 4" 
	unit_test
	ARG="1 3 0 2 4" 
	unit_test
	ARG="1 3 2 0 4" 
	unit_test
	ARG="2 0 1 3 4" 
	unit_test
	ARG="2 0 3 1 4" 
	unit_test
	ARG="2 1 0 3 4" 
	unit_test
	ARG="2 1 3 0 4" 
	unit_test
	ARG="2 3 1 0 4" 
	unit_test
	ARG="2 3 0 1 4" 
	unit_test
	ARG="3 0 1 2 4" 
	unit_test
	ARG="3 0 2 1 4" 
	unit_test
	ARG="3 1 0 2 4" 
	unit_test
	ARG="3 1 2 0 4" 
	unit_test
	ARG="3 2 0 1 4" 
	unit_test
	ARG="3 2 1 0 4" 
	unit_test

}
make bonus && testeur