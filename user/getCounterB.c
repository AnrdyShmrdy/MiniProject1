#include "types.h"
#include "user.h"

//This function uses system call partBCount() to get the number of system calls
int main(){
	printf(1, "There have been %d system calls\n", partBCount());
	exit();
}
