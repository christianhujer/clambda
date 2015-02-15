#ifndef CLAMBDA_H
#define CLAMBDA_H

/** Defines a lambda expression of a specifyable return type.
 * @param R
 *      Return type of the lambda expression.
 * @param P
 *      Parameters of the lambda expression.
 * @param ...
 *      Code of the lambda expression.
 */
#define lambda(R, P, ...) ({ R lambda P { __VA_ARGS__ ; } lambda; })

/** Defines a lambda expression of return type void.
 * @param P
 *      Parameters of the lambda expression.
 * @param ...
 *      Code of the lambda expression.
 */
#define l(P, ...) lambda(void, P, ##__VA_ARGS__)

#endif
