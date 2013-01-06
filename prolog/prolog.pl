% 1, subList(L1, L2) to mean every element in list L1 is also in list L2
subList([],_).
subList([H|T],L) :- member(H,L), !, subList(T,L).

% 2, intersect (L1, L2, I) to mean I is the intersection of lists L1 and L2.
% intersect([],_,[]).
intersect(L1,L2,I) :-
  findall(X,(member(X,L2), member(X,L1)),Y), 
  setof(Z,member(Z,Y),I).

% order(IN,OUT) :- 

% counts how many times X occurs in list L, output is O
countX(X,L,O) :- findall(X, member(X,L), Y), length(Y,O).


% 3, disjoint(L1, L2) to mean L1 and L2 share no elements, and at least one 
% of them is not empty
disjoint([],_).
disjoint([H|T], L) :- \+member(H,L), disjoint(T,L).

% 4, difference(L1, L2, L) to mean L consists of all the elements in L1 that 
% are not in L2.
difference(L1,L2,L) :- findall(X,(member(X,L1), \+member(X,L2)),L).

% 5, sift(L, N, Result) to mean Result is list L but with all occurrences of 
% elements greater than N removed.
sift(L,N,R) :- findall(X, (member(X,L), X=<N), R).

% 6, um.. too long
process(L1,L2,C,I) :-
  findall((X1,Y1,Z1), (member((X1,Y1),L1), member((X1,Y1,Z1),L2)), C),
  findall((X,Y,Z), (member((X,Y,Z),L2), \+member((X,Y),L1)), I).
  /*setof((X4,Y4,Z4), (member((X3,Y3),L1), member((X4,Y4,Z4),L2),
  (X3 \= X4; Y3 \= Y4)), I).*/
    %test(L1,L2,C,I) :- findall((X,Y,Z), (member((X,Y,Z),L2), \+member((X,Y),L1)), I).

