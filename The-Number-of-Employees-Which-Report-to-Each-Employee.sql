1# Write your MySQL query statement below
2select e2.employee_id as employee_id ,e2.name as name,count(e1.employee_id) as reports_count,round( avg(e1.age) )as average_age
3from Employees e1
4 join Employees e2
5on e1.reports_to=e2.employee_id
6where e2.employee_id is not NULL
7group by e2.employee_id,e2.name
8order by e2.employee_id
9