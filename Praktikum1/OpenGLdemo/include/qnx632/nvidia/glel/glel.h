#ifndef GLEL_H_INCLUDED
#define GLEL_H_INCLUDED

#include "../GLES/gl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Inits the extensions and returns 0 if successful
 */
int init_extensions(void);

/**
 * Inits the extensions and returns 1 if successful
 */
int glelInit(void);

int glelCheckExtension(int glelExtId);

typedef GLsizeiptrARB GLsizeiptr;
typedef GLintptrARB GLintptr;

#define GLEL_EXT_GL_OES_QUERY_MATRIX                    0x00001
#define GLEL_EXT_GL_OES_READ_FORMAT                     0x00002
#define GLEL_EXT_GL_NV_FENCE                            0x00003
#define GLEL_EXT_GL_EXT_TEXTURE_COMPRESSION_S3TC        0x00004
#define GLEL_EXT_GL_EXT_TEXTURE_COMPRESSION_DXT1        0x00005
#define GLEL_EXT_GL_EXT_TEXTURE_LOD_BIAS                0x00006
#define GLEL_EXT_GL_NV_REGISTER_COMBINERS               0x00007
#define GLEL_EXT_GL_OES_COMPRESSED_PALETTED_TEXTURE     0x00008
#define GLEL_EXT_GL_NV_ATTRIB_STACK                     0x00009
#define GLEL_EXT_GL_SGIS_TEXTURE_LOD                    0x0000A
#define GLEL_EXT_GL_NV_TEXTURE_RECTANGLE                0x0000B
#define GLEL_EXT_GL_OES_TEXTURE_CUBE_MAP                0x0000C
#define GLEL_EXT_GL_NV_TEXGEN_FULL                      0x0000D
#define GLEL_EXT_GL_OES_MATRIX_PALETTE                  0x0000E
#define GLEL_EXT_GL_OES_DRAW_TEXTURE                    0x0000F
#define GLEL_EXT_GL_EXT_SEPARATE_SPECULAR_COLOR         0x00010
#define GLEL_EXT_GL_NV_RESIDENCE                        0x00011
#define GLEL_EXT_GL_OES_VERTEX_BUFFER_OBJECT            0x00012
#define GLEL_EXT_GL_EXT_TIMER_QUERY                     0x00013

//The extension part
//----------------------- OES_vertex_buffer_objects -----------------------------

#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING    0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING    0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING     0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING     0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD

// function pointer typedefs
typedef void (*PFNGLBINDBUFFER)(GLenum target, GLuint buffer);
typedef void (*PFNGLBUFFERDATA)(GLenum target, GLsizeiptr size,
                                const GLvoid *data, GLenum usage);
typedef void (*PFNGLBUFFERSUBDATA)(GLenum target, GLintptr offset,
                                   GLsizeiptr size, const GLvoid *data);
typedef void (*PFNGLDELETEBUFFERS)(GLsizei n, const GLuint *buffers);
typedef void (*PFNGLGENBUFFERS) (GLsizei n, GLuint* buffers);

// prototypes for function pointers for VBO
extern PFNGLBINDBUFFER    myGlBindBufferOES;
extern PFNGLBUFFERDATA    myGlBufferDataOES;
extern PFNGLBUFFERSUBDATA myGlBufferSubDataOES;
extern PFNGLDELETEBUFFERS myGlDeleteBuffersOES;
extern PFNGLGENBUFFERS myGlGenBuffersOES;

#define glBindBufferOES    myGlBindBufferOES
#define glBufferDataOES    myGlBufferDataOES
#define glBufferSubDataOES myGlBufferSubDataOES
#define glDeleteBuffersOES myGlDeleteBuffersOES
#define glGenBuffersOES myGlGenBuffersOES

#ifndef GL_OES_VERSION_1_1
#define glBindBuffer    glBindBufferOES
#define glBufferData    glBufferDataOES
#define glBufferSubData glBufferSubDataOES
#define glDeleteBuffers glDeleteBuffersOES
#define glGenBuffers glGenBuffersOES
#endif //GL_OES_VERSION_1_1

//----------------------- OES_texture_cube_map -----------------------------
#define GL_TEXTURE_GEN_S                  0x0C60
#define GL_TEXTURE_GEN_T                  0x0C61
#define GL_TEXTURE_GEN_R                  0x0C62
#define GL_TEXTURE_GEN_MODE               0x2500
#define GL_STR                            0x2004   // FIXME: replace with
                                                   // official value!
