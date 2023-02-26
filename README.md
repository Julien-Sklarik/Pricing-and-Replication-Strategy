# Pricing-and-Replication-Strategy

## Overview

The file Report.pdf gives a detailed description of the project.

In this project, we developed a program to price options using three different methods: Black-Scholes-Merton (BSM), Monte Carlo, and PDE. We studied financial theory to fully understand the operation and distinction between these methods before implementing them in C++.

## Pricing Methods

- BSM: allows us to value options using an explicit formula, which is only possible in certain cases and under certain conditions. In particular, we considered European calls and puts for this model.

- Monte Carlo: allows us to value options when there is no explicit formula. In this project, we focused on the valuation of six products: calls, puts, binary (“digital calls”, “digital puts” and “double digital calls”) and Asian options, although the BSM and Monte Carlo methods are valid in many other cases.

- PDE: partial differential equations provide another valuation method for European vanilla options.

## Program Features

### Use case

Here is the user interaction loop:

1. A command to be executed is requested from the user.
2. The user gives either a pricing command or an auxiliary command (i.e. "quit" or "help").
3. The program executes the command.
4. If there is an error, a message is displayed. Otherwise, an answer is given.
5. The program goes back to step 1 and waits for the user’s next action unless the command "quit" is selected.

Example:

When the user selects PDEcall or PDEput, we ask him to enter the parameters of the option: time to expiry, risk-free interest rate, volatility, and a maximum strike price. As an output, the user receives a plot of the market value of the option as a function of a spot price and a time to expiry. 😃

### Architecture

#### Fundamental structure

The code is structured around the Console and Command classes. The Console class contains the user interaction loop.

A distinction is made between the pricing commands which are used to determine the price of an option and the auxiliary commands which participate in the operation of the program: help displays a help message to detail the available commands with their descriptions, and quit terminates the program.

All pricing commands are child classes of the Command class. The parent class Command contains everything that is common to all the commands, and the child classes contain their respective specific functions.

#### Container

As the list of parameters can vary from one function to another, we decided to store them in a container. All parameters are character strings (entered by the user on the keyboard) in the application. As parameters can be numbers or dates, transformations take place in the code when needed. The type of container that we chose allows the parameters to be stored in a dictionary.
