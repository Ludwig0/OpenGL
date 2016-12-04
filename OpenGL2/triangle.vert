#version 330
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 texCoord;

out vec3 color;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    TexCoord = texCoord;
    color = vec3(inColor);
}
