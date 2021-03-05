#!/bin/bash
INPUT="$1"
OUTPUT="$2"

[ $# -eq 0 ] && { echo "Usage: $0 filename $1 $2"; exit 1; }

[ ! -f $INPUT ] && { echo "$0: file $INPUT not found."; exit 2; }

[ -f $OUTPUT ] && { echo -n > $OUTPUT; }

foundSymbol=1
spaceBefore=0
while IFS= read -r -n1 c
do
	if [ "$c" == "." ] || [ "$c" == "!" ] || [ "$c" == "?" ]; then
		foundSymbol=1
		c="${c} "
		spaceBefore=1
	elif [ $foundSymbol -eq 1 ] && [ "$c" != " " ]; then
		c="${c^}"
		foundSymbol=0
		spaceBefore=0
	fi

	if [ "${c:-1}" == " " ];  then
		if [ $spaceBefore -eq 1 ]; then
			c=""
		fi
		spaceBefore=1
	else
		spaceBefore=0
	fi

	printf "%s" "$c" >> $OUTPUT
done < "$INPUT"

cat $OUTPUT
printf "\n"