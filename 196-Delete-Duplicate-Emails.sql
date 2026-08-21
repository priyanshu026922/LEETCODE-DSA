# Write your MySQL query statement below
-- select DISTINCT (p.email),p.id
-- from Person p
DELETE p1
FROM person p1
JOIN person p2
on p1.email=p2.email
and p1.id>p2.id