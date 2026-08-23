# Write your MySQL query statement below
select q.query_name,round(avg(q.rating/q.position),2) as quality,
 round(
    (count(
    case
    when q.rating<3 then 1
    end
    )
    /count(q.rating))*100
    , 2) 
 as poor_query_percentage
-- round(avg(q.rating/q.position),2) as quality,
-- round(
--   count (case
--      when q.rating<3 then 1
--      else 0
--     end )/(select count(q.quey_name) from Queries)

-- ,2)
-- as poor_query_percentage

from Queries q
group by q.query_name
