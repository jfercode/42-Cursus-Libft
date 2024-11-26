#include "../include/libft.h"

void check_ft_lstnew_bonus()
{
	t_list		*elem;
	char	str [] = "lorem ipsum dolor sit";

	printf("/* ft_lstnew_bonus Check */\n");
	if (!(elem = ft_lstnew(str)))
		printf("NULL");
	else
	{
		if (!(elem->content))
			printf("NULL");
		else
		{
			printf("content ptr: %p\n", elem->content);
		}
		if (!(elem->next))
		{
			printf("next: NULL");
		}
	}
	printf("\n");
}

void check_ft_lstadd_front()
{
	printf("/* ft_lstadd_front Check */ \n");
	char	str01[] = "lorem ipsum";
	char	str02[] = "dolor sit";

	t_list	*node01 = ft_lstnew(str01);
	t_list	*node02 = ft_lstnew(str02);

	printf("cont ptr node01: %s || next node01: %p\n", (char *)node01->content, (void *)node01->next);
	printf("cont ptr node02: %s || next node02: %p\n", (char *)node02->content, (void *)node02->next);
	
	printf("node01->node02\n");
	ft_lstadd_front(&node02, node01);

	printf("After ft_lstadd_front:\n");
	printf("cont node01 %s || next node01 ptr: %p\n", (char *)node01->content, (char *)node01->next->content);
	printf("cont node02: %s || next node02 ptr: %p\n", (char *)node01->next->content, (void *)node01->next->next);
}

void	check_ft_lstsize()
{
	printf("/* ft_lstsize check */\n");
	t_list *node01 = ft_lstnew("Hola");
	t_list *node02 = ft_lstnew("Mundo");
	t_list *node03 = ft_lstnew("Nuevo");
	node01->next = node02;
	node02->next = node03;
	printf("t_list with 3 nodes size: %d\n", ft_lstsize(node01));
}

void	check_ft_lstlast()
{
	printf("/* ft_lstlast check */\n");
	t_list *node01 = ft_lstnew("Hola");
	printf("cont ptr node01: %s || next node01: %p\n", (char *)node01->content, (void *)node01->next);
	t_list *node02 = ft_lstnew("Mundo");
	printf("cont ptr node02: %s || next node02: %p\n", (char *)node02->content, (void *)node02->next);
	t_list *node03 = ft_lstnew("Nuevo");
	printf("cont ptr node03: %s || next node03: %p\n", (char *)node03->content, (void *)node03->next);
	node01->next = node02;
	node02->next = node03;
	printf("node01->node02->node03\n");
	printf("last node content: %s || last node ptr: %p\n", (char *)ft_lstlast(node01)->content, (void *)ft_lstlast(node01)->next);
}

void	check_ft_lstadd_back()
{
	printf("/* ft_lstadd_front Check */ \n");
	char	str01[] = "lorem ipsum";
	char	str02[] = "dolor sit";

	t_list	*node01 = ft_lstnew(str01);
	t_list	*node02 = ft_lstnew(str02);

	printf("cont ptr node01: %s || next node01: %p\n", (char *)node01->content, (void *)node01->next);
	printf("cont ptr node02: %s || next node02: %p\n", (char *)node02->content, (void *)node02->next);

	printf("node01->node02\n");
	ft_lstadd_back(&node01, node02);

	printf("After ft_lstadd_back:\n");
	printf("cont node01 %s || next node01: %p\n", (char *)node01->content, (char *)node01->next->content);
	printf("cont node02: %s || next node02: %p\n", (char *)node01->next->content, (void *)node01->next->next);
}

void	my_del(void *content)
{
    free(content);
}

void	check_ft_lstdelone()
{
    printf("/* ft_lstdelone Check */ \n");
    char *str = strdup("lorem ipsum");
    t_list *node = ft_lstnew(str);
	printf("content node: %s || next node: %p\n", (char *)node->content, node->next);
    ft_lstdelone(node, my_del);
	printf("node deleted\n");
}

void	check_ft_lstclear()
{
	printf("/* ft_lstclear check */\n");
	t_list *list = ft_lstnew(strdup("Node 1"));
    list->next = ft_lstnew(strdup("Node 2"));
    list->next->next = ft_lstnew(strdup("Node 3"));
    printf("Original list:\n");
    t_list *temp = list;
    while (temp) {
        printf("%s -> ", (char *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
    ft_lstclear(&list, my_del);
    printf("List after clearing:\n");
    if (list == NULL) {
        printf("List is NULL (cleared successfully)\n");
    } else {
        temp = list;
        while (temp) {
            printf("%s -> ", (char *)temp->content);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void	ft_modify_list_with_d(void *elem)
{
	int		len;
	char	*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		content[len++] = 'd';
	}
}

void	check_ft_lstiter()
{
	printf("/* ft_lstiter check */\n");
	t_list *node = ft_lstnew(strdup("Node01"));
	node->next = ft_lstnew(strdup("Node02"));
	node->next->next = ft_lstnew(strdup("Node03"));
	printf("Originl list:\n");
	t_list *temp = node;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstiter(node, ft_modify_list_with_d);
	printf("Apply function iter\n");
	if (node->content)
	{	
		t_list *temp = node;
		while (temp)
		{
			printf("%s ", (char *)temp->content);
			temp = temp->next;
		}
	}
	printf("\n");
}

void	*modify_with_s(void *content)
{
	(void)content;
	char *new_content = strdup("ssssss");
	return new_content;
}
void	check_ft_lstmap()
{
	printf("/* ft_lstmap check */\n");
	t_list *node = ft_lstnew(strdup("Node01"));
	node->next = ft_lstnew(strdup("Node02"));
	node->next->next = ft_lstnew(strdup("Node03"));
	printf("Originl list:\n");
	t_list *temp = node;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	
	t_list *new_lst = ft_lstmap(node, modify_with_s, my_del);	
	printf("Apply function map\n");
	while (new_lst)
	{
		printf("%s ",(char *)new_lst->content);
		new_lst = new_lst->next;
	
	}
	printf("\n");

}

int	main (void)
{
	check_ft_lstnew_bonus();
	check_ft_lstadd_front();
	check_ft_lstsize();
	check_ft_lstlast();
	check_ft_lstadd_back();
	check_ft_lstdelone();
	check_ft_lstclear();
	check_ft_lstiter();
	check_ft_lstmap();

	return (0);
}
