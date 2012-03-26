#ifndef __glext_h_
#define __glext_h_

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------- extensions -------------------- */

#define GL_OES_query_matrix               1
#define GL_EXT_texture_lod_bias           1
#define GL_EXT_texture_compression_dxt1   1
#define GL_SGIS_texture_lod               1
#define GL_NV_attrib_stack                1
#define GL_NV_combiner_program            1
#define GL_NV_render_alpha_to_green       1
#define GL_OES_texture_cube_map           1
#define GL_NV_texgen_full                 1
#define GL_OES_vertex_buffer_object       1
#define GL_EXT_texture_compression_s3tc   1
#define GL_NV_fence                       1
#define GL_NV_texture_rectangle           1
#define GL_NV_register_combiners          1
#define GL_EXT_bgra                       1
#define GL_OES_matrix_palette             1
#define GL_OES_extended_matrix_palette    1
#define GL_OES_draw_texture               1
#define GL_EXT_separate_specular_color    1
#define GL_NV_residence                   1
#define GL_EXT_timer_query                1
#define GL_OES_EGL_image                  1

/* NV_attrib_stack */
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
GLAPI void APIENTRY glPopAttribNV(void);
GLAPI void APIENTRY glPopClientAttribNV(void);
GLAPI void APIENTRY glPushAttribNV(GLbitfield mask);
GLAPI void APIENTRY glPushClientAttribNV(GLbitfield mask);

/* EXT_bgra */
#define GL_BGR_EXT                        0x80E0
#define GL_BGRA_EXT                       0x80E1

/* SGIS_texture_lod */
#define GL_TEXTURE_MIN_LOD_SGIS           0x813A
#define GL_TEXTURE_MAX_LOD_SGIS           0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS        0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS         0x813D

/* EXT_texture_compression_dxt1 */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1

/* EXT_texture_compression_s3tc */
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3

/* EXT_texture_lod_bias */
#define GL_MAX_TEXTURE_LOD_BIAS_EXT       0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT     0x8500
#define GL_TEXTURE_LOD_BIAS_EXT           0x8501

/* OES_query_matrix */
GLAPI GLbitfield APIENTRY glQueryMatrixxOES (GLfixed mantissa[16], GLint exponent[16]);

/* NV_combiner_program */
#define GL_COMBINER_PROGRAM_NV            0x890A
#define GL_PROGRAM_FORMAT_BINARY_NV       0x890B
// aliases with MAX_PROGRAM_ENV_PARAMETERS_ARB
#define GL_MAX_PROGRAM_ENV_PARAMETERS_NV  0x88B5 
#define GL_NUM_PROGRAM_FORMATS_NV         0x890C
#define GL_SUPPORTED_PROGRAM_FORMATS_NV   0x890D
// alias with MAX_TEXTURE_COORDS_ARB/MAX_TEXTURE_IMAGE_UNITS_ARB
#define GL_MAX_TEXTURE_COORDS_NV          0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV     0x8872

#ifdef GL_NV_combiner_program
#ifndef GLAPI
#define GLAPI
#endif
#ifndef APIENTRY
#define APIENTRY
#endif
GLAPI void APIENTRY glGenProgramsNV(GLsizei n, GLuint *programs);
GLAPI void APIENTRY glDeleteProgramsNV(GLsizei n, const GLuint *programs);
GLAPI void APIENTRY glProgramStringNV(GLenum target, GLenum format, GLsizei len, const GLubyte *program);
GLAPI void APIENTRY glProgramEnvParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glProgramEnvParameter4xNV(GLenum target, GLuint index, GLfixed x, GLfixed y, GLfixed z, GLfixed w);
GLAPI void APIENTRY glBindProgramNV(GLenum target, GLuint program);
GLAPI void APIENTRY glGetProgramivNV(GLenum target, GLenum pname, GLint *params);
#endif /* GL_NV_combiner_program */

