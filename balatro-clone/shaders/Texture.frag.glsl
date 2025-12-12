#version 130

uniform sampler2D u_Texture;
uniform bool u_IsHovered;

void main()
{
	// Use SFML's built-in variables
	vec2 texCoord = gl_TexCoord[0].xy;
	gl_FragColor = texture2D(u_Texture, texCoord);
	
	if (u_IsHovered)
		gl_FragColor.rgb += 0.2;
}
