1# Write your MySQL query statement below
2select
3round(avg(if(order_date=customer_pref_delivery_date,1,0)*100),2) as immediate_percentage
4from Delivery
5where (customer_id,order_date) IN (
6    Select customer_id,min(order_date)
7    from delivery
8    group by customer_id
9); 