# Pricing-and-Replication-Strategy

## The file "Report.pdf" gives a description of the whole project.

<p>In this project we developed a program to “price” options using three
different methods: one using the Black-Scholes-Merton (BSM) model, the
second using the Monte Carlo method and the third using PDE. We started
by studying financial theory in order to fully understand the operation
and distinction between these two methods before implementing them in
C++.</p>
<p>On the one hand, the BSM model allows us to value options using an
explicit formula, which is only possible in certain cases and under
certain conditions. In particular, we considered European calls and puts
for this model. On the other hand, the Monte Carlo method allows us to
value options when there is no explicit formula. In this project, we
focused on the valuation of six products: calls, puts, binary (“digital
calls”, “digital puts” and “double digital calls”) and Asian options,
although the BSM and Monte Carlo methods are valid in many other cases.
Finally, as a bonus, our program provides a PDE valuation for European
vanilla options.</p>
