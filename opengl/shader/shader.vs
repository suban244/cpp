#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec2 aTexCoord;
  
out vec3 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

uniform float offset;
uniform mat4 model, view, projection, transform;

void main()
{
    gl_Position = projection * view * model * transform * vec4(aPos.xyz, 1.0);
    TexCoord = aTexCoord;
}  