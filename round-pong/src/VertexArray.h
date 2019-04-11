#pragma once
#include "BufferLayout.h"
#include "VertexBuffer.h"


class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const BufferLayout& layout);
    void bind() const;
    void unbind() const;

private:
    unsigned int m_id;
};

