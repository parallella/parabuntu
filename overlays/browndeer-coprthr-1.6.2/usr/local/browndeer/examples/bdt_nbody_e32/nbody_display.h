/* nbody_display.h
 *
 * Copyright (c) 2008-2009 Brown Deer Technology, LLC.  All Rights Reserved.
 *
 * This software was developed by Brown Deer Technology, LLC.
 * For more information contact info@browndeertechnology.com
 * 
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* DAR */


#ifndef _NBODY_DISPLAY_H
#define _NBODY_DISPLAY_H


//#include <algorithm>
//#include <cstring>
//#include <math.h> 
//#include <stdio.h>
//#include <stdlib.h>
//#include <float.h>
//#include <sys/time.h>

#include<GL/glut.h>


void display_init();
void idle();
void reShape(int w,int h);
void displayfunc();
void keyboardFunc(unsigned char key, int mouseX, int mouseY);

#endif

