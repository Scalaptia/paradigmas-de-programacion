process_file :-
   read(Line),
   Line \== end_of_file, % when Line is not not end of file, call process.
   process(Line).
process_file :- !. % use cut to stop backtracking

process(Line):- %this will print the line into the console
   write(Line),nl,
   process_file.