#include <rpc/rpc.h>
#include <unistd.h>
#include "hw.h"
#include "source/lista.h"
/*
   Hello world RPC server -- it just returns the string.
*/


struct msg {
	int msg_id;
	int cli_id;
	char * str;
};
typedef struct msg Msg;

Msg * novaMsg(int msg_id, int cli_id, char * str) {
	Msg * m = malloc(sizeof(Msg));
	m->msg_id = msg_id;
	m->cli_id = cli_id;
	m->str = malloc(1500);
	strcpy(m->str, str);

	return m;
}

void * get_cli_str(char * str, int * cli_id, char * msg) {
	str[1] = '\0';
	*cli_id = atol(str);
	strcpy(msg, str+2);
}

char * client_names[10];
int n_clientes = -1;
LDDE * lista_msg;
int pos_msg = 0;
int pos_cli[10] = {-1};

int * getid_1_svc(char ** arg, struct svc_req *req) {
	if(lista_msg == NULL) {
		printf("[SVR] Criando Lista de mensagens\n");
		lista_msg = listaCriar(sizeof(Msg));
	}
	++n_clientes;
	client_names[n_clientes] = malloc(sizeof(strlen(*arg)));
	strcpy(client_names[n_clientes], *arg);
	printf("[SVR] Nova conexão %s#%d\n", client_names[n_clientes], n_clientes);
	return &n_clientes;
}

void * newmessage_1_svc(char ** arg, struct svc_req *req) {
	int cli_id;
	char msg[1500];
	get_cli_str(*arg, &cli_id, msg);
	listaInserir(lista_msg, novaMsg(pos_msg, cli_id, msg));
	printf("[MSG-%d] %s#%d \"%s\"\n", pos_msg, client_names[cli_id],cli_id,  msg);
	pos_msg++;
}

char * buffer;
char * ret;
char ** getmessage_1_svc(int * cli_id, struct svc_req * req) {
	ret = strdup("\0");
	NoLDDE * no = lista_msg->fimLista;
	if(no == NULL)
		return &ret;

	Msg * m = (Msg *)(no->dados);
	if(m->cli_id != *cli_id) {
		return &(m->str);
	}
	return &ret;

	/*
	if(pos_cli[*cli_id] == pos_msg)
		return NULL;

	buffer = malloc(sizeof(2500));
	NoLDDE * no = lista_msg->inicioLista;
	for(int i = 0; i < pos_cli[*cli_id]; i++)
		no = no->prox;

	return NULL;

	NoLDDE * no = lista_msg->inicioLista;
	while(1) {
		if(((Msg*)no->dados)->cli_id != *cli_id) {
			strcat(buffer, client_names[((Msg*)no->dados)->cli_id]);
			strcat(buffer, strdup("> "));
			strcat(buffer, ((Msg*)no->dados)->str);
			strcat(buffer, strdup("\n"));
		}
		if(no->prox == NULL){
			break;
		}
		//pos_cli[*cli_id]++;
		no = no->prox;
	}

	return &buffer;
	*/
}

char **hw_1_svc(void *a, struct svc_req *req) {
	printf("NEW CONNECTION: %d\n", n_clientes);
	printf("FODEO\n");
	n_clientes++;
	char * str = malloc(sizeof(char) * 256);
	scanf("%s", str);

	static char msg[256];
	static char *p;

	printf("getting ready to return value\n");
	strcpy(msg, "Hello world3");
	p = str;
	printf("Returning...\n");

	return(&p);
}
