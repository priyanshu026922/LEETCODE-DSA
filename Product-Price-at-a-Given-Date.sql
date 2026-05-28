1# Write your MySQL query statement below
2select p1.product_id as product_id,p1.new_price as price
3from Products p1
4where p1.change_date=(
5    select max(p2.change_date)
6    from Products p2
7    where p2.change_date<='2019-08-16' and p1.product_id=p2.product_id
8    group by p2.product_id
9) 
10
11union 
12select p1.product_id as product_id,10 as price
13from Products p1
14-- where p1.change_date>'2019-08-16' 
15group by p1.product_id
16having min(p1.change_date)>'2019-08-16' 