/* OES_texture_cube_map */
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
GLAPI void APIENTRY glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexGeniv(GLenum coord, GLenum pname, GLint *params); 
GLAPI void APIENTRY glGetTexGenxv(GLenum coord, GLenum pname, GLfixed *params);
GLAPI void APIENTRY glTexGenfv(GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexGeniv(GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexGenxv(GLenum target, GLenum pname, const GLfixed *params);
GLAPI void APIENTRY glTexGenf(GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTexGeni(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexGenx(GLenum target, GLenum pname, GLfixed param);

/* NV_texgen_full */
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

/* OES_vertex_buffer_object */
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
typedef int GLsizeiptr;
typedef int GLintptr;
GLAPI GLvoid APIENTRY glGenBuffers(GLsizei cnt, GLuint *buffers);
GLAPI GLvoid APIENTRY glDeleteBuffers(GLsizei cnt, const GLuint *buffers);
GLAPI GLvoid APIENTRY glBindBuffer(GLenum target, GLuint name);
GLAPI GLvoid APIENTRY glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
GLAPI GLvoid APIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
GLAPI GLboolean APIENTRY glIsBuffer(GLuint name);
GLAPI GLvoid APIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
GLAPI GLvoid APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, GLvoid **params);
GLAPI void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI GLvoid *APIENTRY glMapBuffer(GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer(GLenum target);

/* NV_register_combiners */
#define GL_REGISTER_COMBINERS_NV          0x8522
#define GL_COMBINER0_NV                   0x8550
#define GL_COMBINER1_NV                   0x8551
#define GL_COMBINER2_NV                   0x8552
#define GL_COMBINER3_NV                   0x8553
#define GL_COMBINER4_NV                   0x8554
#define GL_COMBINER5_NV                   0x8555
#define GL_COMBINER6_NV                   0x8556
#define GL_COMBINER7_NV                   0x8557
#define GL_VARIABLE_A_NV                  0x8523
#define GL_VARIABLE_B_NV                  0x8524
#define GL_VARIABLE_C_NV                  0x8525
#define GL_VARIABLE_D_NV                  0x8526
#define GL_VARIABLE_E_NV                  0x8527
#define GL_VARIABLE_F_NV                  0x8528
#define GL_VARIABLE_G_NV                  0x8529
#define GL_CONSTANT_COLOR0_NV             0x852A
#define GL_CONSTANT_COLOR1_NV             0x852B
#define GL_PRIMARY_COLOR_NV               0x852C
#define GL_SECONDARY_COLOR_NV             0x852D
#define GL_SPARE0_NV                      0x852E
#define GL_SPARE1_NV                      0x852F
/*      GL_TEXTURE0_ARB */
/*      GL_TEXTURE1_ARB */
#define GL_UNSIGNED_IDENTITY_NV           0x8536
#define GL_UNSIGNED_INVERT_NV             0x8537
#define GL_EXPAND_NORMAL_NV               0x8538
#define GL_EXPAND_NEGATE_NV               0x8539
#define GL_HALF_BIAS_NORMAL_NV            0x853A
#define GL_HALF_BIAS_NEGATE_NV            0x853B
#define GL_SIGNED_IDENTITY_NV             0x853C
#define GL_SIGNED_NEGATE_NV               0x853D
#define GL_E_TIMES_F_NV                   0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_SCALE_BY_TWO_NV                0x853E
#define GL_SCALE_BY_FOUR_NV               0x853F
#define GL_SCALE_BY_ONE_HALF_NV           0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV   0x8541
#define GL_DISCARD_NV                     0x8530
#define GL_COMBINER_INPUT_NV              0x8542
#define GL_COMBINER_MAPPING_NV            0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV    0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV     0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV     0x8546
#define GL_COMBINER_MUX_SUM_NV            0x8547
#define GL_COMBINER_SCALE_NV              0x8548
#define GL_COMBINER_BIAS_NV               0x8549
#define GL_COMBINER_AB_OUTPUT_NV          0x854A
#define GL_COMBINER_CD_OUTPUT_NV          0x854B
#define GL_COMBINER_SUM_OUTPUT_NV         0x854C
#define GL_MAX_GENERAL_COMBINERS_NV       0x854D
#define GL_NUM_GENERAL_COMBINERS_NV       0x854E
#define GL_COLOR_SUM_CLAMP_NV             0x854F
// additional defines not part of the extension but used by it
#define GL_NONE                           0
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
GLAPI void APIENTRY glCombinerParameterfvNV(GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glCombinerParameterfNV(GLenum pname, GLfloat param);
GLAPI void APIENTRY glCombinerParameterivNV(GLenum pname, const GLint pv[]);
GLAPI void APIENTRY glCombinerParameteriNV(GLenum pname, GLint param);
GLAPI void APIENTRY glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI void APIENTRY glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);

/* NV_render_alpha_to_green */
#define GL_RENDER_ALPHA_TO_GREEN_NV       0x88BE

/* NV_fence */
#define GL_ALL_COMPLETED_NV               0x84F2
#define GL_FENCE_STATUS_NV                0x84F3
#define GL_FENCE_CONDITION_NV             0x84F4
GLAPI void APIENTRY glDeleteFencesNV(GLsizei n, const GLuint *fences);
GLAPI void APIENTRY glGenFencesNV(GLsizei n, GLuint *fences);
GLAPI void APIENTRY glGetFenceivNV(GLuint id, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsFenceNV(GLuint id);
GLAPI GLboolean APIENTRY glTestFenceNV(GLuint id);
GLAPI void APIENTRY glSetFenceNV(GLuint id, GLenum condition);
GLAPI void APIENTRY glFinishFenceNV(GLuint id);

/* NV_texture_rectangle */
#define GL_TEXTURE_RECTANGLE_NV           0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV   0x84F6
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV  0x84F8

/* OES_matrix_palette */
#define GL_MAX_VERTEX_UNITS_OES           0x86A4
#define GL_MAX_PALETTE_MATRICES_OES       0x8842
#define GL_MATRIX_PALETTE_OES             0x8840
#define GL_MATRIX_INDEX_ARRAY_OES         0x8844
#define GL_WEIGHT_ARRAY_OES               0x86AD
#define GL_MATRIX_INDEX_ARRAY_SIZE_OES    0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_OES    0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_OES  0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_OES 0x8849
#define GL_MATRIX_INDEX_ARRAY_BUFFER_BINDING_OES 0x8B9E
#define GL_WEIGHT_ARRAY_SIZE_OES          0x86AB
#define GL_WEIGHT_ARRAY_TYPE_OES          0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_OES        0x86AA
#define GL_WEIGHT_ARRAY_POINTER_OES       0x86AC
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_OES 0x889E
//#define GL_FAST_TWO_MATRIX_PALETTE_NV   0xFIND_VALUE //TODO:
GLAPI void APIENTRY glCurrentPaletteMatrixOES (GLuint matrixpaletteindex);
GLAPI void APIENTRY glLoadPaletteFromModelViewMatrixOES (void);
GLAPI void APIENTRY glMatrixIndexPointerOES (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GLAPI void APIENTRY glWeightPointerOES (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

/* OES_draw_texture */
#define GL_TEXTURE_CROP_RECT_OES          0x8B9D
GLAPI void APIENTRY glDrawTexsOES (GLshort x, GLshort y, GLshort z, GLshort width, GLshort height);
GLAPI void APIENTRY glDrawTexiOES (GLint x, GLint y, GLint z, GLint width, GLint height);
GLAPI void APIENTRY glDrawTexxOES (GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height);

GLAPI void APIENTRY glDrawTexsvOES (const GLshort *coords);
GLAPI void APIENTRY glDrawTexivOES (const GLint *coords);
GLAPI void APIENTRY glDrawTexxvOES (const GLfixed *coords);

GLAPI void APIENTRY glDrawTexfOES (GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
GLAPI void APIENTRY glDrawTexfvOES (const GLfloat *coords);

GLAPI void APIENTRY glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexParameteriv(GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexParameterxv (GLenum target, GLenum pname, const GLfixed *params);
GLAPI void APIENTRY glGetTexParameterxv (GLenum target, GLenum pname, GLfixed *params);

/* EXT_separate_specular_color */
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT  0x81F8
#define GL_SINGLE_COLOR_EXT               0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT    0x81FA

/* EXT_timer_query */
#define GL_QUERY_COUNTER_BITS_ARB         0x8864
#define GL_CURRENT_QUERY_ARB              0x8865
#define GL_QUERY_RESULT_ARB               0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB     0x8867
#define GL_TIME_ELAPSED_EXT               0x88BF

#if defined(_WIN32) && (_MSC_VER < 1300)
typedef unsigned __int64   GLuint64EXT;
typedef          __int64   GLint64EXT;
#else 
typedef unsigned long long GLuint64EXT;
typedef          long long GLint64EXT;
#endif

GLAPI void APIENTRY glGenQueriesARB (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glDeleteQueriesARB (GLsizei n, const GLuint *ids);
GLAPI GLboolean APIENTRY glIsQueryARB (GLuint id);
GLAPI void APIENTRY glBeginQueryARB (GLenum target, GLuint id);
GLAPI void APIENTRY glEndQueryARB (GLenum target);
GLAPI void APIENTRY glGetQueryObjectivARB (GLuint id, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectuivARB (GLuint id, GLenum pname, GLuint *params);
GLAPI void APIENTRY glGetQueryivARB (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjecti64vEXT (GLuint id, GLenum pname, GLint64EXT *params);
GLAPI void APIENTRY glGetQueryObjectui64vEXT (GLuint id, GLenum pname, GLuint64EXT *params);

#ifdef GL_OES_EGL_image
#define GL_TEXTURE_2D_OES                     0x1
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES    0x3
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES    0x4
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES    0x5
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES    0x6
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES    0x7
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES    0x8
#define GL_RENDERBUFFER_OES                   0x9
#define GL_TEXTURE_RECTANGLE_NV_OES           0xb

typedef struct nvGlEglOpaqueImage *  GLeglImageOES;
GLAPI void APIENTRY glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image);

#endif


/* NV_residence */
#define GL_TEXTURE_RESIDENT_NV               0x8067
GLAPI GLboolean APIENTRY glAreTexturesResidentNV(GLsizei n, GLuint *textures, GLboolean *residences);
GLAPI GLboolean APIENTRY glAreBuffersResidentNV(GLsizei n, GLuint *buffers, GLboolean *residences);

/* quad, polygon support - embedded ONLY */
#define GL_QUADS                             0x0007
#define GL_QUAD_STRIP                        0x0008
#define GL_POLYGON                           0x0009

#ifdef __cplusplus
}
#endif

#endif /* __glext_h_ */
