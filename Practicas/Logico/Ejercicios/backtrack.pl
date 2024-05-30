# boy(tom).
# boy(bob).
# girl(alice).
# girl(lili).

# pay(X,Y) :- boy(X), girl(Y).

# f(X,0) :- X < 3.              % Rule 1
# f(X,2) :- 3 =< X, X < 6.   % Rule 2
# f(X,4) :- 6 =< X.             % Rule 3

f(X,0) :- X < 3,!.            % Rule 1
f(X,2) :- 3 =< X, X < 6,!. % Rule 2
f(X,4) :- 6 =< X.             % Rule 3