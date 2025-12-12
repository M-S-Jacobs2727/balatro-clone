#version 130

uniform mat4 u_Transform;

void main()
{
	// Use SFML's built-in variables - these work automatically with VertexArray
	gl_Position = u_Transform * gl_Vertex;
	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
}