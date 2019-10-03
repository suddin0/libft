#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"

# define INTERNAL_STRING_PACK_DATA_SIZE	5



typedef struct s_internal_string_pack
{
	unsigned char				data[INTERNAL_STRING_PACK_DATA_SIZE];
	size_t						len;	/* number of element in `data` */

	/* A hash of the string */
	struct s_internal_string	*prev;
	struct s_internal_string	*next;
}				t_internal_string_pack;

typedef struct	s_string
{
	char					*data;		/* The whole string */
	size_t					data_len;	/* The length of the data */
	size_t					data_size;	/* The length of the data */

	size_t					cur;		 /* Cursor */
	size_t					len;		 /* Length of the string */
	/* The hash of the string */

	/* Node related */
	t_internal_string_pack *node_start;	/* Begining of the node*/
	t_internal_string_pack *node_cur;	/* current node */
	t_internal_string_pack *node_last;	/* Last node */
	size_t					node_len;	/* Number of nodes */



}				t_string;

// str_set_curs

// str_append
// str_char_cmp
// str_str_cmp
// str_char_cpy
// str_str_cpy
// str_char_dup
// str_str_dup

/*
**	Public functions
*/

void					str_char_append(t_string *dest,\
							const unsigned char *str);


/*
**	Privet functions
*/

t_internal_string_pack	*internal_string_pack_new(void);
int						str_init(t_string *string);
#endif
