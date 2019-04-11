#pragma once


struct BufferLayoutElement
{
    unsigned int count;
    GLenum type;
    GLboolean normalized;

    BufferLayoutElement(unsigned int count, GLenum type, GLboolean normalized)
        : count(count), type(type), normalized(normalized) {}
};


class BufferLayout
{
public:
    static unsigned int getSizeOfGLtype(GLenum type);

    BufferLayout()
        : m_stride(0) 
    {}

    const std::vector<BufferLayoutElement>& getElements() const
    {
        return m_elements;
    }

    unsigned int getStride() const
    {
        return m_stride;
    }


    template<typename T>
    void add(unsigned int count)
    {
        RP_ASSERT(false, "Invalid type when adding to buffer layout!");
    }

    template<>
    void add<float>(unsigned int count)
    {
        m_elements.emplace_back(count, GL_FLOAT, GL_FALSE);
        m_stride += count * BufferLayout::getSizeOfGLtype(GL_FLOAT);
    }

    template<>
    void add<unsigned int>(unsigned int count)
    {
        m_elements.emplace_back(count, GL_UNSIGNED_INT, GL_TRUE);
        m_stride += count * BufferLayout::getSizeOfGLtype(GL_UNSIGNED_INT);
    }

    template<>
    void add<unsigned char>(unsigned int count)
    {
        m_elements.emplace_back(count, GL_UNSIGNED_BYTE, GL_TRUE);
        m_stride += count * BufferLayout::getSizeOfGLtype(GL_UNSIGNED_BYTE);
    }

private:
    std::vector<BufferLayoutElement> m_elements;
    unsigned int m_stride;
};

