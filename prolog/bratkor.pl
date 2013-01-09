%:- use_module(library(lists)).

% Ex 3.1 a) delete last 3
delete_last_3(L,Lo) :- append(Lo,[_,_,_],L).

% b) delete first 3 and last 3
delete_3(L,Lo) :- append(L1,[_,_,_],L), append([_,_,_],Lo,L1).

% Ex 3.2 
my_last(I,O) :- append(_,[O],I).

my_last2([X],[X]).
my_last2([_|T],X) :- my_last2(T,X).

% Ex 3.3
evenlength([_,_]).
evenlength([_,_|T]) :- evenlength(T).

oddlength([_]).
oddlength([_,_|T]) :- oddlength(T).

% Ex 3.4
my_reverse([X],[X]).
my_reverse([H|T],X) :- reverse(T,Xnew), append(Xnew,[H],X).

% Ex 3.5
palindrome(L) :- my_reverse(L,L).

% Ex 3.6
shift(L1,L2) :- append([X1],X2,L1), append(X2,[X1],L2).

% Ex 3.7
means(0,zero).
means(1,one).
means(2,two).
means(3,three).
means(4,four).
means(5,five).
means(6,six).
means(7,seven).
means(8,eight).
means(9,nine).

translate(L1,L2) :- findall(Y,(member(X,L1),means(X,Y)),L2).

% Ex 3.8
subset([],[]).
subset([_|T],S) :- subset(T,S).
subset([H|T],[H|T2]) :- subset(T,T2).

% Ex. 3.9
% dividelist(L1,L2,Lo) :- 



