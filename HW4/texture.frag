
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    // TODO: pub with your code...
    //stbi_set_flip_vertically_on_load(true);
    float tempx = UV.x;  
    float tempy = UV.y;
    vec2 UV2;

    //if(mod(tempy, 0.66) == 0)
    UV2 = vec2( tempx , mod(tempy, 0.67));
    //else
      //UV2 = UV;

    color = texture( myTextureSampler, UV2);
}