#define GL_NORMAL_MAP                     0x8511
#define GL_REFLECTION_MAP                 0x8512
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C


typedef void (*PFNGLGETTEXGENFV)  (GLenum coord, GLenum pname, GLfloat *params);       
typedef void (*PFNGLGETTEXGENIV)  (GLenum coord, GLenum pname, GLint *params);         
typedef void (*PFNGLGETTEXGENXV)  (GLenum coord, GLenum pname, GLfixed *params);       
typedef void (*PFNGLTEXGENFV)     (GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLTEXGENIV)     (GLenum target, GLenum pname, const GLint *params);  
typedef void (*PFNGLTEXGENXV)     (GLenum target, GLenum pname, const GLfixed *params);
typedef void (*PFNGLTEXGENF)      (GLenum target, GLenum pname, GLfloat param);        
typedef void (*PFNGLTEXGENI)      (GLenum target, GLenum pname, GLint param);          
typedef void (*PFNGLTEXGENX)      (GLenum target, GLenum pname, GLfixed param);        


// prototypes for function pointers for VBO
extern PFNGLGETTEXGENFV myGlGetTexGenfv;
extern PFNGLGETTEXGENIV myGlGetTexGeniv; 
extern PFNGLGETTEXGENXV myGlGetTexGenxv; 
extern PFNGLTEXGENFV    myGlTexGenfv;    
extern PFNGLTEXGENIV    myGlTexGeniv;    
extern PFNGLTEXGENXV    myGlTexGenxv;    
extern PFNGLTEXGENF     myGlTexGenf;     
extern PFNGLTEXGENI     myGlTexGeni;     
extern PFNGLTEXGENX     myGlTexGenx;  

#define glGetTexGenfv  myGlGetTexGenfv 
#define glGetTexGeniv  myGlGetTexGeniv 
#define glGetTexGenxv  myGlGetTexGenxv 
#define glTexGenfv     myGlTexGenfv    
#define glTexGeniv     myGlTexGeniv    
#define glTexGenxv     myGlTexGenxv    
#define glTexGenf      myGlTexGenf     
#define glTexGeni      myGlTexGeni     
#define glTexGenx      myGlTexGenx     
     

//----------------------- NV_texgen_full -----------------------------
#define GL_TEXTURE_GEN_Q                  0x0C63
#define GL_S                              0x2000
#define GL_T                              0x2001
#define GL_R                              0x2002
#define GL_Q                              0x2003
#define GL_EYE_LINEAR                     0x2400
#define GL_OBJECT_LINEAR                  0x2401
#define GL_SPHERE_MAP                     0x2402
#define GL_OBJECT_PLANE                   0x2501
#define GL_EYE_PLANE                      0x2502

//----------------------- GL_NV_register_combiners -----------------------------
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SPARE0_NV 0x852E
#define GL_SPARE1_NV 0x852F
#define GL_DISCARD_NV 0x8530
#define GL_E_TIMES_F_NV 0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SCALE_BY_TWO_NV 0x853E
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557

// additional defines not part of the extension but used by it
#ifndef GL_NONE
#define GL_NONE 0
#endif
#ifndef GL_RED
#define GL_RED 0x1903
#endif
#ifndef GL_GREEN
#define GL_GREEN 0x1904
#endif
#ifndef GL_BLUE
#define GL_BLUE 0x1905
#endif

