/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:42:14 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 02:46:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_a_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	for_tests(t_stack *stack_a, t_stack *stack_b, int size)
{
	int (i) = 1;
	t_stack	*(tempo_a) = stack_a;
	t_stack *(tempo_b) = stack_b;

	ft_printf("\033[35;01m| Stack_a valid !  size %2d |\033[00m\n", size);
	while (i < size)
	{
		if (tempo_a)
		{
			ft_printf("\033[34;01m| stack_a %2d =\033[00m %11d \033[34;01m|\033[00m \033[36;01midx = %2d\033[00m", i, tempo_a->value, tempo_a->index);
			tempo_a = tempo_a->next;
		}
		else if (!tempo_a)
			ft_printf("%37c", ' ');
		if (tempo_b)
		{
			ft_printf("\033[32;01m\t| stack_b %2d =\033[00m %11d \033[32;01m|\033[00m \033[33;01midx = %2d\033[00m\n", i, tempo_b->value, tempo_b->index);
			tempo_b = tempo_b->next;
		}
		else if (!tempo_b)
			ft_printf("\n");
		i++;
	}
	ft_printf("\033[34;01m| stack_a %2d =\033[00m %11d \033[34;01m|\033[00m \033[36;01midx = %2d\033[00m", i, tempo_a->value, tempo_a->index);
	if(tempo_b)
		ft_printf("\033[32;01m\t| stack_b %2d =\033[00m %11d \033[32;01m|\033[00m \033[33;01midx = %2d\033[00m\n", i, tempo_b->value, tempo_b->index);
	else if (!tempo_b)
		ft_printf("\n");
	if (!ft_stack_a_is_sorted(stack_a))
		ft_printf("\033[31;01m|  Stack_a not sorted  !!  |\033[00m\n");
	else
		ft_printf("\033[32;01m|    Stack_a sorted  !!    |\033[00m\n");
	return ;
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !ft_stack_a_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3 && !ft_stack_a_is_sorted(*stack_a))
		ft_triad_sorting(stack_a);
	else if (size > 3 && !ft_stack_a_is_sorted(*stack_a))
		ft_sorting(stack_a, stack_b, size);
	return ;
}

static void	ft_give_index(t_stack *stack_a, int size)
{
	t_stack	*tempo_a;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		tempo_a = stack_a;
		highest = NULL;
		value = -2147483648;
		while (tempo_a)
		{
			if (tempo_a->value == -2147483648 && tempo_a->index == 0)
				tempo_a->index = 1;
			if (tempo_a->value > value && tempo_a->index == 0)
			{
				highest = tempo_a;
				value = tempo_a->value;
				tempo_a = stack_a;
			}
			else
				tempo_a = tempo_a->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	char	**list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	list = ft_check_input(argv);
	if (list == NULL)
		ft_error(NULL, NULL);
	stack_a = ft_make_stack_a(list);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	ft_give_index(stack_a, size + 1);

	for_tests(stack_a, stack_b, size);
	push_swap(&stack_a, &stack_b, size);
	for_tests(stack_a, stack_b, size);

	ft_xav_the_stack(&stack_b);
	ft_xav_the_stack(&stack_a);
	return (0);
}

/*

	verif du nbr d'args:
		• Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
		l’invite de commande.

//		verif_input.c	//
	verif des args:
		• En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
		Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
		un int, ou encore, s’il y a des doublons.

//		.c	//
	creation de la liste:
		• prend en paramètre la pile a sous la forme d’une liste d’entiers.
		Le premier paramètre est au sommet de la pile.

	indexer la liste:
		• donne a chaque element de la liste un index corespondent a sa place dans la pile final.

	creation des instruction de tri:
		• sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
			Ne fait rien s’il n’y en a qu’un ou aucun.
		• sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
			Ne fait rien s’il n’y en a qu’un ou aucun.
		• ss : sa et sb en même temps.

		• pa (push a) : Prend le premier élément au sommet de b et le met sur a.
			Ne fait rien si b est vide.
		• pb (push b) : Prend le premier élément au sommet de a et le met sur b.
			Ne fait rien si a est vide.

		• ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
			Le premier élément devient le dernier.
		• rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
			Le premier élément devient le dernier.
		• rr : ra et rb en même temps.

		• rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
			la pile a. Le dernier élément devient le premier.
		• rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
			la pile b. Le dernier élément devient le premier.
		• rrr : rra et rrb en même temps.

	algo:
		• prendre le nbr complet d'element dans la pile a
		• diviser se nbr par 2 pour enssuite trouver le pgcd
		• push dans b les nbr dans l'ordre croissant en stash de valeur pgcd
		• push dans a en fonction du calcul de coup
*/
