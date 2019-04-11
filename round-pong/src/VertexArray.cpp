#include "pch.h"
#include "VertexArray.h"


VertexArray::VertexArray()
{
    GL_CALL(glGenVertexArrays(1, &m_id));
    GL_CALL(glBindVertexArray(m_id));
}


VertexArray::~VertexArray()
{
    GL_CALL(glDeleteVertexArrays(1, &m_id));
    RP_LOG("Vertex Array #%d deleted", m_id);
}


void VertexArray::bind() const
{
    GL_CALL(glBindVertexArray(m_id));
}


void VertexArray::unbind() const
{
    GL_CALL(glBindVertexArray(0));
}


void VertexArray::addBuffer(const VertexBuffer& vb, const BufferLayout& layout)
{
    bind();
    vb.bind();

    const auto& layoutElements = layout.getElements();
    unsigned int offset = 0;

    for (unsigned int i = 0; i < layoutElements.size(); i++)
    {
        const auto& el = layoutElements[i];
        glVertexAttribPointer(i, el.count, el.type, el.normalized, layout.getStride(), (const void*)offset);
        glEnableVertexAttribArray(i);
        offset += el.count * BufferLayout::getSizeOfGLtype(el.type);
    }

}
