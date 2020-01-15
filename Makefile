fmt:
	find . -name "*.c" | xargs -I {} indent -i8 -linux {} -o {}
