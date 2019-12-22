# DC
DC lab programs externals final list
packages
<p>sudo apt install libopenmp-dev
<p>sudo apt install libopenmpi-dev
<p>sudo apt install libgd-dev
 <p><h3>compiling
 <p>gcc -fopenmp filename.c 
 <p>attach -lm -lgd incase math.h or gd.h is used
<p>mpicc filename.c
 <p> mpirun -np 6 ./a.out
