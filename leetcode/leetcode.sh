if [ -f $1 ]; then
    git add $1
    message="leetcode: `echo $1 | sed 's/_/-/g' | sed 's/.cpp//g' | sed 's/\./ /g'`"
    git commit -m "$message" 
else
    echo 'No such file or directory'
    exit -1
fi
