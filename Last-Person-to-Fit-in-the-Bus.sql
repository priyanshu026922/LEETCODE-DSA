1# Write your MySQL query statement below
2select person_name as person_name
3From
4(
5    select p.person_name, p.turn,
6        (
7         select sum(q.weight) 
8          from Queue q 
9          where q.turn<=p.turn 
10
11        ) as s1
12    from Queue p
13
14) t
15
16where s1<=1000
17order by turn desc
18lIMit 1