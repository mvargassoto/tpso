#include <stdlib.h>
#include <stdio.h>
#include <utils/utils-client.h>


int main(void) {

    int conexion;
	char* ip;
	char* puerto_mem;

    t_log* logger;
	t_config* config;


	logger = log_create("cpu_log.log", "CPU",true, LOG_LEVEL_INFO);
	if (!logger) {
		perror("No se pudo crear el logger\n");
		exit(EXIT_FAILURE);
	}

    config = config_create("/home/utnso/prototp/tp-2024-1c-los-programadores-de-la-nada/cpu/cpu.config");
	if (!config) {
		perror("No se pudo crear el config\n");
        log_destroy(logger);
		exit(EXIT_FAILURE);
	}

	ip = config_get_string_value(config, "IP");
	puerto_mem = config_get_string_value(config, "PUERTO_MEM");

    log_info(logger,ip);
	log_info(logger,puerto_mem);

    conexion = crear_conexion(ip, puerto_mem);
    if (conexion == -1) {
        log_destroy(logger);
        config_destroy(config);
        exit(EXIT_FAILURE);
    }

    enviar_mensaje("CPU CONECTADO!\n", conexion);

    int a;
    scanf("%i ", &a);

    liberar_conexion(conexion);
    log_destroy(logger);
    config_destroy(config);

    return 0;
}