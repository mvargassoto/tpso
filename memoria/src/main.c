#include <stdlib.h>
#include <stdio.h>
#include <utils/utils-server.h>

t_log* logger;

void iterator(char* value) {
	log_info(logger,"%s", value);
}

int main(void) {

    logger = log_create("mem_log.log", "MEMORIA", 1, LOG_LEVEL_DEBUG);
    
	int server_fd = iniciar_servidor("4444", logger);
	log_info(logger, "Servidor listo para recibir al cliente");
	int cliente_fd = esperar_cliente(server_fd, logger);

	t_list* lista;
	while (1) {
		int cod_op = recibir_operacion(cliente_fd);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(cliente_fd, logger);
			break;
		case PAQUETE:
			lista = recibir_paquete(cliente_fd);
			log_info(logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
		case -1:
			log_error(logger, "el cliente se desconecto. Terminando servidor");
			return EXIT_FAILURE;
		default:
			log_warning(logger,"Operacion desconocida. No quieras meter la pata");
			break;
		}
	}
	return 0;
}

