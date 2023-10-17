#include "main.h"
#include "main.h"
/**
* write_buffer - Writes the contents of the output buffer to stdout
*
* Description:
* This function writes the contents of the output buffer
* to the standard output (stdout).
*/
void write_buffer(void)
{
 /* Write the contents of the buffer to stdout */
write(STDOUT_FILENO, output_buffer, buffer_index);
}
