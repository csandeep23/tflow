#include<iostream>
#include "pth.h"

int pth::*print_threadindex(void *tid){
	return 0;
}

int pth::create_threads(int cnt){
	for(int i=0;i<cnt;i++){
		std::cout << "Creating thread #" << i << std::endl;
	}
	return 1;
}

