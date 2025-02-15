/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:20:49 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/15 13:23:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

// Function to get a random message from an array
const char *get_random_message(const char *messages[], int size)
{
	return messages[rand() % size];
}

void its_error(int ac, char **av)
{
	// Seed for random selection (call once at program start)
	srand(time(NULL));

	// Error messages collections
	const char *no_argument_msgs[] = {
		"\033[1;31m🚨 ERROR: No arguments provided! I need some input to work my magic. ✨\033[0m",
		"\033[1;31m🛑 Whoa! You forgot to pass an argument. Are you testing me? 🤔\033[0m",
		"\033[1;31m⚠️  Input required! Even wizards need instructions. 🧙‍♂️\033[0m",
		"\033[1;31m🚨 Oops! You forgot to pass an argument. I can't read minds... yet! 🤖\033[0m"
	};

	const char *too_many_args_msgs[] = {
		"\033[1;33m📢 Too many arguments! I'm not a supercomputer, keep it simple. 🧠\033[0m",
		"\033[1;33m❌ Whoa! You're overloading me with data! Try fewer arguments. 🤯\033[0m",
		"\033[1;33m⚠️  Less is more! Stick to the required number of inputs. 🎯\033[0m"
	};

	const char *invalid_julia_msgs[] = {
		"\033[1;34m🤔 Did you mean: ./fractol julia [x] [y]? Try again! 🧐\033[0m",
		"\033[1;34m🚀 Oops! 'julia' needs two numbers. Correct format: ./fractol julia [x] [y]\033[0m",
		"\033[1;34m📝 Looks like you mistyped something. Try: ./fractol julia X Y 📊\033[0m"
	};

	const char *invalid_mandelbrot_msgs[] = {
		"\033[1;36m🔍 Did you mean: ./fractol mandelbort? Check your spelling! 📝\033[0m",
		"\033[1;36m🤨 Something's off! Try: ./fractol mandelbort\033[0m",
		"\033[1;36m⚠️  Incorrect input! Just type: ./fractol mandelbort 🎨\033[0m"
	};

	const char *generic_error_msgs[] = {
		"\033[1;31m🛑 What kind of sorcery is this? Your input is all over the place! 🧙‍♂️\033[0m",
		"\033[1;31m⚠️  Mysterious error detected! Double-check your input. 🔍\033[0m",
		"\033[1;31m⛔ Something's off! Try again with the correct format. 📏\033[0m"
	};

	// Selecting and displaying messages randomly
	if (ac == 1)
		printf("%s\n", get_random_message(no_argument_msgs, 4));
	else if (ac > 4)
		printf("%s\n", get_random_message(too_many_args_msgs, 3));
	else if (ac == 4 && ft_strcmp(av[1], "julia") != 0)
		printf("%s\n", get_random_message(invalid_julia_msgs, 3));
	else if (ac != 4 && ft_strcmp(av[1], "julia") == 0)
		printf("%s\n", get_random_message(invalid_julia_msgs, 3));
	else if (ac == 2 && ft_strcmp(av[1], "mandelbort") != 0)
		printf("%s\n", get_random_message(invalid_mandelbrot_msgs, 3));
	else if (ac != 2 && ft_strcmp(av[1], "mandelbort") == 0)
		printf("%s\n", get_random_message(invalid_mandelbrot_msgs, 3));
	else
		printf("%s\n", get_random_message(generic_error_msgs, 3));
}