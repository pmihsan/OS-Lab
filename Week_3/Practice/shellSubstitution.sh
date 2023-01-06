echo -e "Shell Substitutions\n"
# You can sustitute variables with any command using backquote(`)

DATE=`date`
echo -e "Date - $DATE\n"

USER=`whoami`
echo -e "User logged in as - $USER\n"

UP=`date -u ; uptime`
echo -e "Uptime - $UP\n"

LIST=`ls`
echo -e "Files in current directory - $LIST\n"

FILE_COUNT=`ls | wc -l`
echo -e "No of files in current directory - $FILE_COUNT\n"

PRINT_PWD=`pwd`
echo "Current working directory - $PRINT_PWD\n"



