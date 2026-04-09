#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime() {
    struct timeval t; // t.tv_sec is seconds, t.tv_usec is microseconds
    int rc = gettimeofday(&t, NULL); // gettimeofday() returns 0 if OK, -1 on error
    assert(rc == 0); // assert() aborts the program if its argument is false
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong)
	; // do nothing in loop
}

#endif // __common_h__