#include "pch.h"
#include "VertexBuffer.h"


VertexBuffer::VertexBuffer(unsigned int size, const void* data, GLenum usagePattern)
    : GLbuffer(GL_ARRAY_BUFFER, size, data, usagePattern)
{}


void VertexBuffer::bind() const
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
    RP_LOG("VertexBuffer #%d is now bound", m_id);
}


void VertexBuffer::unbindAll()
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
    RP_LOG("No VertexBuffer bound.");
}