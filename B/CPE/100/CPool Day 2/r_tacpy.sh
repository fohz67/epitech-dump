#!/bin/bash
sed "1~2d" | cut -d: -f 1 | rev | sort -r | sed "$MY_LINE1,$MY_LINE2!d" | tr '\n' ',' | sed "s/,/, /g" | sed "s/.$//" | sed "s/.$/.\n/"
