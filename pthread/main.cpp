#define THREAD_MAX 5

#include<iostream>
#include<pthread.h>
#include<atomic>
#include "pth.h"

using namespace std;

atomic_flag print_lock = ATOMIC_FLAG_INIT;

void *print_random(void *tid) {
	while (print_lock.test_and_set(memory_order_acquire));
	cout << "This is from thread #" << (long) tid << endl;
	print_lock.clear(memory_order_acquire);
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	int tret;
	long i;
	cout << "Testing the pthreads" << endl;

	// Section of the code where the new cpp files are used
	pth p;
	cout << p.create_threads(THREAD_MAX) << endl;

	pthread_t th[THREAD_MAX];

	for (i = 0; i < THREAD_MAX; i++) {
		tret = pthread_create(&th[i], NULL, print_random, (void *) i);
		if (tret) {
			cout << "-E- " << argv[0] << ": The thread " << i
					<< " has failed. tret = " << tret << endl;
		}
	}
	pthread_exit(NULL);
	return 0;
}
