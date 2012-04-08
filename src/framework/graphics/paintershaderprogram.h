/*
 * Copyright (c) 2010-2012 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef PAINTERSHADER_H
#define PAINTERSHADER_H

#include "shaderprogram.h"
#include "coordsbuffer.h"
#include <framework/core/timer.h>

class PainterShaderProgram : public ShaderProgram
{
    enum {
        VERTEX_ATTR = 0,
        TEXCOORD_ATTR = 1,
        PROJECTION_MATRIX_UNIFORM = 0,
        TEXTURE_TRANSFORM_MATRIX_UNIFORM = 1,
        COLOR_UNIFORM = 2,
        OPACITY_UNIFORM = 3,
        TIME_UNIFORM = 4,
        TEX0_UNIFORM = 5,
        TEX1_UNIFORM = 6,
        //TEX2_UNIFORM = 7,
        //TEX3_UNIFORM = 8,
    };
public:
    enum DrawMode {
        Triangles = GL_TRIANGLES,
        TriangleStrip = GL_TRIANGLE_STRIP
    };

    PainterShaderProgram();

    bool link();

    void setProjectionMatrix(const Matrix3& projectionMatrix);
    void setColor(const Color& color);
    void setOpacity(float opacity);
    void setTexture(const TexturePtr& texture, int index = 0);
    void setUniformTexture(int location, const TexturePtr& texture, int index);
    void draw(CoordsBuffer& coordsBuffer, DrawMode drawMode = Triangles);

private:
    DrawMode m_drawMode;
    float m_startTime;
    TexturePtr m_textures[2];

    Color m_color;
    float m_opacity;
    Matrix3 m_projectionMatrix;
    Matrix2 m_textureTransformMatrix;
    float m_time;
    int m_lastTexture;
};

#endif
