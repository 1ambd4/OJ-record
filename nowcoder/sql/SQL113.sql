update examination_info
set tag = 'Python'
where tag = 'PYTHON';

update examination_info
set tag = replace(tag, 'PYTHON', 'Python');
