#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

typedef struct	s_user
{
	char 		*creation_order;
	int			id;
	struct tm	created_at;
}				t_user;

t_user	*create_user(char *order)
{
	t_user	*user = (t_user *)malloc(sizeof(t_user));
	time_t	now;

	if (!user)
		return(NULL);
	user->creation_order = strdup(order);
	if (!user->creation_order)
	{
		free(user);
		return (NULL);
	}
	user->id =  rand() % 9000 + 1000;
	time(&now);
	user->created_at = *localtime(&now);
	return (user);
}

void	print_user(void *data)
{
	t_user *user = (t_user *)data;
	printf("Order of creation : %s\n", user->creation_order);
	char created_at_buffer[26];
	strftime(created_at_buffer, 26, "%Y-%m-%d %H:%M:%S", &user->created_at);
	printf("ID: %d\nCreated at: %s\n", user->id, created_at_buffer);
}

void	del(void *data)
{
	t_user *user = (t_user *)data;
	free(user->creation_order);
	free(user);
}

void	*modify_user(void *data)
{
	t_user *old_user = (t_user *)data;
	t_user *new_user = (t_user *)malloc(sizeof(t_user));
	if (!new_user)
		return (NULL);
	const char *suffix = " (new list)";
	size_t new_length = strlen(old_user->creation_order) + strlen(suffix) + 1;
	new_user->id = old_user->id;
	new_user->created_at = old_user->created_at;
    new_user->creation_order = (char *)malloc(new_length);
	if (!new_user->creation_order)
	{
		free(new_user);
		return (NULL);
	}
	snprintf(new_user->creation_order, new_length, "%s%s", old_user->creation_order, suffix);
	return (new_user);
}

int main(void)
{
	srand(time(NULL));
	t_user *head = create_user("1");
	sleep(1);
	t_user *user1 = create_user("2");
	sleep(1);
	t_user *user2 = create_user("3");
	if (!head || !user1 || !user2)
	{
		fprintf(stderr, "Failed to create user\n");
		return (EXIT_FAILURE);
	}
	t_list *list = ft_lstnew(head);
	ft_lstadd_front(&list, ft_lstnew(user1));
	ft_lstadd_back(&list, ft_lstnew(user2));
	printf(MAGENTA "Test of the functions manipulating a list:\n" RESET);
	printf("Size of the list: %d nodes.\n", ft_lstsize(list));
	ft_lstiter(list, print_user);
	printf("------------------------------------\n");
	t_list *new_list = ft_lstmap(list, modify_user, del);
	if (!new_list)
	{
		fprintf(stderr, "Failed to create new_list\n");
		ft_lstclear(&list, del);
		return (EXIT_FAILURE);
	}
	printf("Size of the new list: %d nodes.\n", ft_lstsize(list));
	ft_lstiter(new_list, print_user);
	ft_lstclear(&list, del);
	ft_lstclear(&new_list, del);
	return (EXIT_SUCCESS);
}