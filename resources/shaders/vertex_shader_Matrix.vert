#version 330

uniform mat4 m_transform; // translation matrix

// input vertex packet
layout (location = 0) in vec2 position;
layout (location = 1) in vec4 colour;
layout (location = 2) in vec2 textureCoord;



// output vertex packet
out packet {

	vec4 colour;
	vec2 textureCoord;

} outputVertex;



void main(void) {

	outputVertex.colour = colour;
	outputVertex.textureCoord = textureCoord;

	vec4 pos = vec4(position.x, position.y, 0.0, 1.0);

	gl_Position = m_transform * pos; // MUST set gl_Position
}

