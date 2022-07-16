


void main(void)
{	
	vec4 point = gl_Vertex;
	gl_Position = gl_ModelViewProjectionMatrix * point;
}