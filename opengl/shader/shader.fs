#version 330 core
out vec4 FragColor;  

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float visibility;
  
void main()
{
    // FragColor = vec4(ourColor, 1.0);
    // FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
    // FragColor = texture(texture2, TexCoord);
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(1 - TexCoord.x, TexCoord.y)), visibility) * vec4(ourColor, 1.0);

}