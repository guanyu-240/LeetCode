# Read from the file file.txt and print its transposed content to stdout.
file="file.txt"
while read -a line
do
    for ((i=0; i<"${#line[@]}"; i++))
    do
        [ "${output[i]}" == "" ] && 
            output[$i]="${line[i]}" ||
            output[$i]="${output[i]} ${line[i]}"
    done
done < $file

for ((i=0; i<${#output[@]}; i++))
do
    echo "${output[i]}"
done
