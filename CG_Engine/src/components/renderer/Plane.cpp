#include "CG/components/renderer/ShapeRenderer.hpp"
#include "CG/rendering/ShaderProgram.hpp"
#include "CG/rendering/GLTrianglesBuilder.hpp"

CG::ShapeRenderer CG::ShapeRenderer::Plane()
{
	GLTrianglesBuilder builder;


#define P +0.5
#define N -0.5
	builder.vertices = {
		{{N, N, 0}, Vector3::Forward(), Color::White()},
		{{P, N, 0}, Vector3::Forward(), Color::White()},
		{{P, P, 0}, Vector3::Forward(), Color::White()},
		{{N, P, 0}, Vector3::Forward(), Color::White()},
	};
#undef P
#undef N

	builder.indices = {
		0, 1, 2,
		0, 2, 3,
	};

	return CG::ShapeRenderer(std::move(builder.build()));

	/*GLuint vbo;
	GLCall(glGenBuffers(1, &vbo));

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

	GLCall(glGenVertexArrays(1, &m_drawable.vao));
	GLCall(glBindVertexArray(m_drawable.vao));
	GLCall(glVertexAttribPointer(0,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void *)offsetof(Vertex, position)));
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(1,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void *)offsetof(Vertex, normal)));
	GLCall(glEnableVertexAttribArray(1));
	GLCall(glVertexAttribPointer(2,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void *)offsetof(Vertex, color)));
	GLCall(glEnableVertexAttribArray(2));*/
}
