#include "main.h"

/**
 * buffer_init - Initialize the buffer structure
 * @buffer: Pointer to the Buffer structure
 *
 * Description:
 * This function initializes the buffer by setting its size to 0 and
 * null-terminating the data.
 */
void buffer_init(Buffer *buffer) {
    buffer->size = 0;
    buffer->data[0] = '\0';
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
void buffer_append_char(Buffer *buffer, char c) {
    if (buffer->size < BUFFER_SIZE - 1) {
        buffer->data[buffer->size] = c;
        buffer->size++;
        buffer->data[buffer->size] = '\0'; // Null-terminate the string
    } else {
        // Buffer is full, flush it and reset
        write(STDOUT_FILENO, buffer->data, buffer->size);
        buffer->size = 0;
        buffer->data[0] = '\0';
        buffer_append_char(buffer, c);
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
void buffer_flush(Buffer *buffer) {
    write(STDOUT_FILENO, buffer->data, buffer->size);
    buffer->size = 0;
    buffer->data[buffer->size] = '\0';
}

