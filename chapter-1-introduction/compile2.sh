#!/bin/bash
function f(){
    cc $1
    ./a.out
}

echo ""
echo "$(date '+%YY-%m-%d %H:%M:%S') - $1"
echo ------------------------------------
when-changed $1 f $1

