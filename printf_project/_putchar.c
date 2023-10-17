/**
* _putchar- Writes a character to the output buffer
* @c: The character to write
*
* Description:
* This function writes a character to the output buffer. If the buffer is full,
* it flushes the buffer to the standard output and resets the buffer index.
* Return: This function returns 1 on success or -1 on failure.
*/
int _putchar(char c)
{
	if (buffer_index < BUFFER_SIZE)
	{
		output_buffer[buffer_index++] = c;
	}
	else
	{
		write_buffer(); /* Flush the buffer */
		buffer_index = 0; /* Reset the buffer index */
		output_buffer[buffer_index++] = c;
	}
	return (1); /* Indicate success in adding the character to the buffer */
}
