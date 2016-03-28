#include "Camera.hpp"


/*virtual*/ void Camera :: CameraOrtho(double g, double x, double y, double h, double cmin, double cmax){
	glOrtho(g, x, y, h, cmin, cmax);
}


/*virtual*/ void Camera :: CameraPerspective(double fov, double ratio, double cmin, double cmax){
	gluPerspective(fov, ratio, cmin, cmax);
}


/*virtual*/ void Camera ::  CameraViewport(int x, int y,float l, float h){
	glViewport(int x, int y,float l, float h);
}


/*virtual*/ void Camera ::  CameraGluLookAt
			(	  double ex 
				, double ey
				, double ez
				, double cx 
				, double cy
				, double cz
				, double upx
				, double upy
				, double upz ){
	gluLookAt(ex, ey, ez, cx, cy, cz, upx, upy, upz);
}

