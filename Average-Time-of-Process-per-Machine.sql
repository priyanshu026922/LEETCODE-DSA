1# Write your MySQL query statement below
2select a1.machine_id ,round(avg(a2.timestamp-a1.timestamp),3) as processing_time
3from Activity a1
4left join Activity a2
5on a1.machine_id=a2.machine_id and a2.process_id=a1.process_id and a1.activity_type='start' and a2.activity_type='end'
6group by a1.machine_id