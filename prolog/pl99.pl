%http://www.ic.unicamp.br/~meidanis/courses/mc336/2009s2/prolog/problemas/index.html

:- use_module(library(lists)).

% prolog 99

% P01, last element of list
my_last(X,[X]).
my_last(X,[_|T]) :- my_last(X,T).

% without recursion
my_last2(X,L) :- append(_,[X],L).

% P02, last but one
my_last_but_one(X,[X,_]).
my_last_but_one(X,[_|T]) :- my_last_but_one(X,T).

% without recursion
my_last_but_one2(X,L) :- append(_,[X,_],L).

% P03, kth element
element_at(H,[H|_],1).
element_at(X,[_|T],K) :- K2 is K-1, element_at(X,T,K2).

% P04, number of element of list
count_list([],0).
count_list([_|T],N) :- count_list(T,Nnew), N is Nnew+1.

% P05, reverse a list
my_reverse([X],[X]).
my_reverse([H|T],O) :- my_reverse(T,O2), append(O2,[H],O).

% P06 palindrome
palindrome(L) :- my_reverse(L,L2), compareList(L,L2).

compareList([],[]).
compareList([H1|T1],[H2|T2]) :- compareList(T1,T2), H1 == H2.

% P07 flatten a nested list structure
my_flatten(X,[X]) :- \+ is_list(X). % first my_flatten
my_flatten([],[]).                    % second my_flatten
my_flatten([H|T],X) :- 
  my_flatten(H,X1), 
  my_flatten(T,X2), 
  append(X1,X2,X).

% P08 eleminate consecutive duplicates
compress([X],[X]).
compress([H1|T1],X) :- 
  compress(T1,[H2|T2]), 
  (H2 == H1 -> NewElement = []; NewElement = [H1]),
  append(NewElement,[H2|T2],X).



% 09 pack consecutive duplicates into sublists
pack([],[]).







