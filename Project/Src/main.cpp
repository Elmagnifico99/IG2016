/* Une animation en OpenGL                      */
/*                                              */
/* Auteur: Nicolas JANEY                        */
/* nicolas.janey@univ-fcomte.fr                 */
/* Septembre 2012                               */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <Image.hpp>
#include <Texture.hpp>
Texture* tex = nullptr;
Texture* tex2 = nullptr;
#include <Application.hpp>

/* Variables et constantes globales             */
/* pour les angles et les couleurs utilises     */

static float r0 = 0.0F;
static float r1 = 0.0F;
static float r2 = 0.0F;
static float r3 = 0.0F;
static float r4 = 0.0F;
static const float blanc[] = { 1.0F,1.0F,1.0F,1.0F };
static const float jaune[] = { 1.0F,1.0F,0.0F,1.0F };
static const float rouge[] = { 1.0F,0.0F,0.0F,1.0F };
static const float vert[] = { 0.0F,1.0F,0.0F,1.0F };
static const float bleu[] = { 0.0F,0.0F,1.0F,1.0F };

/* Fonction d'initialisation des parametres     */
/* OpenGL ne changeant pas au cours de la vie   */
/* du programme                                 */

void init(void) {
  const GLfloat shininess[] = { 50.0 };
  glMaterialfv(GL_FRONT,GL_SPECULAR,blanc);
  glMaterialfv(GL_FRONT,GL_SHININESS,shininess);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,rouge);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,jaune);
  glLightfv(GL_LIGHT2,GL_DIFFUSE,bleu);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glEnable(GL_AUTO_NORMAL);
}

/* Scene dessinee                               */
static float color[] = {1.0f, 1.0f, 1.0f, 1.0f};
void scene(void) {
  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    tex->Enable();
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-5.0f, -5.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(5.0f, -5.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(5.0f, 5.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-5.0f, 5.0f, 0.0f);
	glEnd();
	tex2->Enable();
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-15.0f, -5.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-5.0f, -5.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-5.0f, 5.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-15.0f, 5.0f, 0.0f);
	glEnd();
  glPopMatrix();
}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

void display(void) {
  glClearColor(0.5F,0.5F,0.5F,0.5F);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  const GLfloat light0_position[] = { 0.0,0.0,0.0,1.0 };
  const GLfloat light1_position[] = { -1.0,1.0,1.0,0.0 };
  const GLfloat light2_position[] = { 1.0,-1.0,1.0,0.0 };
  glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
  glLightfv(GL_LIGHT1,GL_POSITION,light1_position);
  glLightfv(GL_LIGHT2,GL_POSITION,light2_position);
  glPushMatrix();
  scene();
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
  int error = glGetError();
  if ( error != GL_NO_ERROR )
    printf("Attention erreur %d\n",error);
}

/* Fonction executee lorsqu'aucun evenement     */
/* n'est en file d'attente                      */

void idle(void) {
  glutPostRedisplay();
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */

void reshape(int x,int y) {
  glViewport(0,0,x,y); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80.0F,(float) x/y,1.0,40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0,0.0,20.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */

void keyboard(unsigned char key,int x,int y) {
  switch (key) {
    case 0x0D :
      { static int anim = 1;
        anim = !anim;
        glutIdleFunc(( anim ) ? idle : NULL); }
      break;
    case 0x1B :
      exit(0);
      break; }
}

/* Fonction principale                          */


void freeTextures()
{
	delete tex;
	delete tex2;
}

class MyApp : public Application
{
	virtual void OnInitialize(int argc, char** argv)
	{
		tex = new Texture("test.png");
		tex2 = new Texture("bla.png");
		init();
	}
	virtual void OnUpdate(float deltaTimeInSeconds)
	{
		display();
	}
	virtual void OnResizingWindow(unsigned int width, unsigned int height)
	{
		reshape(width, height);
	}
	virtual void OnKeyReleased(Key k)
	{
		if(k.code == e_key_escape)
		{
			Close();
		}
		else if(k.code == e_key_left_ctrl || k.code == e_key_right_ctrl)
		{
			printf("ctrl\n");
		}
		else if(k.code == e_key_left_alt || k.code == e_key_right_alt)
		{
			printf("alt\n");
		}
		else if(k.code == e_key_left_shift || k.code == e_key_right_shift)
		{
			printf("shift\n");
		}
		else if(k.character != 0)
		{
			printf("%c", k.character);
			if(k.character == 13)
			{
				printf("%c", 10);
			}
		}
	}
	virtual void OnRelease()
	{
		freeTextures();
	}
};

int main(int argc,char **argv) {

	Application::Parameters p;
	p.Width = 300;
	p.Height = 300;
	p.PositionX = 50;
	p.PositionY = 50;
	p.CenterWindow = false;
	p.WindowTitle = "Application test";

	MyApp app;
	app.Start(argc, argv, p);

	return(0);
}
