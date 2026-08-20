# Write your MySQL query statement below
SELECT s.score ,DENSE_RANK() over (order by s.score DESC) as `rank`
FROm scores as s
