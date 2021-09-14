#include "types.h"
#include "user.h"

//This code uses system call partAcount() to see how many times getpid() was called.
int main(){
	printf(1, "getpid() was called %d times\n", partACount());
	exit();
}
