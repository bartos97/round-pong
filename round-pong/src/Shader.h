#pragma once


class Shader
{
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();

    void bind() const;
    void unbind() const;

    void setUniform(const std::string& name, float x, float y, float z, float w);
    void setUniform(const std::string& name, float x, float y, float z);
    void setUniform(const std::string& name, float x, float y);
    void setUniform(const std::string& name, float x);
    void setUniform(const std::string& name, bool x);
    void setUniform(const std::string& name, int x);

private:
    unsigned int m_id;

    void readFiles(const char* vertexShaderPath,
                   const char* fragmentShaderPath,
                   std::string& vertexStr,
                   std::string& fragmentStr);
    void createShaderProgram(std::string& vertexStr, std::string& fragmentStr);
    unsigned int compileSingleShader(const char* shaderStr, GLenum shaderEnum);
};
