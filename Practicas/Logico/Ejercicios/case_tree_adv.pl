height(N,H) :- setof(Z,ht(N,Z),Set),
               max(Set,0,H).
               
ht(Node,0) :- leaf_node(Node),!.
ht(Node,H) :- Node is_parent Child,
              ht(Child,H1),
              H is H1 + 1.
max([],M,M).
max([X|R],M,A) :- (X > M -> max(R,X,A) ; max(R,M,A)).