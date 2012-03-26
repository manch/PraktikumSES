
#ifndef _mglu_h_included
#define _mglu_h_included

#include "./gl.h"
#include "./glext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GLUquadric GLUquadric;
typedef struct GLUquadric GLUquadricObj;

/* QuadricDrawStyle */
#define GLU_POINT                          100010
#define GLU_LINE                           100011
#define GLU_FILL                           100012
#define GLU_SILHOUETTE                     100013

/* QuadricCallback */
/*      GLU_ERROR */

/* QuadricNormal */
#define GLU_SMOOTH                         100000
#define GLU_FLAT                           100001
#define GLU_NONE                           100002

/* QuadricOrientation */
#define GLU_OUTSIDE                        100020
#define GLU_INSIDE                         100021


#define GLU_ERROR                          100103

/* ErrorCode */
#define GLU_INVALID_ENUM                   100900
#define GLU_INVALID_VALUE                  100901
#define GLU_OUT_OF_MEMORY                  100902
#define GLU_INVALID_OPERATION              100904

#ifndef GL_ES_ONLY
extern void gluLookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez,
                      GLfloat centerx, GLfloat centery, GLfloat centerz,
                      GLfloat upx, GLfloat upy, GLfloat upz);

extern void gluOrtho2D(GLfloat left, GLfloat right,
                       GLfloat bottom, GLfloat top);

extern void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear,
                           GLfloat zFar);
#endif

extern GLint gluBuild2DMipmaps(GLenum target, GLint internalFormat, 
                               GLsizei width, GLsizei height, 
                               GLenum format, GLenum type, 
                               const void *data);

#ifndef GL_ES_ONLY
extern void gluCylinder(GLUquadric* quad, GLfloat base, GLfloat top,
                        GLfloat height, GLint slices, GLint stacks);
extern void gluDeleteQuadric (GLUquadric* quad);
extern void gluDisk (GLUquadric* quad, GLfloat inner, GLfloat outer, GLint slices, GLint loops);
extern GLUquadric* gluNewQuadric (void);
extern void gluPartialDisk (GLUquadric* quad, GLfloat inner, GLfloat outer, GLint slices, GLint loops, GLfloat start, GLfloat sweep);
extern void gluQuadricCallback (GLUquadric* quad, GLenum which, GLvoid (*CallBackFunc)(void));
extern void gluQuadricDrawStyle (GLUquadric* quad, GLenum draw);
extern void gluQuadricNormals (GLUquadric* quad, GLenum normal);
extern void gluQuadricOrientation (GLUquadric* quad, GLenum orientation);
extern void gluQuadricTexture (GLUquadric* quad, GLboolean texture);
extern void gluSphere (GLUquadric* quad, GLfloat radius, GLint slices, GLint stacks);
#endif

#ifdef __cplusplus
}
#endif

#endif // _mglu_h_included
