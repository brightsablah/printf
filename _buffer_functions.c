#include "main.h"

/**
* buffer_init - Initialize the buffer structure
* @buffer: Pointer to the Buffer structure
*
* Description:
* This function initializes the buffer by setting its size to 0 and
* null-terminating the data.
*/
void buffer_init(Buffer *buffer)
{
		if (buffer != NULL)
	{
		buffer->buffer_index = 0;
		buffer->output_buffer[0] = '\0';
	}
}

/**
* buffer_append_char - Append a character to the buffer
* @buffer: Pointer to the Buffer structure
* @c: The character to append
*
* Description:
* This function appends a character to the buffer. If the buffer is full,
* it is flushed to the standard output.
*/
void buffer_append_char(Buffer *buffer, char c)
{
	if (buffer != NULL)
	{
		if (buffer->buffer_index < BUFFER_SIZE)
		{
			buffer->output_buffer[buffer->buffer_index++] = c;
		}
	else
		{
			buffer_flush(buffer);
			buffer->output_buffer[buffer->buffer_index++] = c;
		}
	}
}

/**
* buffer_flush - Flush the buffer to stdout
* @buffer: Pointer to the Buffer structure
*
* Description:
* This function flushes the buffer to the standard output and resets the
* buffer's size and data.
*/
void buffer_flush(Buffer *buffer)
{
	if (buffer != NULL && buffer->buffer_index > 0)
	{
		write(STDOUT_FILENO, buffer->output_buffer, buffer->buffer_index);
		buffer_init(buffer);
	}
}

