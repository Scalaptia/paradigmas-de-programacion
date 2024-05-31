% Hechos
food(burger).
food(sandwich).
food(pizza).
lunch(sandwich).
dinner(pizza).

% Reglas
meal(X) :- food(X).