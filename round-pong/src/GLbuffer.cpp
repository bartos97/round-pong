#include "pch.h"
#include "GLbuffer.h"

GLbuffer::~GLbuffer()
{
    GL_CALL(glDeleteBuffers(1, &m_id));
    RP_LOG("Buffer #%d deleted", m_id);
}


GLbuffer::GLbuffer(GLenum bindingTarget, unsigned int size, const void* data, GLenum usagePattern)
{
    GL_CALL(glGenBuffers(1, &m_id));
    GL_CALL(glBindBuffer(bindingTarget, m_id));
    GL_CALL(glBufferData(bindingTarget, size, data, usagePattern));
    RP_LOG("Buffer #%d created and bound.", m_id);
}