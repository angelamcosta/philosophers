# Philosophers 🍝💭💤

<div align=center>

  ![badge](https://raw.githubusercontent.com/angelamcosta/angelamcosta/main/42_badges/philosopherse.png)

  [![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)  [![forthebadge](https://forthebadge.com/images/badges/built-by-codebabes.svg)](https://forthebadge.com)
</div>

Philosophers is a simulation program written in C that represents a classic dining philosophers problem. The program simulates a group of philosophers sitting at a round table, alternating between eating, thinking, and sleeping. Their goal is to avoid starvation while sharing a bowl of spaghetti and a limited number of forks. The subject of the project can be found in this [link](https://raw.githubusercontent.com/angelamcosta/philosophers/main/en.subject.pdf).

## 📜 Problem Description

Here are the key details of the problem:

- A group of philosophers sits at a round table with a large bowl of spaghetti in the middle.
- The philosophers alternate between three states: eating, thinking, and sleeping.
- While a philosopher is eating, they cannot think or sleep. The same applies to the other states.
- Each philosopher requires two forks to eat. There are as many forks on the table as there are philosophers.
- After finishing their meal, philosophers put their forks back on the table and start sleeping. Upon waking up, they resume thinking.
- The simulation continues until a philosopher dies of starvation.
- It is crucial to ensure that every philosopher has an opportunity to eat and does not starve.
- Philosophers do not communicate or interact directly with each other.
- Philosophers are unaware if another philosopher is on the verge of starvation.
- The objective is to prevent philosophers from dying.

## 🚦 Program Rules

To succeed in this assignment, follow these rules:

- Global variables are forbidden.
- The program should take the following command-line arguments:
  - `number_of_philosophers`: The number of philosophers (also the number of forks).
  - `time_to_die` (in milliseconds): If a philosopher doesn't start eating within this time after their last meal or the beginning of the simulation, they die.
  - `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat, requiring both forks.
  - `time_to_sleep` (in milliseconds): The time a philosopher spends sleeping.
  - `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops when all philosophers have eaten at least this number of times. Otherwise, it stops when a philosopher dies.
- Each philosopher is assigned a number from 1 to `number_of_philosophers`.
- Philosopher number 1 sits next to philosopher number `number_of_philosophers`. For other philosophers N, they sit between N-1 and N+1.
- The program should display the state changes of philosophers in a specific format, including timestamp and philosopher number.
- Log messages for state changes should be distinct and not mixed with other messages.
- The message announcing a philosopher's death should be displayed within 10 ms of their actual death.
- The program must avoid data races.

## 📂 Program Structure

The Philosophers repository has the following folder structure:

- files/: The main folder containing the source code and necessary files.
  - philo.h: Header file with function prototypes and definitions for the Philosophers program.
  - philo.c: Source code file containing the main implementation of the dining philosophers simulation.
  - print_utils/: Subfolder containing the implementation of a custom printf function.
  - utils/: Subfolder containing utility files used by the Philosophers program.

## 🚀 Usage

To compile the Philosophers program, navigate to the `files/` directory and run the following command:

```
make
```

This will generate an executable named `philo`.

To launch the simulation, use the following command:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Replace the arguments in square brackets with the appropriate values.
