#pragma once

/**
 * Base class for OpenGL's vertex bufffers and element (index) buffers
 */
class GLbuffer
{
public:
    virtual void bind() = 0;
    ~GLbuffer();

protected:
    GLbuffer(GLenum bindingTarget, unsigned int size, const void* data, GLenum usagePattern);
    unsigned int m_id;
};
