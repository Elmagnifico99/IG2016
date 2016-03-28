#ifndef __CAMERA_HPP
#define __CAMERA_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Camera
{
	public:
	
			/* Methode                                  */ 
			virtual void CameraOrtho(double g, double x, double y, double h, double cmin, double cmax);
			
			virtual void CameraPerspective(double fov, double ratio, double cmin, double cmax);
			
			virtual void CameraViewport(int x, int y,float l, float h);
			
			virtual void CameraGluLookAt
			(	  double ex 
				, double ey
				, double ez
				, double cx 
				, double cy
				, double cz
				, double upx
				, double upy
				, double upz );
			
			
}


#endif
