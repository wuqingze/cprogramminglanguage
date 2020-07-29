#!/bin/bash
echo ""
echo "$(date '+%YY-%m-%d %H:%M:%S') - $1"
echo ------------------------------------
cc $1
./a.out

