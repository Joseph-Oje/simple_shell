#include "p_shell.h"

/**
 * list_free - Free linked list
 *
 * Description:
 * @top: The top of the link_t list
 *
 * Return: void
 */
void list_free(link_t *top)
{
	link_t *nex;

	while (top)
	{
		nex = top->nex;
		free(top->dir);
		free(top);
		top = nex;
	}
}

/**
 * aliasend_add - Adds a node to the end of alias_t linked list
 *
 * Description:
 * @top: Pointer to the head of the alias_t list.
 * @name: Name of the new alias to add
 * @value: Value of the new alias to add
 *
 * Return: Pointer to the new node or NULL on error
 */
alias_t *aliasend_add(alias_t **top, char *name, char *value)
{
	alias_t *newAlias = malloc(sizeof(alias_t));
	alias_t *last;

	if (!newAlias)
		return (NULL);

	newAlias->nex = NULL;
	newAlias->name = malloc(sizeof(char) * (p_strlent(name) + 1));
	if (!newAlias->name)
	{
		free(newAlias);
		return (NULL);
	}
	newAlias->value = value;
	p_strcpy(newAlias->name, name);

	if (*top)
	{
		last = *top;
		while (last->nex != NULL)
			last = last->nex;
		last->nex = newAlias;
	}
	else
		*top = newAlias;

	return (newAlias);
}

/**
 * alias_freelist - Frees alias_t linked list
 *
 * Description:
 * @top: The top of the alias_t list
 *
 * Return: void
 */
void alias_freelist(alias_t *top)
{
	alias_t *nex;

	while (top)
	{
		nex = top->nex;
		free(top->name);
		free(top->value);
		free(top);
		top = nex;
	}
}

/**
 * core_add - Adds a node to the end of a link_t linked list.
 *
 * Description:
 * @top: Pointer to the top of the link_t list
 * @dir: Directory path for the new core
 *
 * Return: Pointer to the new core or NULL on error
 */
link_t *core_add(link_t **top, char *dir)
{
	link_t *newCore = malloc(sizeof(link_t));
	link_t *last;

	if (!newCore)
		return (NULL);

	newCore->dir = dir;
	newCore->nex = NULL;

	if (*top)
	{
		last = *top;
		while (last->nex != NULL)
			last = last->nex;
		last->nex = newCore;
	}
	else
		*top = newCore;

	return (newCore);
}

