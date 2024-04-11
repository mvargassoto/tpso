#ifndef UTILS_H_
#define UTILS_H_

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<commons/log.h>
#include<commons/collections/list.h>
#include<string.h>
#include<assert.h>

typedef enum
{
	MENSAJE,
	PAQUETE
}op_code;

void* recibir_buffer(int*, int);

int iniciar_servidor(char*, t_log*);
int esperar_cliente(int, t_log*);
t_list* recibir_paquete(int);
void recibir_mensaje(int, t_log*);
int recibir_operacion(int);

#endif /* UTILS_H_ */
