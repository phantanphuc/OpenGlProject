GLuint blockIndex = glGetUniformBlockIndex(shaderProgram, "BlobSettings");
		GLint blockSize;

		glGetActiveUniformBlockiv(shaderProgram, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

		GLubyte * blockBuffer = new GLubyte[blockSize];

		const GLchar *names[] = { "InnerColor", "OuterColor", "RadiusInner", "RadiusOuter" };

		GLuint indices[4];
		glGetUniformIndices(shaderProgram, 4, names, indices);

		GLint offset[4];
		glGetActiveUniformsiv(shaderProgram, 4, indices, GL_UNIFORM_OFFSET, offset);
		GLfloat outerColor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat innerColor[] = { 0.0f, 1.0f, 0.05f, 1.0f };
		GLfloat innerRadius = 0.25f, outerRadius = 0.45f;

		memcpy(blockBuffer + offset[0], innerColor, 4 * sizeof(GLfloat));
		memcpy(blockBuffer + offset[1], outerColor, 4 * sizeof(GLfloat));
		memcpy(blockBuffer + offset[2], &innerRadius, sizeof(GLfloat));
		memcpy(blockBuffer + offset[3], &outerRadius, sizeof(GLfloat));



		GLuint uboHandle;
		glGenBuffers(1, &uboHandle);
		glBindBuffer(GL_UNIFORM_BUFFER, uboHandle);
		glBufferData(GL_UNIFORM_BUFFER, blockSize, blockBuffer, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, uboHandle);
		
		glUniformBlockBinding(shaderProgram, blockIndex, 1);
		delete blockBuffer;