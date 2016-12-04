#version 330

in vec3 color;
in  vec2 TexCoord;

out vec4 outColor;
uniform sampler2D texData;

void main(){
  outColor = texture(texData, TexCoord) * vec4(color, 1.0); 
}
