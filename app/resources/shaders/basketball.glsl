//#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;

layout (location = 2) in vec2 aTexCoords;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout (location = 1) in vec3 aNormal;
out vec3 Normal;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoords = aTexCoords;
    Normal = mat3(transpose(inverse(model))) * aNormal;
}

//#shader fragment
#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;

uniform sampler2D texture_diffuse1;

void main() {
    vec3 norm = normalize(Normal);
    vec3 light_direction = normalize(vec3(1.0, 1.0, 1.0));

    float diffuse = max(dot(norm, light_direction), 0.0);
    float ambient = 0.2;

    vec3 texture_color = texture(texture_diffuse1, TexCoords).rgb;
    vec3 result = (ambient + 0.8 * diffuse) * texture_color;

    FragColor = vec4(result, 1.0);
}