typedef void (*PFNGLCOMBINERINPUTNVPROC)                    (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (*PFNGLCOMBINEROUTPUTNVPROC)                   (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef void (*PFNGLCOMBINERPARAMETERFNVPROC)               (GLenum pname, GLfloat param);
typedef void (*PFNGLCOMBINERPARAMETERFVNVPROC)              (GLenum pname, const GLfloat* params);
typedef void (*PFNGLCOMBINERPARAMETERINVPROC)               (GLenum pname, GLint param);
typedef void (*PFNGLCOMBINERPARAMETERIVNVPROC)              (GLenum pname, const GLint* params);
typedef void (*PFNGLFINALCOMBINERINPUTNVPROC)               (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (*PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)      (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params);
typedef void (*PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)      (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params);
typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)     (GLenum stage, GLenum portion, GLenum pname, GLfloat* params);
typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)     (GLenum stage, GLenum portion, GLenum pname, GLint* params);
typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (GLenum variable, GLenum pname, GLfloat* params);
typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (GLenum variable, GLenum pname, GLint* params);

extern PFNGLCOMBINERINPUTNVPROC                    myGlCombinerInputNV;
extern PFNGLCOMBINEROUTPUTNVPROC                   myGlCombinerOutputNV;
extern PFNGLCOMBINERPARAMETERFNVPROC               myGlCombinerParameterfNV;
extern PFNGLCOMBINERPARAMETERFVNVPROC              myGlCombinerParameterfvNV;
extern PFNGLCOMBINERPARAMETERINVPROC               myGlCombinerParameteriNV;
extern PFNGLCOMBINERPARAMETERIVNVPROC              myGlCombinerParameterivNV;
extern PFNGLFINALCOMBINERINPUTNVPROC               myGlFinalCombinerInputNV;
extern PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC      myGlGetCombinerInputParameterfvNV;
extern PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC      myGlGetCombinerInputParameterivNV;
extern PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC     myGlGetCombinerOutputParameterfvNV;
extern PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC     myGlGetCombinerOutputParameterivNV;
extern PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC myGlGetFinalCombinerInputParameterfvNV;
extern PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC myGlGetFinalCombinerInputParameterivNV;

#define glCombinerInputNV                       myGlCombinerInputNV                     
#define glCombinerOutputNV                      myGlCombinerOutputNV                    
#define glCombinerParameterfNV                  myGlCombinerParameterfNV                
#define glCombinerParameterfvNV                 myGlCombinerParameterfvNV               
#define glCombinerParameteriNV                  myGlCombinerParameteriNV                
#define glCombinerParameterivNV                 myGlCombinerParameterivNV               
#define glFinalCombinerInputNV                  myGlFinalCombinerInputNV                
#define glGetCombinerInputParameterfvNV         myGlGetCombinerInputParameterfvNV       
#define glGetCombinerInputParameterivNV         myGlGetCombinerInputParameterivNV       
#define glGetCombinerOutputParameterfvNV        myGlGetCombinerOutputParameterfvNV      
#define glGetCombinerOutputParameterivNV        myGlGetCombinerOutputParameterivNV      
#define glGetFinalCombinerInputParameterfvNV    myGlGetFinalCombinerInputParameterfvNV  
#define glGetFinalCombinerInputParameterivNV    myGlGetFinalCombinerInputParameterivNV  

//----------------------- EXT_texture_compression_dxt1 -----------------------------
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1

//----------------------- EXT_texture_compression_s3tc -----------------------------
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3

//----------------------- NV_attrib_stack -----------------------------
#define GL_CURRENT_BIT_NV                   0x00000001
#define GL_POINT_BIT_NV                     0x00000002
#define GL_LINE_BIT_NV                      0x00000004
#define GL_POLYGON_BIT_NV                   0x00000008
#define GL_PIXEL_MODE_BIT_NV                0x00000020
#define GL_LIGHTING_BIT_NV                  0x00000040
#define GL_FOG_BIT_NV                       0x00000080
#define GL_DEPTH_BUFFER_BIT_NV              0x00000100
#define GL_STENCIL_BUFFER_BIT_NV            0x00000400
#define GL_VIEWPORT_BIT_NV                  0x00000800
#define GL_TRANSFORM_BIT_NV                 0x00001000
#define GL_ENABLE_BIT_NV                    0x00002000
#define GL_COLOR_BUFFER_BIT_NV              0x00004000
#define GL_HINT_BIT_NV                      0x00008000
#define GL_TEXTURE_BIT_NV                   0x00040000
#define GL_SCISSOR_BIT_NV                   0x00080000
#define GL_ALL_ATTRIB_BITS_NV               0xFFFFFFFF
#define GL_CLIENT_VERTEX_ARRAY_BIT_NV       0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS_NV        0xFFFFFFFF
#define GL_ATTRIB_STACK_DEPTH_NV            0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH_NV     0x0BB1
#define GL_MAX_ATTRIB_STACK_DEPTH_NV        0x0D35
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH_NV 0x0D3B

typedef void (*PFNGLPOPATTRIBNVPROC)        (void);
typedef void (*PFNGLPOPCLIENTATTRIBNVPROC)  (void);
typedef void (*PFNGLPUSHATTRIBNVPROC)       (GLbitfield mask);
typedef void (*PFNGLPUSHCLIENTATTRIBNVPROC) (GLbitfield mask);

extern PFNGLPOPATTRIBNVPROC                 myGlPopAttribNV;       
extern PFNGLPOPCLIENTATTRIBNVPROC           myGlPopClientAttribNV; 
extern PFNGLPUSHATTRIBNVPROC                myGlPushAttribNV;      
extern PFNGLPUSHCLIENTATTRIBNVPROC          myGlPushClientAttribNV;

#define glPopAttribNV         myGlPopAttribNV        
#define glPopClientAttribNV   myGlPopClientAttribNV  
#define glPushAttribNV        myGlPushAttribNV       
#define glPushClientAttribNV  myGlPushClientAttribNV 

//----------------------- EXT_texture_lod_bias -----------------------------
#define GL_MAX_TEXTURE_LOD_BIAS_EXT       0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT     0x8500
#define GL_TEXTURE_LOD_BIAS_EXT           0x8501

//----------------------- EXT_timer_query ----------------------------------
#define GL_QUERY_COUNTER_BITS_ARB         0x8864
#define GL_CURRENT_QUERY_ARB              0x8865
#define GL_QUERY_RESULT_ARB               0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB     0x8867
#define GL_TIME_ELAPSED_EXT               0x88BF

typedef unsigned long long GLuint64EXT;
typedef          long long GLint64EXT;

typedef void      (*PFNGLGENQUERIESARB)          (GLsizei n, GLuint *ids);
typedef void      (*PFNGLDELETEQUERIESARB)       (GLsizei n, const GLuint *ids);
typedef GLboolean (*PFNGLISQUERYARB)             (GLuint id);
typedef void      (*PFNGLBEGINQUERYARB)          (GLenum target, GLuint id);
typedef void      (*PFNGLENDQUERYARB)            (GLenum target);
typedef void      (*PFNGLGETQUERYOBJECTIVARB)    (GLuint id, GLenum pname, GLint *params);
typedef void      (*PFNGLGETQUERYOBJECTUIVARB)   (GLuint id, GLenum pname, GLuint *params);
typedef void      (*PFNGLGETQUERYIVARB)          (GLenum target, GLenum pname, GLint *params);
typedef void      (*PFNGLGETQUERYOBJECTI64VEXT)  (GLuint id, GLenum pname, GLint64EXT *params);
typedef void      (*PFNGLGETQUERYOBJECTUI64VEXT) (GLuint id, GLenum pname, GLuint64EXT *params);

extern PFNGLGENQUERIESARB                        myGlGenQueriesARB;        
extern PFNGLDELETEQUERIESARB                     myGlDeleteQueriesARB;     
extern PFNGLISQUERYARB                           myGlIsQueryARB;           
extern PFNGLBEGINQUERYARB                        myGlBeginQueryARB;        
extern PFNGLENDQUERYARB                          myGlEndQueryARB;          
extern PFNGLGETQUERYOBJECTIVARB                  myGlGetQueryObjectivARB;  
extern PFNGLGETQUERYOBJECTUIVARB                 myGlGetQueryObjectuivARB; 
extern PFNGLGETQUERYIVARB                        myGlGetQueryivARB;        
extern PFNGLGETQUERYOBJECTI64VEXT                myGlGetQueryObjecti64vEXT;
extern PFNGLGETQUERYOBJECTUI64VEXT               myGlGetQueryObjectui64vEXT;

#define glGenQueriesARB           myGlGenQueriesARB         
#define glDeleteQueriesARB        myGlDeleteQueriesARB      
#define glIsQueryARB              myGlIsQueryARB            
#define glBeginQueryARB           myGlBeginQueryARB         
#define glEndQueryARB             myGlEndQueryARB           
#define glGetQueryObjectivARB     myGlGetQueryObjectivARB   
#define glGetQueryObjectuivARB    myGlGetQueryObjectuivARB  
#define glGetQueryivARB           myGlGetQueryivARB         
#define glGetQueryObjecti64vEXT   myGlGetQueryObjecti64vEXT
#define  glGetQueryObjectui64vEXT myGlGetQueryObjectui64vEXT


//----------------------- SGIS_texture_lod -----------------------------------
#define GL_TEXTURE_MIN_LOD_SGIS           0x813A
#define GL_TEXTURE_MAX_LOD_SGIS           0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS        0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS         0x813D

//----------------------- end of extensions ----------------------------------
#ifdef __cplusplus
}
#endif

#endif //GLEL_H_INCLUDED
