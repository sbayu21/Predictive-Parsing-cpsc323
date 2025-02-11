# Predictive-Parsing-cpsc323
Predictive parsing is a top-down method in compiler design.
Predictive parsing is a top-down method in compiler design that uses a parsing table to decide which production rule to apply based on the current input symbol and parser state. This approach, often associated with LL(1) parsers, eliminates the need for backtracking by utilizing a single token lookahead. The parsing table is constructed by computing the FIRST and FOLLOW sets for the grammar's non-terminals. During parsing, the parser consults this table to determine the appropriate production rule, ensuring efficient and deterministic parsing. However, the grammar must be free of left recursion and left-factored to be suitable for predictive parsing.
Method Used: Predictive Parsing Table
Language used: c++
The original program on page “1”
Part I

program s2024;
//This program computes and prints the value
of an expression//
var
// declare variables //
p1 , q2s , r, pp : integer ;
begin
p1 = 3 ;
pp= 23 ;
q2s = 4 ;
r = 5 ;
p1 = 2p1+ r( q2s + pp);
write ( p1 ); // display p1 //
//compute the value of this expression //
pp = p1 * ( q2s + 2 * rc) ;
write ( “value=”, pp ) ; //print the value of pp //
18
end.
3. The original grammar on page “2”
<prog> → program <identifier>; var <dec-list> begin <stat-list> end.
<identifier> → <letter>{<letter>|<digit>} note. This grammar is in EBNF
<dec-list> → <dec> : <type> ;
<dec> → <identifier> , <dec> | < identifier >
<type> → integer
<stat-list> → <stat> | <stat> <stat-list>
<stat> → <write> | <assign>
<write> → write( <str> < identifier > );
<str> →”value=”, | λ
<assign> → < identifier > = <expr>;
<expr> → <expr> + <term> | <expr> - <term> | <term>
<term> → <term> * <factor> | <term> / <factor>| <factor>
<factor> → < identifier > | <number> | ( <expr> )
<number> → <sign><digit>{ <digit> } note: the grammar is in EBNF
<sign> → + | - | λ
<digit> → 0|1|2|...|
<letter> → p | q | r | s
![Screenshot 2025-02-11 085333](https://github.com/user-attachments/assets/148e9216-c368-4af8-bfb8-c5ac00d1e208)
![Screenshot 2025-02-11 090222](https://github.com/user-attachments/assets/0f122da7-7451-4d88-ace5-d121fe1e2c1b)
![Screenshot 2025-02-11 085521](https://github.com/user-attachments/assets/83971035-7949-43ea-8417-3f89b9c4e5f6)
![Screenshot 2025-02-11 085554](https://github.com/user-attachments/assets/1ebaec9a-b417-4d12-9dc4-2777cc6135ea)
![Screenshot 2025-02-11 085636](https://github.com/user-attachments/assets/f46219bf-1ef1-4f24-913c-2ab4f62f177a)
![Screenshot 2025-02-11 085745](https://github.com/user-attachments/assets/f544e687-77c0-47b9-9cb0-3516cf670032)
![Screenshot 2025-02-11 085821](https://github.com/user-attachments/assets/9a0deec4-a966-45e4-92bc-b03fb4ae910f)
![Screenshot 2025-02-11 085900](https://github.com/user-attachments/assets/4a007ce1-f67e-4474-a00d-af79da6832cf)
![Screenshot 2025-02-11 085934](https://github.com/user-attachments/assets/5fc0545f-e232-44e0-9e97-63f1443719c2)
![Screenshot 2025-02-11 090010](https://github.com/user-attachments/assets/2ec3e0ee-a4da-4cb5-bf9f-6283329b2ba3)









