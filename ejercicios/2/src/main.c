#include "gestor_tarea.h"
#include <assert.h>


int main(void)
{
	struct tarea *t1,*t3,*t4;
        char info[250];
	struct gestor_tarea *t2;
	t1 = curso_tarea_alloc();
	t2 = curso_gestor_tarea_alloc();
	t4 = curso_tarea_alloc();
	t3 = curso_tarea_alloc();
	//creamos la tarea 1
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_NOMBRE_TAREA, "XX67838 SE");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_DESC_TAREA, "XXX");
    	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_USUARIO, "jose");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_PRIORIDAD, 10);
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	//la añadimos al gestor
     	curso_gestor_tarea_set_tarea(t2, CURSO_GESTOR_TAREAS_ATTR_TAREAS, t1,sizeof(struct tarea *), 0);
	
	//creamos la tarea 2
        curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_NOMBRE_TAREA, "XX67838 SE");
        curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_DESC_TAREA, "XXX");
        curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_USUARIO, "maria");
        curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_PRIORIDAD, 8);
        curso_tarea_attr_set_u32(t3, CURSO_TAREA_ATTR_ID, 0);
        //la añadimos al gestor
        curso_gestor_tarea_set_tarea(t2, CURSO_GESTOR_TAREAS_ATTR_TAREAS, t3,sizeof(struct tarea *), 1);

	//creamos la tarea 3

	curso_tarea_attr_set_str(t4, CURSO_TAREA_ATTR_NOMBRE_TAREA, "XX67838 SE");
        curso_tarea_attr_set_str(t4, CURSO_TAREA_ATTR_DESC_TAREA, "XXX");
        curso_tarea_attr_set_str(t4, CURSO_TAREA_ATTR_USUARIO, "caballero");
        curso_tarea_attr_set_str(t4, CURSO_TAREA_ATTR_PRIORIDAD, 12);
        curso_tarea_attr_set_u32(t4, CURSO_TAREA_ATTR_ID, 0);

	curso_gestor_tarea_set_tarea(t2, CURSO_GESTOR_TAREAS_ATTR_TAREAS,t4, sizeof(struct tarea *),2);

	

	//comprobamos que la tarea se ha asignado usando la prioridad de la tarea 
	
	int i;
	for (i=0; i < curso_gestor_tarea_get_numberOfElements(t2);i++){
		struct tarea *test;
  		test=curso_gestor_tarea_attr_get_tarea(t2,CURSO_GESTOR_TAREAS_ATTR_TAREAS,i); 
  		curso_tarea_snprintf(info,sizeof(info),test);
  		printf("la tarea test:%s\n",info);
  		

        }

	
	printf("quitamos la primera\n");
	curso_gestor_tarea_attr_unset(t2,CURSO_GESTOR_TAREAS_ATTR_TAREAS,1);
	printf("se quita\n");
	


	//volvemos a ver las tareas actuales habiendo quitado una

		
        for (i=0; i < curso_gestor_tarea_get_numberOfElements(t2);i++){
		printf("%d\n",i);
                struct tarea *test;
                test=curso_gestor_tarea_attr_get_tarea(t2,CURSO_GESTOR_TAREAS_ATTR_TAREAS,i); 
		printf("antes de perdira\n");
                curso_tarea_snprintf(info,sizeof(info),test);
                printf("la tarea test:%s\n",info);


        }

  	curso_gestor_tarea_free(t2);
  	//comprobamos el orden de las tareas esta bien asignado por prioridad
	return 0;


	}
