read x
read y
read z

if [ $x == $y ] || [ $x == $z ] || [ $y == $z ];then
    if [ $((x+y)) == $((z*2)) ];then
        echo "EQUILATERAL"
    else
        echo "ISOSCELES"
        fi
else
    echo "SCALENE"
    fi
