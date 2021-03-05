#!/bin/bash

currentDir=""
if [ $1 ]
then
	currentDir="$1"
fi

resultFilesPathes=()
findStrings=${@:2}

getFilesInDir () {
	readarray -t files < <(ls $2)

	local shiftNum=0
	if [ $1 ]
	then
		local shiftNum=$1
	fi
	local shiftNum=$((shiftNum+1))

	for file in "${files[@]}"; do
		# creating shift with dots
		for (( i = 0; i < $shiftNum; i++ )); do
			printf "\e[1;30m....\e[0m"
		done

		# searchin in file or path/file
		local filePath=$file
		if [ $2 ]
			then
				local filePath="$2$file"
		fi

		# Find by regex in file
		found=0
		for fileSearch in $findStrings; do
			if [ $(echo $file | grep $fileSearch) ];
			then
				found=1
				break
			fi
		done

		if [ -d $filePath ]
		then

			if [ $found -eq 1 ]; then
				printf "\e[1;5m%s\e[0m\n" $file
			else
				printf "\e[1;34m%s\e[0m\n" $file
			fi

			# Starting again with new path
			if [ $2 ]
				then
					getFilesInDir $shiftNum "$2/$file/"
				else
					getFilesInDir $shiftNum "$file/"
			fi
		elif [[ -f $filePath ]]; then

			if [ $found -eq 1 ]; then
				printf "\e[1;5m%s\e[0m\n" $file
				resultFilesPathes+=($filePath)
			else
				printf "\e[1;33m%s\e[0m\n" $file
			fi
		fi
	done
}

echo $(pwd)" with path /$currentDir"
getFilesInDir 0 $currentDir

for i in "${!resultFilesPathes[@]}"; do
	filePath=$"${resultFilesPathes[$i]}"
	printf "%s\n" "$filePath"
	printf "%s\n" "$(cat --squeeze-blank -n $filePath)"
done