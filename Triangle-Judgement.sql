1# Write your MySQL query statement below
2select x ,y,z,if(x+y>z and x+z>y and y+z>x,'Yes','No') as triangle
3from Triangle