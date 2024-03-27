#ifndef TOKENS_H
# define TOKENS_H

enum e_token_type
{
	VECTOR,
	FLOAT,
	RGB
};

typedef struct s_token
{
	enum e_token_type	type;
	int					index;
	void				(*parser)(void *target, char *src);
}						t_token;

#endif