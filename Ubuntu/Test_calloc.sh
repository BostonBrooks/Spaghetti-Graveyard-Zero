 #!/bin/bash

BGreen='\033[1;32m'
Color_Off='\033[0m'

#while [ 1 == 1 ]
#do

 echo -e "Look, a Tortoise:\n${BGreen}\n       _____     ____\n     /      \  |  o |\n    |        |/ ___\| \n    |_________/     \n    |_|_| |_|_|\n//////////////////////////////////////////////////////////////${Color_Off}\n\nAttempting to compile:\n"

 if gcc\
  ../test/Test_calloc.c\
 -g -lm -w;
  then
    echo "Compile Succeeded:"
    ./a.out
  else
    echo "Compile Failed!"
 #   exit
  fi

#done