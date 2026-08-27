WITH filtered AS (
    SELECT
        id,
        visit_date,
        people
    FROM Stadium
    WHERE people >= 100
),
ranked AS (
    SELECT
        id,
        visit_date,
        people,
        id - ROW_NUMBER() OVER (
            ORDER BY id
        ) AS rn
    FROM filtered
)
,valid_groups as (
    select rn
from ranked
group by rn
having count(rn)>=3
)
SELECT id, visit_date, people
FROM ranked
WHERE rn IN ( 
    select rn from valid_groups
 );