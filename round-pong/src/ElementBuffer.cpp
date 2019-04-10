#include "pch.h"
#include "ElementBuffer.h"


ElementBuffer::ElementBuffer(unsigned int size, const void* data, GLenum usagePattern)
    : GLbuffer(GL_ELEMENT_ARRAY_BUFFER, size, data, usagePattern)
{}


void ElementBuffer::bind()
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}


void ElementBuffer::unbindAll()
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}