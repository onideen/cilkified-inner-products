
#INC=/home/beta/cilk/include/cilk
INC=/usr/local/bin/cilk

innerproduct: innerproduct.cpp submit.cpp
	cilk++ -fcilkscreen -o innerproduct innerproduct.cpp submit.cpp -I $(INC) -lrt
clean: 
	rm innerproduct

