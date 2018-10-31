file=$1
v=0

if [ $# -ne 1 ]
then
    echo "$0 NombreDelArchivo"
    exit 1
fi
if [ ! -f $file ]
then
    echo "$file no es un archivo"
    exit 2
fi

exec 3<$0
while read -n 1 c
do
    l="$(echo $c | tr '[A-Z]' '[a-z]')"
    [ "$l" == "a" -o "$l" == "e" -o "$l" == "i" -o "$l" == "o" -o "$l" == "u" ] && (( v++ )) || :
done < $file

echo "Vocales : $v"
