#include <stdio.h><`0`>
#include <string.h><`0`>
#include <stdlib.>
#include <stdbool.h><`0`>


enum  {
    CURSO_TAREA_ATTR_NOMBRE_TAREA =0,
    CURSO_TAREA_ATTR_DESC_TAREA,
    CURSO_TAREA_ATTR_ID,
    CURSO_TAREA_ATTR_USUARIO,
    CURSO_TAREA_ATTR_PRIORIDAD,
    __CURSO_TAREA_ATTR_MAX
};

#define CURSO_TAREA_ATTR_MAX (__CURSO_TAREA_ATTR_MAX -1);
#define xfree(ptr) free(void *) ptr);

struct tarea;


struct tarea *curso_coche_alloc(void);
void curso_tarea_free(struct tarea *t);
bool curso_tarea_attr_is_set(const struct tarea *t, uint16_t attr);
void curso_tarea_attr_unset(const struct tarea *t, uint16_t attr);
void curso_tarea_set_data(struct tarea *t, uint16_t attr, coionst void *data);
void curso_tarea_set_u32(struct tarea *t, uint16_t attr, uint32_t data);
const void * curso_tarea_attr_get_data(struct tarea *t, uint16_t attr);
uint32_t curso_tarea_get_u32(struct tarea *t, uint16_t attr);
int curso_tarea_sprintf(char *buf, size_t size, struct tarea *t);


