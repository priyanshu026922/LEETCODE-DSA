# Write your MySQL query statement below
Select s1.student_id,s1.student_name,s2.subject_name,COUNT(e1.subject_name) as attended_exams
From Students s1
CROSS Join Subjects s2
LEFT JOIN Examinations e1
on s1.student_id=e1.student_id  and e1.subject_name=s2.subject_name
group by s1.student_id,s1.student_name,s2.subject_name
order by s1.student_id ,s2.subject_name