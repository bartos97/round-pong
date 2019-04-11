#include "pch.h"
#include "ElementBuffer.h"


ElementBuffer::ElementBuffer(unsigned int count, const unsigned int* data, GLenum usagePattern)
    : GLbuffer(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, usagePattern)
{}


void ElementBuffer::bind() const
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}


void ElementBuffer::unbindAll()
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}