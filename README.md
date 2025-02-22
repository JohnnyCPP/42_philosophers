# Philosophers

The goal of this project is to solve the dining philosophers problem, where a group of philosophers sit around a table with a fork placed between each pair.

## Project Overview

![42](./resources/42_madrid.jpg "42")

> 42 Madrid is an academy for values, attitude and learning "hard and soft skills" in the digital environment.
<br>
Philosophers is designed to teach students about multithreading and synchronization in a Unix-like environment, using the C programming language. The project is inspired by the dining philosophers problem, a classic synchronization problem in computer science.

Each philosopher alternates between thinking, eating, and sleeping. To eat, a philosopher needs to pick up the two forks adjacent to them.

The challenge is to prevent deadlocks, resource starvation, and ensure that all philosophers can eat without causing the system to freeze.

- Each philosopher is represented by a thread
- In the standard version, mutexes are used to protect shared resources (forks) to avoid race conditions
- Philosophers must avoid starving
- They must eat, sleep, and think for specific amounts of time

## Run

Clone the repository and run the following make targets:

```bash
git clone https://github.com/JohnnyCPP/42_philosophers.git
cd 42_philosophers
make help
make all
./philo 5 800 200 200 7
# it will stop once every philosopher eats 7 times
```

