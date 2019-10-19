#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"

# define STRING_ERROR -1
# define STRING_SUCCESS 0

# define PRIVATE_STRING_PACK_DATA_SIZE	2


typedef struct s_private_string_pack
{
	char							data[PRIVATE_STRING_PACK_DATA_SIZE];
	size_t							len;	/* number of element in `data` */

	/* A hash of the string */
	struct s_private_string_pack	*prev;
	struct s_private_string_pack	*next;
}				t_priv_string_pack;

typedef struct	s_private_index
{
	size_t	index;
	int		index_moved;
}				t_priv_index;

typedef struct	s_private_string_data
{
		char	*data;		/* The whole string */
		size_t	data_len;	/* The length of the data */
		size_t	data_size;	/* The length of the data */
}				t_priv_data;

typedef struct	s_string
{
	t_priv_data			data;		/* Contains the string (char *) */

	t_priv_index		index;		 /* current index */
	size_t					len;		 /* Length of the string */
	/* The hash of the string */

	/* Node related */
	t_priv_string_pack *node_start;	/* Begining of the node*/
	t_priv_string_pack *node_cur;	/* current node */
	t_priv_string_pack *node_last;	/* Last node */
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

t_string				*str_new(const char *str);
void					str_add(t_string *dest, const char *str);
void					str_free(t_string *string);
char					*str_get_string(t_string *string);

/*
**	Privet functions
*/

t_priv_string_pack	*priv_string_pack_new(void);
int					priv_str_init(t_string *string);
ssize_t				priv_str_add(t_string *dest, const char *src);
int					priv_str_pack_add_char(t_string *string,const char ch);
int					priv_str_pack_node_add(t_string *string);


#endif
