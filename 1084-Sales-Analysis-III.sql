select p.product_id,p.product_name
from Product p
left join Sales s
on p.product_id=s.product_id
-- and  s.sale_date between '2019-01-01' and '2019-03-31'
group by p.product_id
-- -- having (
--    select count(s.sale_date) as cnt
--    from Sales s
--    group by s.product_id
-- -- )
-- -- =cnt

having min(s.sale_date)>='2019-01-01' and max(s.sale_date)<='2019-03-31'
