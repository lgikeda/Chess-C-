#include "freeglut.h"
#include <math.h>
#include "esfera.h"
#include "mundo.h"

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

esfera esfera1 = { 1,3,0,0,255,255 };
esfera esfera2 = { 1,0,0,255,0,0 };
mundo mundo1 = { 0, 10, 20 };

int main(int argc, char* argv[])
{
	//inicialización de los datos de la simulación
	esfera1.setColor(200, 0, 0);
	esfera1.setRadio(1);
	esfera1.setPos(2, 0);
	esfera2.setColor(0, 200, 0);
	esfera2.setRadio(1);
	esfera2.setPos(3, 0);

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//inicialización de los datos de la simulación
	esfera1.setColor(200, 0, 0);
	esfera2.setColor(0, 200, 0);
	//pasarle el control a FREEGLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(mundo1.x, mundo1.y, mundo1.z,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	//aqui es donde hay que poner el código de dibujo
	esfera1.dibuja();
	esfera2.dibuja();

	glColor3ub(0, 255, 0);
	glutSolidTorus(1, 5, 20, 20);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glColor3ub(255, 0, 0);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);


	//no borrar esta linea ni poner nada despues

	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	if (key == '+' && esfera2.radio < 3)
		esfera2.radio += 0.5f;
	if (key == '-' && esfera2.radio > 1)
		esfera2.radio -= 0.5f;
	if (key == 'r')
	{
		esfera2.rojo = 255;
		esfera2.verde = 0;
		esfera2.azul = 0;
	}
	if (key == 'a')
		esfera2.x -= 0.2f;
	if (key == 'd')
		esfera2.x += 0.2f;
	if (key == 's')
		esfera2.y -= 0.2f;
	if (key == 'w')
		esfera2.y += 0.2f;
}

void OnTimer(int value)
{
	mundo1.rotarOjo();
	esfera2.mueve();
	//Mueve(&esfera2);
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
void esfera::mueve()
{
	radio += 0.01f;
	if (radio > 3)
		radio = 0.5f;
}
