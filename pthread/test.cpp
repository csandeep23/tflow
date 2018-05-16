#include<iostream>
#include<pthread.h>

#define THREAD_MAX 5

using namespace std;

void *print_random(void *tid) {
    cout << "This is from thread #" << (long)tid << endl;
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    int tret;
    long i;
    cout << "Testing the pthreads" << endl;
    pthread_t th[THREAD_MAX];

    for(i=0;i<THREAD_MAX;i++) {
        tret=pthread_create(&th[i],NULL,print_random,(void *)i);
        if (tret) {
            cout << "-E- " << argv[0] << ": The thread " << i << " has failed. tret = " << tret << endl;
        }
    }
    pthread_exit(NULL); 
    return 0;
}
