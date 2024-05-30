path(a).                             /* Can start at a. */
path(Node) :- Mother is_parent Node, /* Choose parent, */
              path(Mother),          /* find path and then */ 
              write(Mother),
              write(' --> ').
              
/* Locate node by finding a path from root down to the node */
locate(Node) :- path(Node),
                write(Node),
                nl.