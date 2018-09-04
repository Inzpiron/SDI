#include <stdio.h>
#include <rpc/rpc.h>
#include <pthread.h>
#include <unistd.h>
#include "hw.h"
#include "source/lista.h"
/*
   Simple "hello world" program that demonstrates an rpc call.
*/

int my_id;
CLIENT *cl;

void * write_buffer(void * arg) {
	while(1) {
		char * msg = *(getmessage_1(&my_id, cl));
		if(strlen(msg) > 0)
			printf("%s\n", msg);
		printf("vtnc\n");
		usleep(1000*1000);
	}
}

char * create_message(char * str) {
	char * m = malloc(sizeof(1500));
	m[0] = '0' + my_id;
	m[1] = '-';
	strcpy(m+2, str);

	return m;
}



int main (int argc, char *argv[]) {
	/***************************************************************************
	******************************DEFAULT***************************************
	****************************************************************************/
	if (argc != 3) {
		printf("Usage: client hostname\n");
		exit(1);
	}

	cl = clnt_create(argv[1], HELLO_WORLD_PROG, HELLO_WOLRD_VERS, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}
	/****************************************************************************/

	pthread_t t_writebuffer;
	pthread_create(&(t_writebuffer), NULL, write_buffer, NULL);
	my_id = *(getid_1(&argv[2], cl));
	printf("%d\n", my_id);

	char * m = malloc(sizeof(500));
	while(1) {
		scanf("%s", m);
		m = create_message(m);
		newmessage_1(&m, cl);
	}

	/*
	char **p;
	printf("Getting ready to call hello world\n");
	p = hw_1(NULL, cl);

	printf("Back from hello world\n");
	if (p == NULL) {
		clnt_perror(cl,argv[1]);
		exit(1);
	}

	printf("Returned string=%s\n", *p);
	*/
	pthread_join(t_writebuffer, NULL);
	return 0;
}
