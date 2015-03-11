#include "gestor_tarea.h"
#include <string.h>


struct tarea {
        uint32_t        id;
        const char      *nombre_tarea;
        const char      *desc_tarea;
        const char      *usuario;
        uint32_t        prioridad;

        uint32_t        flags;
};



struct gestor_tarea {
	uint32_t	id;
	struct tarea *tareas[10];
	int 		numberOfElements;
	uint32_t	flags;
};

struct gestor_tarea *curso_gestor_tarea_alloc(void)
{

	return (struct gestor_tarea *) malloc(sizeof(struct gestor_tarea));
}

void curso_gestor_tarea_free(struct gestor_tarea *g)
{
	if (g->flags & (1 << CURSO_GESTOR_TAREAS_ATTR_TAREAS)){
		int i=0;
        for(i=0; i<sizeof(g->tareas)/sizeof(struct tarea *);i++){

             xfree(g->tareas[i]);
         }
    }


	xfree(g);
}

bool curso_gestor_tarea_attr_is_set(const struct gestor_tarea *g, uint16_t attr)
{
	return g->flags & (1 << attr);
}
void curso_gestor_tarea_attr_unset(struct gestor_tarea *g, uint16_t attr, int n){
	if (!(g->flags & (1 << attr)))
		return;

	switch (attr) {
	case CURSO_GESTOR_TAREAS_ATTR_TAREAS:
		if (g->tareas[n]) {
			xfree(g->tareas[n]);
			g->tareas[n] = NULL;
      curso_gestor_tarea_reorder(g,n);
      g->numberOfElements--;
      
		}
		break;

	case CURSO_GESTOR_TAREAS_ATTR_ID:
		break;
	}

	g->flags &= ~(1 << attr);
}

void curso_gestor_tarea_set_data(struct gestor_tarea *g, uint16_t attr, const void *data,
			  uint32_t data_len, int n)
{
	if (attr > CURSO_GESTOR_TAREAS_ATTR_MAX)
		return;

	switch (attr) {
	    case CURSO_GESTOR_TAREAS_ATTR_TAREAS:
		    if (g->tareas[n])
			    xfree(g->tareas[n]);

	    	g->tareas[n] = strdup(data);

		printf("dentrdo de set_data %s\n",g->tareas[n]->id);
		    break;

	case CURSO_GESTOR_TAREAS_ATTR_ID:
		g->id = *((uint32_t *)data);
		break;
	}

	g->flags |= (1 << attr);
}

void curso_gestor_tarea_attr_set_u32(struct gestor_tarea *g, uint16_t attr, uint32_t data, int n)
{
	curso_gestor_tarea_set_data(g, attr, &data, sizeof(uint32_t), n);
}

void curso_gestor_tarea_attr_set_str(struct gestor_tarea *g, uint16_t attr, const char *data, int n)
{
	curso_gestor_tarea_set_data(g, attr, data,sizeof(uint32_t), n);
}

const void *curso_gestor_tarea_attr_get_data(struct gestor_tarea *g, uint16_t attr, int n)
{
	if (!(g->flags & (1 << attr)))
		return NULL;

	switch(attr) {
	case CURSO_GESTOR_TAREAS_ATTR_TAREAS:
		return g->tareas[n];
	case CURSO_GESTOR_TAREAS_ATTR_ID:
		return &g->id;
	}
	return NULL;
}

uint32_t curso_gestor_tarea_attr_get_u32(struct gestor_tarea *g, uint16_t attr, int n)
{
	const void *ret = curso_gestor_tarea_attr_get_data(g, attr, n);
	return ret == NULL ? 0 : *((uint32_t *)ret);
}

struct tarea *curso_gestor_tarea_attr_get_tarea(struct gestor_tarea *g, uint16_t attr, int n)
{
	return curso_gestor_tarea_attr_get_data(g, attr, n);
}

int curso_gestor_tarea_snprintf(char *buf, size_t size, struct gestor_tarea *g, int n)
{


        return snprintf(buf, size, "la tarea %d esta enviada por %s se llama  %s y la descripcion  %s",
				g->tareas[0]->id, g->tareas[n]->usuario,g->tareas[n]->nombre_tarea, g->tareas[n]->desc_tarea);

}
void curso_gestor_tarea_set_tarea(struct gestor_tarea *g, uint16_t attr,  struct tarea *data,
                          uint32_t data_len, int n)
{
        if (attr > CURSO_GESTOR_TAREAS_ATTR_MAX)
                return;

        switch (attr) {
            case CURSO_GESTOR_TAREAS_ATTR_TAREAS:
    
              if(n<9 && (g->numberOfElements+1)<=9){
		          if(g->tareas[n])
			          xfree(g->tareas[n]);
              
              g->tareas[n]=data;
 		          g->numberOfElements++;
		    //ordenamos en funcion de la prioridad
		          int i,j;
		          int v= g->numberOfElements;
		          printf("acaba de asignar v %d\n",v);
              struct tarea *aux;
		          printf("tareas actuales %d\n",v);
	            int b=v;	
		          if(v==1){
		    	     break; 
                
              }
		          printf("hola\n");
		          for (i=0; i <=v-1 ; i++){
			          for(j=i+1; j <=v-1; j++){
		              if(g->tareas[i]->prioridad < g->tareas[j]->prioridad){
				            printf("dentro del for\n");
			              aux=g->tareas[i];
				            g->tareas[i]=g->tareas[j];
				            g->tareas[j]=aux;
			            }
			          } 
		           }   
               break;
		          }else{
		          	printf("el numero maximo de asignación de tareas es 9 (desde 0 a 9) usted ha insertado el numero %d\n",n);
		          	break;
		          }
        case CURSO_GESTOR_TAREAS_ATTR_ID:
                g->id = *((uint32_t *)data);
                break;
        }
  
       g->flags |= (1 << attr);
}

void curso_gestor_tarea_reorder(struct gestor_tarea *g, int n){
  //saneamos los null del unset
  int k;
  for (k=n ; k< g->numberOfElements; k++){
    if(k+1 != g->numberOfElements){
        struct tarea *aux;
        printf("%d\n",g->tareas[k+1]->prioridad);

        g->tareas[k]=g->tareas[k+1];
        printf("%d\n",g->tareas[k]->prioridad);
        
    }else{
      g->tareas[k+1]=NULL;
    }

  }
  printf("chivato comprovamos los valores hasta el numero de elementos -1\n");
  int b;
  for (b=0; b<g->numberOfElements; b++){
      printf("%d\n",g->tareas[b]->prioridad);
  }
//  printf("comprobamos desntro de reorder la prioridad %d\n",g->tareas[k]->prioridad);
}
int curso_gestor_tarea_get_numberOfElements(struct gestor_tarea *g){

  return g->numberOfElements;
}
