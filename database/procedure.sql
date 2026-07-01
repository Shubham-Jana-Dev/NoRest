show DATABASEs;
use My_practice;
show tables;
select* from student;
delimiter //
select* from student;
Create Procedure Insertinfo3(in s_id int, in roll int,in Sname VARCHAR(100) )
begin
   
        insert into student (student_id, roll, student_name) values(s_id, roll, Sname);

end//
delimiter ;
call insertinfo3(23, 45, 'Shubham Jana' );
desc student;

Create Procedure Insertinfo7(in n varchar(100),in e int)
begin
   update student set student_name = n where student_id = e; 
end//
delimiter ;
call insertinfo7('eeee',1);
alter Table student add department VARCHAR(200);
update student set department = 'EEE' where student_id = 4;
Create Procedure I7(in dep varchar(200))
begin
   select* from student where department = dep;
end//
call I7('CSE');
alter Table student add Marks int;
update student set Marks = 2330 where student_id = 4;
Create Procedure I473(in id int)
begin
   update student set marks = marks + (marks*(10/100)) where student_id = id ;
end//
call i473();

drop procedure I2239;
Create Procedure I2239(in b decimal(32,2), out abc decimal(32,2))
begin
   select  abc=b*12;

end//
call I2239(2330,@a);
select @abc;

alter table student add total_marks int;

Create Procedure I9891(in b bigint,out a bigint)
begin
select b*12 into a;
end//
call I9891(20,@a);
select @a;

