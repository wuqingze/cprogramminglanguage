for f in $(ls | grep .c)
do
    when-changed $f "cc $f >> log; echo --------------$f >> log; ./a.out >> log" &
    echo $f
done
