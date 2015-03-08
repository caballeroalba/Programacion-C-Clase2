#include "tarea.h"


struct tarea{
    uint32_t id;
    const char *nombre_tarea;
    const char *desc_tarea:
    const char *usuario;
    int prioridad;
    uint32_t flags;


}


struct tarea *curso_tarea_alloc(void)
{
    return (struct tarea *)malloc (sizeof(struct tarea));
}

void curso_tarea_free(struct tarea *t)
{
    if(t->flags & (1 << CURSO_TAREA_ATTR_NOMBRE_TAREA))
        xfree(t->nombre_tareab);
    if(t->flags & (1 << CURSO_TAREA_ATTR_DESC_TAREA))
        xfree(t->desc_tarea);
    if(t->flags & (1<< CURSO_TAREA_ATTR_USUARIO))
        xfree(t->usuario);
    if(t->prioridad (1 << CURSO_TAREA_ATTR_PRIORIDAD))
        xfree(t->prioridad);
    xfree(t);

}

bool curso_tarea_attr_is_set(const struct tarea *t, uint16_t attr)
{
    return t->flags & (1<< attr);

}

void curso_tarea_attr_unset(struct tarea *c, uint16_t attr)
{
    if(!(c->flags & (1 << attr)))
        return;

    switch (attr) {
        case CURSO_TAREA_ATTR_NOMBRE_TAREA:
            if(c->nombre_tarea){
                xfree(c->nombre_tarea);
                c->nombre_tarea=NULL;
            }
            <`3`>
            <`4:break;`><`5`>
        case CURSO_TAREA_ATTR_DESC_TAREA:
            if(c->desc_tarea){
                xfree(c->desc_tarea);
                c->desc_tarea=NULL;
            }
            break;
        case CURSO_TAREA_ATTR_USUARIO:
            if(c->usuario){
                xfree(c->usuario);
                c->usuario=NULL;
            }
            break;
        case CURSO_TAREA_ATTR_PRIORIDAD:
            if(c->prioridad){
                xfree(c->prioridad);
                c->prioridad=NULL;
            }
            break;
        case CURSO_TAREA_ATTR_ID:
            break;
<`6`>
    }
    c->flags &= ~(1 << attr);
}

void curso_tarea_set_data(struct tarea *t, uint16_t attr, const void * data,
        uint32_t data_len){
    if(attr>CURSO_TAREA_ATTR_MAX)
        return;
    switch(attr){

        case CURSO_TAREA_ATTR_DESC_TAREA:
            if(t->desc_tarea)
                xfree(t->desc_tarea);
            t->desc_tarea=strdup(data);
            break;
        case CURSO_TAREA_ATTR_NOMBRE_TAREA:
            if(t->nombre_tarea)
                xfree(t->nombre_tarea);
            t->nombre_tarea=strdup(data);
        case CURSO_TAREA_ATTR_USUARIO:
            if(t->usuario)
                xfree(t->usuario);
            t->usuario=strdup(data);
        case CURSO_TAREA_ATTR_PRIORIDAD:
            if(t->prioridad)
                xfree(t->prioridad);
            t->prioridad=strdup(data);
        case CURSO_TAREA_ATTR_ID:
            t->id=*((uint32_t *) data);
            break;
    }
    c->flags |=(1<< attr);


}


