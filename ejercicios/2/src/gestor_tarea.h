#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tarea.h"

enum {
	CURSO_GESTOR_TAREAS_ATTR_TAREAS,
	CURSO_GESTOR_TAREAS_ATTR_ID,
  CURSO_GESTOR_TAREAS_ATTR_NUMBER_OF_ELEMENTS,
	__CURSO_GESTOR_TAREAS_ATTR_MAX
};

#define CURSO_GESTOR_TAREAS_ATTR_MAX (__CURSO_GESTOR_TAREAS_ATTR_MAX - 1)
#define CURSO _GESTOR_TAREAS_MAX_TAREAS 10
#define xfree(ptr)      free((void *)ptr);

struct gestor_tarea;

struct gestor_tarea *curso_gestor_tarea_alloc(void);

void curso_gestor_tarea_free(struct gestor_tarea *);

bool curso_gestor_tarea_attr_is_set(const struct gestor_tarea *g, uint16_t attr);

void curso_gestor_tarea_attr_unset(struct gestor_tarea *g, uint16_t attr, int n);

void curso_gestor_tarea_attr_set_data(struct gestor_tarea *g, uint16_t attr, const void *data,
			                          uint32_t data_len);
void curso_gestor_tarea_attr_set_u32(struct gestor_tarea *g, uint16_t attr, uint32_t data, int n);

void curso_gestor_tarea_attr_set_str(struct gestor_tarea *g, uint16_t attr, const char *data, int n);

const void *curso_gestor_tarea_attr_get_data(struct gestor_tarea *g, uint16_t attr, int n);

uint32_t curso_gestor_tarea_attr_get_u32(struct gestor_tarea *g, uint16_t attr, int n);

struct tarea *curso_gestor_tarea_attr_get_tarea(struct gestor_tarea *g, uint16_t attr, int n);

int curso_gestor_tarea_snprintf(char *buf, size_t size, struct gestor_tarea *g, int n);


void curso_gestor_tarea_set_tarea(struct gestor_tarea *g, uint16_t attr,  struct tarea *data,
                          uint32_t data_len, int n);

void curso_gestor_tarea_reorder(struct gestor_tarea *g,int n);

int curso_gestor_tarea_get_numberOfElements(struct gestor_tarea *g);
