#include <stdio.h>
#include "hellomake.h"

int
main()
{

	#ifdef OS_LINUX
	printf("Systéme : Linux\n");
	#endif
	
	//Appel pour une function en une autre archive (hellomake.h)
	myPrintHelloMake();

	return(0);
}
