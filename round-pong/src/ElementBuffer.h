#pragma once
#include "GLbuffer.h"

class ElementBuffer : public GLbuffer
{
public:
    /**
     * Generates and binds Element Buffer Object (or Index Buffer, if you like)
     * @param size - size in bytes of given data
     * @param data - self-explanatory
     * @param usagePattern - specifies the expected usage pattern of the data store
     * by default it is GL_STATIC_DRAW
     */
    ElementBuffer(unsigned int size, const void* data, GLenum usagePattern = GL_STATIC_DRAW);

    virtual void bind() override;
    static void unbindAll();
};

