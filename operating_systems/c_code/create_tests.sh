#!/bin/bash


filename="my_file"
content="Hello, World"
for i in {1..5}
do
	echo "$content $i" > "$filename$i.txt"
done
