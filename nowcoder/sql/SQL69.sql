select prod_name, prod_price
from Products
where prod_price between 3 and 6
order by prod_price asc;
