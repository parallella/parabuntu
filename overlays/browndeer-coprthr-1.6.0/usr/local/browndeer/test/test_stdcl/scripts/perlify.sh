#!/bin/sh

awk -F'\n' '{ sub(/^[ \t]*/,""); gsub(/\\/,"\\\\"); gsub(/\"/,"\\\""); \
	printf "printf \"";  \
	printf "%s",$1; printf "\\n\";\n"; }' $1


