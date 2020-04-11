#ifndef RENDER_BUFFER_H
#define RENDER_BUFFER_H

#include <GL/glew.h>

#include <GL/gl.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/mem.h"

struct renderbuffer {
    int position;
    int color;
    int texture;
    GLint vao;
    GLint vbo;
    GLint ebo;
    GLsizei vertex_pos;
    int vertex_limit;
    GLsizei index_pos;
    int index_limit;
    int index_offset;
    GLfloat *vertices;
    GLuint *indices;
};

typedef struct renderbuffer renderbuffer;

renderbuffer *renderbuffer_init(int position, int color, int texture, int vertex_limit, int index_limit);
void renderbuffer_zero(renderbuffer *self);

#endif
