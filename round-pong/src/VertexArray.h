#pragma once
#include "BufferLayout.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"


class VertexArray
{
public:
    ~VertexArray();

    VertexArray();
    VertexArray(const VertexBuffer& vb, const ElementBuffer& eb, const BufferLayout& layout);

    void addBuffer(const VertexBuffer& vb, const BufferLayout& layout);
    void addBuffer(const ElementBuffer& eb);
    void bind() const;
    void unbind() const;

    const VertexBuffer& getVertexBuffer() const;
    const ElementBuffer& getElementBuffer() const;

private:
    unsigned int m_id;
    const VertexBuffer* m_vertexBuffer;
    const ElementBuffer* m_elementBuffer;
    static const VertexArray* m_currentlyBound;
};

